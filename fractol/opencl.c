/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:37:15 by bturcott          #+#    #+#             */
/*   Updated: 2019/03/11 20:46:12 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	create_device_n_context(t_dev *cl)
{
	int error;

	if ((error = clGetPlatformIDs(1, &cl->platform, NULL)) < 0)
		exit(1);
	if ((error = clGetDeviceIDs(cl->platform, CL_DEVICE_TYPE_GPU, 1, \
					&cl->device, NULL)) < 0)
		exit(1);
	cl->context = clCreateContext(NULL, 1, &cl->device, NULL, NULL, &error);
	if (error < 0)
		exit(1);
}

void	build_program(t_dev *cl, char *program)
{
	char	*buff;
	size_t	prog_size;
	cl_int	err;
	FILE	*fd;

	fd = fopen(program, "r");
	fseek(fd, 0, SEEK_END);
	prog_size = ftell(fd);
	buff = (char *)malloc(sizeof(char) * (prog_size + 1));
	buff[prog_size] = '\0';
	rewind(fd);
	fread(buff, sizeof(char), prog_size, fd);
	fclose(fd);
	cl->program = clCreateProgramWithSource(cl->context, 1, \
			(const char **)&buff, (const size_t *)&prog_size, &err);
	if (err < 0)
		exit(1);
	free(buff);
	err = 0;
	if ((err = clBuildProgram(cl->program, 1, \
					&cl->device, NULL, NULL, NULL)) < 0)
		exit(1);
}

void	switch_fract(double *vars, t_fract *m)
{
	vars[0] = m->e->min_im;
	vars[1] = m->e->min_re;
	vars[2] = m->e->scale;
	vars[5] = (double)m->e->iter;
	vars[6] = (double)m->e->color;
	if (m->f == 'j')
	{
		vars[3] = m->e->c_x;
		vars[4] = m->e->c_y;
	}
}

void	calculate_opencl(t_fract *m, t_dev *cl)
{
	double	var[8];
	size_t	gws;

	gws = WINDOW_X * WINDOW_Y * sizeof(int);
	switch_fract(var, m);
	cl->err = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), (void *)&cl->buff);
	if (cl->err < 0)
		exit(1);
	cl->err = clSetKernelArg(cl->kernel, 1, sizeof(double) * 8, (void *)&var);
	if (cl->err < 0)
		exit(1);
	cl->err = clEnqueueNDRangeKernel(cl->queue, cl->kernel, 1, NULL, &gws, \
			NULL, 0, NULL, NULL);
	if (cl->err < 0)
		exit(1);
	cl->err = clEnqueueReadBuffer(cl->queue, cl->buff, CL_TRUE, 0, gws, \
			m->array, 0, NULL, NULL);
}

void	prepare_opencl(t_fract *m, t_dev *cl)
{
	cl->queue = clCreateCommandQueue(cl->context, cl->device, 0, &cl->err);
	if (cl->err < 0)
		exit(1);
	cl->buff = clCreateBuffer(cl->context, \
			CL_MEM_READ_WRITE, WINDOW_X * WINDOW_Y \
			* sizeof(int), NULL, &cl->err);
	if (cl->err < 0)
		exit(1);
	cl->err = clEnqueueWriteBuffer(cl->queue, cl->buff, CL_TRUE, 0, WINDOW_X * \
			WINDOW_Y * sizeof(int), m->array, 0, NULL, NULL);
	if (cl->err < 0)
		exit(1);
	cl->kernel = clCreateKernel(cl->program, \
			(m->f == 'j') ? "julia" : "mandelbrot", &cl->err);
	if (cl->err < 0)
		exit(1);
	calculate_opencl(m, cl);
}

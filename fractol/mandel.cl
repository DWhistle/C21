__kernel void mandelbrot(__global int *array, double8 z)
{
    double pow_x;
    double pow_y;
    double z_x;
    double z_y;
    double c_x;
    double c_y;
    int a;
    int iter;
    int x;
    int y;


    z_x = 0.0;
    z_y = 0.0;
    iter = 0;
    a = get_global_id(0);
    x = a % 2048;
    y = (a - x) / 2048;
    c_y = (double)y / z[2] + z[0];
    c_x = (double)x / z[2] + z[1];
    while (z_x * z_x + z_y * z_y < 4 && iter < z[5])
        {
            pow_x = z_x * z_x;
            pow_y = z_y * z_y;
            z_y = z_y * z_x * 2 + c_y;
            z_x = pow_x - pow_y + c_x;
            iter++;
        }
        array[a] = z[6] * iter;
}
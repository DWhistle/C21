__kernel void julia(__global int *array, double8 z)
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

    iter = 0;
    a = get_global_id(0);
    c_y = z[4];
    c_x = z[3];
    x = a % 2048;
    y = (a - x) / 2048;
    z_y = (double)y / z[2] + z[0];
    z_x = (double)x / z[2] + z[1];
    while (z_x * z_x + z_y * z_y < 4 && iter < z[5])
        {
            pow_x = z_x * z_x;
            pow_y = z_y * z_y;
            z_y = z_y * z_x * 2 + c_y;
            z_x = pow_x - pow_y + c_x;
            iter++;
        }
        if (iter < (int)z[5])
            array[a] = z[6] * iter * 10;
        else
            array[a] = 0x000000;
}

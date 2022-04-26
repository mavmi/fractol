#include "../include/fractol.h"

// f(z) = z^2 + const
// May return NULL
static t_complex	*fractal_func(t_complex *num, t_complex *constant)
{
	t_complex	*power_2;
	t_complex	*sum;

	power_2 = complex_power_2(num);
	if (!power_2)
	{
		return (NULL);
	}
	sum = complex_sum(power_2, constant);
	free(power_2);
	return (sum);
}

// Iterate fractal func ITERS times
// Return count of iterations
// or -1 if error occurred
static int	is_in_set(t_complex *number, t_complex *constant)
{
	int			iters;
	t_complex	*temp;

	if (!constant || !number)
		return (-1);
	iters = 0;
	while (iters++ < ITERS)
	{
		temp = fractal_func(number, constant);
		free(number);
		if (!temp)
		{
			free(constant);
			return (-1);
		}
		number = temp;
		if (number->value > 2)
			break ;
	}
	free(number);
	free(constant);
	return (iters);
}

// Draw (x, y) point in data->img
static void	draw_point(int x, int y, t_vars *vars, t_data *data)
{
	int			pos;
	int			iters;
	t_complex	*z;
	t_complex	*c;

	z = init_complex((-2.0 + (4.0 / WIDTH)
				* (x + data->horiz * data->scale)) / data->scale,
			(-2.0 + (4.0 / HEIGHT)
				* (y + data->vert * data->scale)) / data->scale);
	c = init_complex(data->x, data->y);
	if (data->fract_code == JUL_CODE)
		iters = is_in_set(z, c);
	else
		iters = is_in_set(c, z);
	if (iters == -1)
	{
		free(z);
		free(c);
		clean_and_exit(1, data);
	}
	pos = y * vars->size_line + x * (vars->bits_per_pixel / 8);
	if (iters >= ITERS)
		*(int *)(data->img_addr + pos) = 0x000000;
	else
		*(int *)(data->img_addr + pos) = (iters % 32 + 64) << 12;
}

void	draw_fractal(t_data *data)
{
	double	x;
	double	y;
	t_vars	vars;

	data->img_addr = mlx_get_data_addr(data->img, &vars.bits_per_pixel,
			&vars.size_line, &vars.endian);
	if (!data->img_addr)
	{
		clean_and_exit(1, data);
	}
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			draw_point(x, y, &vars, data);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

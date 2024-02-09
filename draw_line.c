/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:43:43 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 09:17:48 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static float	get_abs(float num)
{
	if (num < 0)
		num = -num;
	return (num);
}

static float	get_max(float num1, float num2)
{
	if (num1 >= num2)
		return (num1);
	else
		return (num2);
}

void	custom_mlx_pixel_put(t_fdf *data, int x1, int y1, int color)
{
	char	*dst;

	if (x1 >= 0 && x1 < 1920 && y1 >= 0 && y1 < 1080)
	{
		dst = data->img_data + (y1 * data->line_length + \
				x1 * (data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	draw_line(t_fdf *data)
{
	float	x_incr;
	float	y_incr;
	int		max_abs_incr;
	int z1;
	int z2;

	z1 = data->z_mtx[(int)data->param_y][(int)data->param_x]; //access value in matrix by row then column
	z2 = data->z_mtx[(int)data->param_y1][(int)data->param_x1]; //rename params to x1, x2, y1, y2


	zoom(data);
	color(data, z1, z2, data->color_flag);
	isometric(data, z1, z2);
	shift(data);


	x_incr = data->param_x1 - data->param_x;
	y_incr = data->param_y1 - data->param_y;
	max_abs_incr = get_max(get_abs(x_incr), get_abs(y_incr));
	x_incr = x_incr / max_abs_incr;
	y_incr = y_incr / max_abs_incr;
	while((int)(data->param_y - data->param_y1) || (int)(data->param_x - data->param_x1))
	{
		custom_mlx_pixel_put(data, data->param_x, data->param_y, data->color); //understand it!
		data->param_x += x_incr;
		data->param_y += y_incr;
	}
}

void	draw_map(t_fdf *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while(i < data->width)
		{
			if (i < data->width - 1)
			{
				set_coords(data, i, j, 0);
				draw_line(data); //draw line to the right
			}
			if (j < data->height - 1)
			{
				set_coords(data, i, j, 1);
				draw_line(data); //draw line downwards
			}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

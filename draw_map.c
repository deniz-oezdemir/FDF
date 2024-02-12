/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:43:43 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/12 13:30:26 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_max_abs(float x, float y)
{
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	if (x >= y)
		return (x);
	else
		return (y);
}

/* Validate if the coordinates are within the image boundaries.
Calculate the memory address corresponding to the pixel at the given coordinates.
Set the color value of the pixel at this memory address. */
void	custom_mlx_pixel_put(t_fdf *data, int x1, int y1, int clr)
{
	char	*dst;

	if (x1 >= 0 && x1 < W_W && y1 >= 0 && y1 < W_H)
	{
		dst = data->img_data + (y1 * data->line_len + x1 * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = clr;
	}
}

/* Bresenham's line algorithm */
void	draw_line(t_fdf *data)
{
	float	x_incr;
	float	y_incr;
	int		max_abs_incr;
	int		z1;
	int		z2;

	z1 = data->z_mtx[(int)data->y1][(int)data->x1] * data->scale;
	z2 = data->z_mtx[(int)data->y2][(int)data->x2] * data->scale;
	zoom(data);
	clr(data, z1, z2);
	isometric(data, z1, z2);
	translate(data);
	x_incr = data->x2 - data->x1;
	y_incr = data->y2 - data->y1;
	max_abs_incr = get_max_abs(x_incr, y_incr);
	x_incr = x_incr / max_abs_incr;
	y_incr = y_incr / max_abs_incr;
	while ((int)(data->y1 - data->y2) || (int)(data->x1 - data->x2))
	{
		custom_mlx_pixel_put(data, data->x1, data->y1, data->clr);
		data->x1 += x_incr;
		data->y1 += y_incr;
	}
}

void	set_coords(t_fdf *data, int i, int j, int flg)
{
	data->x1 = i;
	data->y1 = j;
	if (!flg)
	{
		data->y2 = j;
		data->x2 = i + 1;
	}
	else
	{
		data->y2 = j + 1;
		data->x2 = i;
	}
}

/* For every point: first draw line to the right, then draw line downwards */
void	draw_map(t_fdf *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			if (i < data->width - 1)
			{
				set_coords(data, i, j, 0);
				draw_line(data);
			}
			if (j < data->height - 1)
			{
				set_coords(data, i, j, 1);
				draw_line(data);
			}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:43:43 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/05 15:46:53 by denizozd         ###   ########.fr       */
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

/*	Bresenham's line algorithm	*/
void	draw_line(float x1, float y1, float x2, float y2, fdf *dat)
{
	float	x_incr;
	float	y_incr;
	int		max_abs_incr;

	x_incr = x2 - x1;
	y_incr = y2 - y1;
	max_abs_incr = get_max(get_abs(x_incr), get_abs(y_incr));
	x_incr = x_incr / max_abs_incr;
	y_incr = y_incr / max_abs_incr;
	while((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(dat->mlx_ptr, dat->win_ptr, x1, y1, 0x00FF00);
		x1 = x1 + x_incr;
		y1 = y1 + y_incr;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:45:32 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/12 11:45:01 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *data, int z1, int z2)
{
	data->x1 = (data->x1 - data->y1) * cos(data->dgr);
	data->x2 = (data->x2 - data->y2) * cos(data->dgr);
	data->y1 = (data->x1 + data->y1) * sin(data->dgr) - z1;
	data->y2 = (data->x2 + data->y2) * sin(data->dgr) - z2;
}

void	zoom(t_fdf *data)
{
	data->x1 = data->x1 * data->zoom;
	data->x2 = data->x2 * data->zoom;
	data->y1 = data->y1 * data->zoom;
	data->y2 = data->y2 * data->zoom;
}

void	translate(t_fdf *data)
{
	data->x1 += data->d_x;
	data->x2 += data->d_x;
	data->y1 += data->d_y;
	data->y2 += data->d_y;
}

void	clr(t_fdf *data, int z1, int z2)
{
	if (!(z2 || z1) && data->clr_flg == 1)
		data->clr = 0x12cc00;
	if ((z2 || z1) && data->clr_flg == 1)
		data->clr = 0xc02e2e;
	if (!(z2 || z1) && data->clr_flg == 2)
		data->clr = 0x2000ff;
	if ((z2 || z1) && data->clr_flg == 2)
		data->clr = 0xdfff00;
	if (!(z2 || z1) && data->clr_flg == 3)
		data->clr = 0x3fd1d1;
	if ((z2 || z1) && data->clr_flg == 3)
		data->clr = 0xed33ff;
}

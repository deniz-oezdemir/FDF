/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:45:32 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 10:46:34 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *data, int z, int z1) // vars
{
	data->param_x = (data->param_x - data->param_y) * cos(data->degree);
	data->param_y = (data->param_x + data->param_y) * sin(data->degree) - z;
	data->param_x1 = (data->param_x1 - data->param_y1) * cos(data->degree);
	data->param_y1 = (data->param_x1 + data->param_y1) * sin(data->degree) - z1;
}

void	zoom(t_fdf *data) // vars
{
	data->param_x = data->param_x * data->zoom;
	data->param_y = data->param_y * data->zoom;
	data->param_x1 = data->param_x1 * data->zoom;
	data->param_y1 = data->param_y1 * data->zoom;
}

void	shift(t_fdf *data) // vars
{
	data->param_x += data->shift_x;
	data->param_y += data->shift_y;
	data->param_x1 += data->shift_x;
	data->param_y1 += data->shift_y;
}

void	color(t_fdf *data, int z1, int z2, int flag)
{
	if (!(z2 || z1) && flag == 1)
		data->color = 0x12cc00;
	if ((z2 || z1) && flag == 1)
		data->color = 0xed33ff;
	if (!(z2 || z1) && flag == 2)
		data->color = 0x2000ff;
	if ((z2 || z1) && flag == 2)
		data->color = 0xdfff00;
	if (!(z2 || z1) && flag == 3)
		data->color = 0x3fd1d1;
	if ((z2 || z1) && flag == 3)
		data->color = 0xc02e2e;
}

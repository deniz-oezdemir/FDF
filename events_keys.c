/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:12:57 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/12 12:45:05 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_translate(int key, t_fdf *data)
{
	if (key == KEY_W)
		data->d_y -= 15;
	else if (key == KEY_S)
		data->d_y += 15;
	else if (key == KEY_A)
		data->d_x -= 15;
	else if (key == KEY_D)
		data->d_x += 15;
}

void	key_dgr(int key, t_fdf *data)
{
	if (key == KEY_Q)
		data->dgr += 0.1;
	else if (key == KEY_E)
		data->dgr -= 0.1;
}

void	key_clr(int key, t_fdf *data)
{
	if (key == KEY_P && data->clr_flg < 3)
		data->clr_flg += 1;
	else
		data->clr_flg = 1;
}

void	key_zoom(int key, t_fdf *data)
{
	if (key == KEY_Z)
		data->zoom += 2;
	else if (key == KEY_X)
		data->zoom -= 2;
}

void	key_scale(int key, t_fdf *data)
{
	if (key == KEY_K)
		data->scale += 1;
	else if (key == KEY_L)
		if (data->scale > 1)
			data->scale -= 1;
}

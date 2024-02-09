/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:12:57 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 10:46:37 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

/*	rewrite all of this	*/

void	key_shift(int key, t_fdf *data)
{
	if (key == KEY_S)
		data->shift_y += 10;
	else if (key == KEY_W)
		data->shift_y -= 10;
	else if (key == KEY_D)
		data->shift_x += 10;
	else if (key == KEY_A)
		data->shift_x -= 10;
}

void	key_degree(int key, t_fdf *data)
{
	if (key == KEY_Q)
		data->degree += 0.1;
	else if (key == KEY_E)
		data->degree -= 0.1;
}

void	key_color(int key, t_fdf *data) //make random inverted colors instead
{
	if (key == KEY_P)
		data->color_flag = 1;
	else if (key == KEY_O)
		data->color_flag = 2;
	else if (key == KEY_I)
		data->color_flag = 3;
}

void	key_zoom(int key, t_fdf *data)
{
	if (key == KEY_Z)
		data->zoom += 1;
	else if (key == KEY_X)
		data->zoom -= 1;
}

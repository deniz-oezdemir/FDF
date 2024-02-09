/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:57:13 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 09:57:48 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mouse_handler(t_fdf *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 17, close_frame, data);
}

void	handle_event(t_fdf *data) //rewrite differently
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_map(data);
}

int	keyboard_handler(int key, t_fdf *data) //rewrite differently, different order
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		key_shift(key, data);
	else if (key == KEY_Q || key == KEY_E)
		key_degree(key, data);
	else if (key == KEY_P || key == KEY_O || key == KEY_I)
		key_color(key, data);
	else if (key == KEY_R)
		init_vars(data);
	else if (key == KEY_Z || key == KEY_X)
		key_zoom(key, data);
	else if (key == KEY_ESC)
	{
		//free_data(data); // check with valgrind
		exit(0);
	}
	handle_event(data);
	return (0);
}

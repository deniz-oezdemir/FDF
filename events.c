/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:57:13 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/08 20:27:01 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void	mouse_handler(t_fdf *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 17, close_frame, data);
	mlx_hook(data->win_ptr, 4, 1L << 11, mouse_release, data);
	mlx_hook(data->win_ptr, 5, 1L << 12, mouse_release, data);
}
*/

void	handle_event(t_fdf *data) //rewrite differently
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	draw_map(data);
}

int	keyboard_handler(int key, t_fdf *data) //rewrite differently
{
	if (key == 65363) // KEY_RIGHT -> make extra header file with all keys
		data->shift_y += 10;
	else if (key == 1 || key == 0 || key == 2 || key == 13)
		key_shift(key, data);
	else if (key == 124 || key == 123)
		key_degree(key, data);
	else if (key == 8 || key == 9 || key == 17)
		key_color(key, data);
	else if (key == 15)
		init_vars(data);
	else if (key == 53)
	{
		//free_data(data);
		exit(0);
	}
	handle_event(data);
	return (0);
}

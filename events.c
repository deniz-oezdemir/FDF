/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:57:13 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 18:51:01 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_mouse(t_fdf *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 17, close_win, data);
}

int	handle_keys(int key, t_fdf *data)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		key_translate(key, data);
	else if (key == KEY_Z || key == KEY_X)
		key_zoom(key, data);
	else if (key == KEY_P)
		key_clr(key, data);
	else if (key == KEY_Q || key == KEY_E)
		key_dgr(key, data);
	else if (key == KEY_R)
		init_vars(data);
	else if (key == KEY_ESC)
	{
		free_data(data);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, W_W, W_H);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_len, &data->endian);
	draw_map(data);
	return (0);
}

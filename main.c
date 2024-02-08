/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:14 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/08 20:08:32 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2 || !av[1])
		perror("Error: unexpected input");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	get_map(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FDF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	init_vars(data);
	draw_map(data);
	/*mouse_handler(data);*/
	mlx_key_hook(data->win_ptr, keyboard_handler, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

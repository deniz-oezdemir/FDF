/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:14 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/11 10:01:08 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2 || !av[1])
		error_input();
	data = (t_fdf *)malloc(sizeof(t_fdf));
	init_vars(data);
	file_to_list(av[1], data);

//	get_map(av[1], data);

	/*	print matrix containing map (test to be deleted)
	int i;
	int j;
	i = 0;
	while(i < data->height)
	{
		j = 0;
		while(j < data->width)
		{
			ft_printf("%d", data->z_mtx[i][j]);
			ft_printf("\t");
			j++;
		}
		ft_printf("\n");
		i++;
	}
*/

/*
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_W, W_H, "FDF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, W_W, W_H);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_len, &data->endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	init_vars(data);
	draw_map(data);
	handle_mouse(data);
	mlx_key_hook(data->win_ptr, handle_keys, data);
	mlx_loop(data->mlx_ptr);
*/
	return (0);
}

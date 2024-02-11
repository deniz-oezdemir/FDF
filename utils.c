/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:57:13 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/11 11:29:21 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_fdf *data)
{
	data->d_x = W_W / 3;
	data->d_y = W_H / 3;
	data->zoom = 40;
	data->dgr = 0.8;
	data->clr = 0xf2f2f2;
	data->clr_flg = 0;
	data->y1 = 0;
	data->x1 = 0;
	data->x2 = 0;
	data->y2 = 0;
	data->list = NULL; //initialize also the other ptrs to NULL
}

void	error_input(void)
{
	ft_printf("Error: Invalid input\n");
	exit(1);
}

void	error_file(t_fdf *data, int fd)
{
	perror("Error");
	close(fd);
	free(data);
	exit(1);
}

void	free_data(t_fdf *data)
{
	int	i;

	ft_lstclear(&(data->list), &free);
	i = 0;
	while (i < data->height)
		free(data->z_mtx[i++]);
	free(data->z_mtx);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
}

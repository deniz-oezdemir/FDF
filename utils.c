/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:57:13 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/12 15:04:28 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_fdf *data, int flg)
{
	if (!flg)
	{
		data->mlx_ptr = NULL;
		data->win_ptr = NULL;
		data->img_ptr = NULL;
		data->img_data = NULL;
	}
	data->d_x = W_W / 3;
	data->d_y = W_H / 3;
	data->scale = 1;
	data->zoom = 40;
	data->dgr = 0.8;
	data->clr = 0xf2f2f2;
	data->clr_flg = 0;
	data->y1 = 0;
	data->x1 = 0;
	data->x2 = 0;
	data->y2 = 0;
}

void	error_input(void)
{
	ft_printf("Error: Invalid input\n");
	exit(1);
}

void	error_file(t_fdf *data, int fd, int flg)
{
	if (!flg)
		perror("Error");
	else
		ft_printf("Error: Invalid map\n");
	close(fd);
	free(data);
	exit(0);
}

void	free_data(t_fdf *data)
{
	int	i;

	ft_lstclear(&(data->z_list), &free);
	i = 0;
	while (i < data->height)
		free(data->z_mtx[i++]);
	free(data->z_mtx);
	if (data->img_ptr != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr != NULL)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr != NULL)
		free(data->mlx_ptr);
	free(data);
}

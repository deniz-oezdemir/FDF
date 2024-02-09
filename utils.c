/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:57:13 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 13:37:42 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_fdf *data) //rename all vars and initialize to other values (also window size)
{
	data->shift_x = 600;
	data->shift_y = 400;
	data->zoom = 30;
	data->degree = 0.8;
	data->color = 0xf2f2f2;
	data->param_y = 0;
	data->param_x = 0;
	data->param_x1 = 0;
	data->param_y1 = 0;
	data->color_flag = 0;
}

void	set_coords(t_fdf *data, int i, int j, int f)
{
	data->param_x = i;
	data->param_y = j;
	if (!f)
	{
		data->param_y1 = j;
		data->param_x1 = i + 1;
	}
	else
	{
		data->param_y1 = j + 1;
		data->param_x1 = i;
	}
}

void	error_input() // arguments
{
	ft_printf("Error: Invalid input\n");
	exit(1);
}

void	error_file(t_fdf *data, int fd) //update arguments everywhere else !
{
	perror("Error");
	close(fd);
	free(data);
	exit(1);
}

void	free_data(t_fdf *data) // where used? !
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->z_mtx[i++]);
	}
	free(data->z_mtx);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
}



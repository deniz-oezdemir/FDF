/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:57:13 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 11:31:41 by denizozd         ###   ########.fr       */
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
	data->color_flag = 1;
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

void	error_file()
{
	perror("Error");
	exit(1);
}



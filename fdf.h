/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:10 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/08 13:57:53 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>


typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct s_map
{
	int		height;
	int		width;
	int		**mtx;
	int		coordinate_y;
	int		coordinate_z;
	int		y0;
	int		y1;
	int		z0;
	int		z1;
	int		zoom;
	int		isometric;
	double	x_value;
	double	angle_y;
	double	angle_z;
}	t_map;

typedef struct s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_img;

typedef struct
{
	int		red;
	int		green;
	int		blue;
}	t_col;

typedef struct s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_img	img;
	t_col	col;
}	t_fdf;


void	get_map(char *file, t_fdf *fdf);

#endif

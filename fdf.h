/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:10 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 11:24:45 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "keys.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

//rename vars better
typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_mtx;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

/*	vars	*/
	int		shift_x; //shifts maybe not needed
	int		shift_y;
	float	zoom;
	double	degree;
	int		color;
	float	param_x; //params maybe not needed
	float	param_y;
	float	param_x1;
	float	param_y1;
	int		color_flag;
}			t_fdf;


void	get_map(char *file, t_fdf *fdf);
void	init_vars(t_fdf *data);
void	draw_map(t_fdf *data);

void	init_vars(t_fdf *data);
void	set_coords(t_fdf *data, int i, int j, int f);

void	isometric(t_fdf *data, int z, int z1);
void	zoom(t_fdf *data) ;
void	shift(t_fdf *data);
void	color(t_fdf *data, int z1, int z2, int f);

void	mouse_handler(t_fdf *data);
int		keyboard_handler(int key, t_fdf *data);
void	handle_event(t_fdf *data) ;

void	key_shift(int key, t_fdf *data);
void	key_degree(int key, t_fdf *data);
void	key_color(int key, t_fdf *data);

void	key_zoom(int key, t_fdf *data);
int		mouse_release(int key, int x, int y, t_fdf *data);
int		close_frame(t_fdf *data);

void	error_input();
void	error_file();

#endif

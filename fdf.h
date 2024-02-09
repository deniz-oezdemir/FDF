/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:10 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 16:23:33 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

/*reorder*/
# define KEY_Z		122
# define KEY_X		120
# define KEY_P		112
# define KEY_I		105
# define KEY_O		111
# define KEY_R		114
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_Q		113
# define KEY_W		119
# define KEY_E		101
# define KEY_ESC    65307

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

/*	get_map.c	*/
void	get_map(char *file, t_fdf *fdf);
int		get_rows(char *file);
int		get_clms(char *file);
void	fill_row(int *z_row, char *line);

/*	draw_map.c	*/
void	draw_map(t_fdf *data);
void	draw_line(t_fdf *data);
void	custom_mlx_pixel_put(t_fdf *data, int x1, int y1, int color);

/*	calculations.c	*/
void	isometric(t_fdf *data, int z, int z1);
void	zoom(t_fdf *data) ;
void	shift(t_fdf *data);
void	color(t_fdf *data, int z1, int z2);

/*	events.c	*/
void	mouse_handler(t_fdf *data);
int		keyboard_handler(int key, t_fdf *data);
void	handle_event(t_fdf *data);

/* events_keys.c	*/
void	key_shift(int key, t_fdf *data);
void	key_degree(int key, t_fdf *data);
void	key_color(int key, t_fdf *data);
void	key_zoom(int key, t_fdf *data);

/* event_mouse.c	*/
int		close_frame(t_fdf *data);

/*	utils.c	*/
void	init_vars(t_fdf *data);
void	set_coords(t_fdf *data, int i, int j, int f);
void	error_input();
void	error_file();
void	free_data(t_fdf *data);

#endif

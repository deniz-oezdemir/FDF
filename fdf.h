/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:10 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/12 15:03:46 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

/*	keys	*/
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_Z		122
# define KEY_X		120
# define KEY_P		112
# define KEY_Q		113
# define KEY_E		101
# define KEY_K		107
# define KEY_L		108
# define KEY_R		114
# define KEY_ESC	65307

/*	window resolution	*/
# define W_W		1600
# define W_H		900

/*	struct	*/
typedef struct s_fdf
{
	int		width;
	int		height;
	t_list	*z_list;
	int		**z_mtx;
	int		d_x;
	int		d_y;
	float	scale;
	float	zoom;
	double	dgr;
	int		clr;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	int		clr_flg;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_fdf;

/*	get_map.c	*/
void	file_to_list(char *file, t_fdf *data);
void	get_width(t_fdf *data);
void	list_to_matrix(t_fdf *data);
void	fill_row(int *z_mtx_row, char *z_str);

/*	draw_map.c	*/
void	draw_map(t_fdf *data);
void	set_coords(t_fdf *data, int i, int j, int flg);
void	draw_line(t_fdf *data);
void	custom_mlx_pixel_put(t_fdf *data, int x1, int y1, int clr);

/*	calculations.c	*/
void	isometric(t_fdf *data, int z, int z1);
void	zoom(t_fdf *data);
void	translate(t_fdf *data);
void	clr(t_fdf *data, int z1, int z2);

/*	events.c	*/
void	handle_mouse(t_fdf *data);
int		handle_keys(int key, t_fdf *data);

/*	events_keys.c	*/
void	key_translate(int key, t_fdf *data);
void	key_dgr(int key, t_fdf *data);
void	key_clr(int key, t_fdf *data);
void	key_zoom(int key, t_fdf *data);
void	key_scale(int key, t_fdf *data);

/*	event_mouse.c	*/
int		close_win(t_fdf *data);

/*	utils.c	*/
void	init_vars(t_fdf *data, int flg);
void	error_input(void);
void	error_file(t_fdf *data, int fd, int flg);
void	free_data(t_fdf *data);

#endif

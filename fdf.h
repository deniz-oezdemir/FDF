/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:10 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/05 18:08:02 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct
{
	int	x;
	int	y;
	int	**mtx;
	int	zoom;
	int	clr;

	void	*mlx_ptr; //rename better: mlx_init
	void	*win_ptr; //rename better: mlx_win
}		fdf;

void	read_map(char *file, fdf *dat);
void	draw_line(float x1, float y1, float x2, float y2, fdf *dat);
void	draw_map(fdf *dat);

#endif

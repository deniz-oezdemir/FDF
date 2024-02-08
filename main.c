/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:14 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/08 11:00:50 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	game plan
1. read map and store in 2-dimensional array (gnl, atoi)	done
2. function to draw a line (bresenham algo)					done
3. function to draw all lines (downwards and right)			done
4. add 3D
5. add bonuses
6. error handling (ac == 2, open file)
7. mem leaks	*/

#include "fdf.h"

int	deal_key(int key, fdf *dat)
{
	ft_printf("%d\n", key);
	if (key == 65263)
		dat->mv_x += 10;
	if (key == 65261)
		dat->mv_x -= 10;
	if (key == 65262)
		dat->mv_y += 10;
	if (key == 65264)
		dat->mv_y -= 10;
	mlx_clear_window(dat->mlx_ptr, dat->win_ptr);
	draw_map(dat);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;

	fdf	*dat;

	dat = (fdf *)malloc(sizeof(fdf));
	read_map(av[1], dat);

/*	print matrix containing map	(test to be deleted)
	int i;
	int j;
	i = 0;
	while(i < dat->y)
	{
		j = 0;
		while(j < dat->x)
		{
			ft_printf("%d", dat->mtx[i][j]);
			ft_printf("\t");
			j++;
		}
		ft_printf("\n");
		i++;
	}
*/

	/*	draw a line*/
	dat->mlx_ptr = mlx_init();
	dat->win_ptr = mlx_new_window(dat->mlx_ptr, 1000, 1000, "FDF");
	dat->zoom = 20;

/*	one line (test to be deleted)
	draw_line(10, 10, 600, 300, dat);
*/

	draw_map(dat);
	mlx_key_hook(dat->win_ptr, deal_key, dat); //does not work
	mlx_loop(dat->mlx_ptr);

	return(0);
}

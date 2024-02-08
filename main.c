/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:14 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/08 15:15:04 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx.init, fdf->mlx.win);
	exit(0);
}

int main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		perror("malloc fail");
	if (ac != 2)
		perror("unexpected input");
	get_map(av[1], fdf);
	reset_map(fdf); //init? TO DO: only what needed
	fdf->mlx.init = mlx_init(); //initialize display
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, 1000, 1000, "FDF");
	mlx_hook(fdf->mlx.win, 17, 0, close_win, fdf);
	//mlx_hook(fdf->mlx.win, 2, 3, keys, fdf); //To DO: keys
	//mlx_loop_hook(fdf->mlx.init, draw, fdf); //To DO: draw
	mlx_loop(fdf->mlx.init);
	free(fdf);
	return (0);

/*	print matrix containing map	(test to be deleted)
	int i;
	int j;
	i = 0;
	while(i < fdf->map.height)
	{
		j = 0;
		while(j < fdf->map.width)
		{
			ft_printf("%d", fdf->map.mtx[i][j]);
			ft_printf("\t");
			j++;
		}
		ft_printf("\n");
		i++;
	}
*/

}
/*	OLD: game plan
1. read map and store in 2-dimensional array (gnl, atoi)	done
2. function to draw a line (bresenham algo)					done
3. function to draw all lines (downwards and right)			done
4. add 3D
5. add bonuses
6. error handling (ac == 2, open file)
7. mem leaks	*/

/* OLD
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

	dat->mlx_ptr = mlx_init();
	dat->win_ptr = mlx_new_window(dat->mlx_ptr, 1000, 1000, "FDF");
	dat->zoom = 20;


	draw_map(dat);
	mlx_key_hook(dat->win_ptr, deal_key, dat); //does not work
	mlx_loop(dat->mlx_ptr);

	return(0);
}
*/

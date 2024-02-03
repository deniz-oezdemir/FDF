/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:14 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/03 10:10:53 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	game plan
1. read map and store in 2-dimensional array (gnl, atoi)
2. function to draw a line (bresenham algo)
3. function to draw all lines
4. add 3D
5. add bonuses
6. error handling (ac == 2, open file)
7. mem leaks	*/

#include "fdf.h"

int	main(int ac, char **av)
{
	fdf	*dat;

	dat = (fdf *)malloc(sizeof(fdf));
	read_map(av[1], dat);

	int i;
	int j;

	i = 0;
	while(i < dat->y)
	{
		j = 0;
		while(j < dat->x)
		{
			ft_printf("%3d", dat->mtx[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return(0);
}

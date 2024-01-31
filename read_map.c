/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/01/31 22:15:29 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_y(char *file)
{
	// get # lines with gnl
}

int	get_x(char *file)
{
	// get # lines with gnl and wordcount from split
}

void	read_map(char *file, fdf *dat)
{
	dat->y = get_y(file);
	dat->x = get_x(file);
}

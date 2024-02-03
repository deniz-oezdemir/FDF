/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/03 12:30:18 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rows(char *file)
{
	int		fd;
	char	*line;
	int		rows;

	rows = 0;
	fd = open(file, O_RDONLY, 0);
	while (line = get_next_line(fd))
	{
		rows++;
		free(line);
	}
	close(fd);
	return (rows);
}

int	get_clms(char *file)
{
	int		fd;
	char	*line;
	int		clms;

	fd = open(file, O_RDONLY, 0);
	
	line = get_next_line(fd);
	clms = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (clms);
}

void	fill_row(int *mtx, char *line)
{
	char **alts; //altitudes
	int i;

	alts = ft_split(line, ' ');
	i = 0;
	while(alts[i])
	{
		mtx[i] = ft_atoi(alts[i]);
		free(alts[i]);
		i++;
	}
	free(alts);

}
void	read_map(char *file, fdf *dat)
{
	int		i;
	int		fd;
	char	*line;

	dat->y = get_rows(file); //call y rows?
	dat->x = get_clms(file); //call x clms?
	dat->mtx = (int **)malloc(sizeof(int *) * (dat->y + 1));
	i = 0;
	while(i < dat->y)
		dat->mtx[i++] = (int *)malloc(sizeof(int) * (dat->x + 1));
	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (line = get_next_line(fd)) //fill mtx row by row
	{
		fill_row(dat->mtx[i], line);
		free(line);
	}
	dat->mtx[i] = 0;
	close(fd);
}

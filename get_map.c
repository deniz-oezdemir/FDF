/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/08 14:16:47 by denizozd         ###   ########.fr       */
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
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
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
	char **vals; //altitudes
	int i;

	vals = ft_split(line, ' ');
	i = 0;
	while(vals[i])
	{
		mtx[i] = ft_atoi(vals[i]);
		free(vals[i]);
		i++;
	}
	free(vals);
}
void	get_map(char *file, t_fdf *fdf)
{
	int		i;
	int		fd;
	char	*line;

	fdf->map.height = get_rows(file);
	fdf->map.width = get_clms(file);
	fdf->map.mtx = (int **)malloc(sizeof(int *) * (fdf->map.height + 1));
	i = 0;
	while(i < fdf->map.height)
		fdf->map.mtx[i++] = (int *)malloc(sizeof(int) * (fdf->map.width + 1));
	fd = open(file, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line) //fill mtx row by row
	{
		fill_row(fdf->map.mtx[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	fdf->map.mtx[i] = 0;
	close(fd);
}

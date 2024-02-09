/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 11:34:10 by denizozd         ###   ########.fr       */
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
	if (fd < 0)
		error_file();
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

	fd = open(file, O_RDONLY, 0); //necessary? check is already above with rows
	if (fd < 0)
		error_file();
	line = get_next_line(fd);
	clms = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (clms);
}

void	fill_row(int *z_row, char *line)
{
	char **vals; //altitudes
	int i;

	vals = ft_split(line, ' ');
	i = 0;
	while(vals[i])
	{
		z_row[i] = ft_atoi(vals[i]);
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

	fdf->height = get_rows(file);
	fdf->width = get_clms(file);
	fdf->z_mtx = (int **)malloc(sizeof(int *) * (fdf->height + 1));
	i = 0;
	while(i < fdf->height)
		fdf->z_mtx[i++] = (int *)malloc(sizeof(int) * (fdf->width + 1));
	fd = open(file, O_RDONLY, 0);
	if (fd < 0) //necessary? check is already above with rows
		error_file();
	i = 0;
	line = get_next_line(fd);
	while (line) //fill mtx row by row
	{
		fill_row(fdf->z_mtx[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	fdf->z_mtx[i] = 0;
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 19:25:41 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rows(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		rows;

	rows = 0;
	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		error_file(data, fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rows++;
		free(line);
	}
	free(line);
	close(fd);
	return (rows);
}

int	get_clms(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		clms;

	fd = open(file, O_RDONLY, 0); //necessary? check is already above with rows
	if (fd < 0)
		error_file(data, fd);
	line = get_next_line(fd);
	if (!line)
		error_input();
	clms = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (clms);
}

void	fill_row(int *row, char *line)
{
	char **vals;
	int i;

	vals = ft_split(line, ' ');
	i = 0;
	while(vals[i])
	{
		row[i] = ft_atoi(vals[i]);
		free(vals[i]);
		i++;
	}
	free(vals);
}
void	get_map(char *file, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	data->width = get_clms(file, data); //first width then height works but not the other way around
	data->height = get_rows(file, data);
	data->z_mtx = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while(i < data->height)
		data->z_mtx[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file, O_RDONLY, 0);
	if (fd < 0) //necessary? check is already above with rows
		error_file(data, fd);
	i = 0;
	while (1) //fill mtx row by row
	{
		line = get_next_line(fd);
		ft_printf("%s\n", line); //to be deleted
		if (!line)
			break ;
		fill_row(data->z_mtx[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}

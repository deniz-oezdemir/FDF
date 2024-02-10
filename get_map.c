/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/10 21:32:19 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	file_to_strs(char *file, t_fdf *data) //file_to_lst
{
	int		fd;
	char	*line;
	t_list	*lst;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		error_file(data, fd);
	ft_printf("file_to_strs\n"); //to be deleted

	line = get_next_line(fd);
	lst = ft_lstnew(line);
	ft_lstadd_back(&(data->head), lst);
	ft_printf("%s\n", data->head->content);

	while (0)
	{


		/*ft_lstadd_back(&(data->head), );
		if (ft_lstlast((data->head)->content) == NULL)
			break ;*/
	}
	close(fd);
}

/*
int	get_rows(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		rows;

	rows = 0;
	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		error_file(data, fd);
	ft_printf("get_rows\n"); //to be deleted
	while (1)
	{
		line = get_next_line(fd);
		ft_printf("%s\n", line); //to be deleted
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
	ft_printf("get_clmns\n"); //to be deleted
	ft_printf("%s\n", line); //to be deleted
	if (!line)
		error_input();
	clms = ft_count_words(line, ' ');
	free(line);
	while (1) //go to end of file to mitigate static ptr in gnl
	{
		line = get_next_line(fd);
		ft_printf("%s\n", line); //to be deleted
		if (!line)
			break ;
		free(line);
	}
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

	data->height = get_rows(file, data);
	data->width = get_clms(file, data); //first width then height works but not the other way around -> fixeb through running clms through whole file
	data->z_mtx = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while(i < data->height)
		data->z_mtx[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file, O_RDONLY, 0);
	if (fd < 0) //necessary? check is already above with rows
		error_file(data, fd);
	i = 0;
	ft_printf("get_map\n"); //to be deleted
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
	close(fd);
}
*/

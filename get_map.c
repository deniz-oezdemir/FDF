/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/12 13:00:15 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_to_list(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	t_list	*new;

	data->z_list = NULL;
	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		error_file(data, fd, 0);
	line = get_next_line(fd);
	if (!line || !ft_isprint(line[0]))
		error_file(data, fd, 1);
	while (line && ft_isprint(line[0]))
	{
		new = ft_lstnew(line);
		ft_lstadd_back(&(data->z_list), new);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	get_width(t_fdf *data)
{
	int	width;

	width = ft_count_words(data->z_list->content, ' ');
	data->width = width;
}

void	list_to_matrix(t_fdf *data)
{
	t_list	*tmp;
	int		i;

	data->height = ft_lstsize(data->z_list);
	get_width(data);
	data->z_mtx = (int **)malloc(sizeof(int *) * (data->height));
	i = 0;
	while (i < data->height)
		data->z_mtx[i++] = (int *)malloc(sizeof(int) * (data->width));
	tmp = data->z_list;
	i = 0;
	while (i < data->height)
	{
		fill_row(data->z_mtx[i], tmp->content);
		tmp = tmp->next;
		i++;
	}
}

/* free(zs[last]) as split returns null as last element */
void	fill_row(int *z_mtx_row, char *z_str)
{
	char	**zs;
	int		i;

	zs = ft_split(z_str, ' ');
	i = 0;
	while (zs[i])
	{
		z_mtx_row[i] = ft_atoi(zs[i]);
		free(zs[i]);
		i++;
	}
	free(zs[i]);
	free(zs);
}

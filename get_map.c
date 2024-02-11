/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/11 17:49:36 by denizozd         ###   ########.fr       */
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
		error_file(data, fd);
	ft_printf("file_to_list\n"); //to be deleted
	line = get_next_line(fd);
	if(!line || !ft_isprint(line[0])) //empty space at beginning of file/line?
		error_file(data, fd); //add error case empty file
	while (line && ft_isprint(line[0])) //why do some maps have empty space at the end? or does gnl not work properly?
	{
		new = ft_lstnew(line);
		ft_printf("new node's content: %s", new->content); //to be deleted
		ft_lstadd_back(&(data->z_list), new);
		ft_printf("last node's content: %s", ft_lstlast(data->z_list)->content); //to be deleted
		line = get_next_line(fd);
	}
	ft_printf("test last node's content: %s\n", ft_lstlast(data->z_list)->content);
	ft_printf("list size: %d\n", ft_lstsize(data->z_list));
	free(line);
	close(fd);
}

void	get_height(t_fdf *data)
{
	t_list	*tmp;
	int		height;

	height = 0;
	tmp = data->z_list;
	while (tmp)
	{
		height++;
		//ft_printf("%s", tmp->content); //to be deleted
		tmp = tmp->next;
	}
	data->height = height;
}

void	get_width(t_fdf *data)
{
	int		width;

	width = ft_count_words(data->z_list->content, ' ');
	data->width = width;
}

void	list_to_matrix(t_fdf *data)
{
	t_list	*tmp;
	int i;

	get_height(data);
	ft_printf("height: %d\n", data->height);
	get_width(data);
	ft_printf("width: %d\n", data->width);
	ft_printf("before: first node's content: %s", data->z_list->content);
	ft_printf("before: second node's content: %s", data->z_list->next->content);
	data->z_mtx = (int **)malloc(sizeof(int *) * (data->height));
	i = 0;
	while(i < data->height)
		data->z_mtx[i++] = (int *)malloc(sizeof(int) * (data->width));
	tmp = data->z_list;
	i = 0;
	while(i < data->height)
	{
		fill_row(data->z_mtx[i], tmp->content);
		tmp = tmp->next;
		i++;
	}
	ft_printf("after: first node's content: %s", data->z_list->content);
	ft_printf("after: second node's content: %s", data->z_list->next->content);
}

void	fill_row(int *z_mtx_row, char *z_str)
{
	char **zs;
	int i;

	zs = ft_split(z_str, ' ');
	i = 0;
	while(zs[i])
	{
		z_mtx_row[i] = ft_atoi(zs[i]);
		free(zs[i]);
		i++;
	}
	free(zs[i]); //split returns null as last element
	free(zs);
}

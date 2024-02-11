/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/11 15:05:53 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_to_list(char *file, t_fdf *data)
{
	int		fd;
	char	*line = NULL;
	t_list	*new = NULL;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		error_file(data, fd);
	//ft_printf("file_to_list\n"); //to be deleted
	while (1)
	{
		line = get_next_line(fd);
		new = ft_lstnew(line);
		ft_lstadd_back(&(data->list), new);
		//ft_printf("%s", ft_lstlast(data->list)->content); //to be deleted
		if (ft_lstlast(data->list)->content == NULL)
			break ;
	}
	//ft_printf("\n");
	get_height(data);
	//ft_printf("height: %d\n", data->height);
	get_width(data);
	//ft_printf("width: %d\n", data->width);
	close(fd);
}

void	get_height(t_fdf *data)
{
	t_list	*tmp;
	int		height;

	height = 0;
	tmp = data->list;
	while (tmp->next && tmp->next->content)
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

	width = ft_count_words(data->list->content, ' ');
	data->width = width;
}

void	list_to_matrix(t_fdf *data)
{
	t_list	*tmp;
	int i;

	data->z_mtx = (int **)malloc(sizeof(int *) * (data->height));
	i = 0;
	while(i < data->height)
		data->z_mtx[i++] = (int *)malloc(sizeof(int) * (data->width));
	tmp = data->list;
	i = 0;
	while(i < data->height)
	{
		fill_row(data->z_mtx[i], tmp->content);
		tmp = tmp->next;
		i++;
	}
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
	free(zs);
}

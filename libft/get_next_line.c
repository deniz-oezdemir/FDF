/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:27:50 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/03 13:17:16 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*extract_excess(char *line)
{
	char	*eol;
	char	*excess;

	eol = ft_strchr(line, '\n');
	if (!eol++)
		return (NULL);
	else
	{
		excess = ft_strdup(eol);
		*eol = '\0';
		return (excess);
	}
}

/* if buf not static, stackoverflow for high BUFFER_SIZE */
char	*read_buffer(char *line, int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		nb;

	//if reset == 1
		//read(fd, line)
	while (!ft_strchr(line, '\n'))
	{
		nb = read(fd, buf, BUFFER_SIZE);
		if (nb == 0) //end of file
			break ;
		if (nb == -1)
		{
			free(line);
			return (NULL);
		}
		buf[nb] = '\0';
		line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd, int reset)
{
	static char	*excess;
	char		*line;
	char		start;

	//if(reset == 1)
		//reset excess to point to beginning of first line
	if(reset)
		start = read(fd, excess, 1);
	//if does not work: read returns 0 if end of file reached

	//Closing and reopening the file will reset the file position, allowing you to read from the beginning again.
	
	line = read_buffer(excess, fd);
	excess = extract_excess(line);
	return (line);
}

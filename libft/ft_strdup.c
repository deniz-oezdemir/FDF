/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:04:38 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/11 11:20:09 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	l;

	/*if (!s || !*s)
		return (NULL);*/
	l = ft_strlen(s);
	dst = (char *)(malloc(sizeof(char) * (l + 1)));
	if (dst == NULL)
		return (NULL);
	/*dst[l] = '\0';
	while (l--)
		dst[l] = s[l];*/
	ft_strlcpy(dst, s, l + 1);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:41:22 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/09 09:59:59 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//this file is not needed, maybe merge with events.c

int	close_frame(t_fdf *data) //close window
{
	(void)data;
	//free_data(data);
	exit(0);
}

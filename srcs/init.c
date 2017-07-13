/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:34:27 by rle               #+#    #+#             */
/*   Updated: 2017/05/16 17:40:00 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	data_init(t_data *data, int size)
{
	data->win_size.x = size;
	data->win_size.y = size;
	data->dist.x = data->win_size.x / (data->dim.x * 2);
	data->dist.y = data->win_size.y / (data->dim.y * 2);
	data->start.x = (data->win_size.x / 2) - ((data->dim.x - \
		(data->dim.x / 2)) * data->dist.x);
	data->start.y = (data->win_size.y / 2) - ((data->dim.y - \
		(data->dim.y / 2)) * data->dist.y);
}

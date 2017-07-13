/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:37:11 by rle               #+#    #+#             */
/*   Updated: 2017/05/16 15:47:44 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	key_help(t_data *data, int keycode)
{
	mlx_clear_window(data->mlx, data->win);
	if (keycode == 53)
	{
		free_map(data->map, data->dim.y);
		free(data);
		exit(1);
	}
	if (keycode == 8)
		data->color = (data->color + 1) % 10;
}

int			my_key_funct(int keycode, t_data *data)
{
	key_help(data, keycode);
	if (keycode == 126)
		data->change++;
	if (keycode == 125)
		data->change--;
	if (keycode == 13)
		data->start.y -= 8;
	if (keycode == 1)
		data->start.y += 8;
	if (keycode == 0)
		data->start.x -= 8;
	if (keycode == 2)
		data->start.x += 8;
	if (keycode == 24)
		data->scale += .1;
	if (keycode == 27 && data->scale > .1)
		data->scale -= .1;
	if (keycode == 29)
		data->scale = 1;
	if (keycode == 38)
		data->ytheta++;
	if (keycode == 37)
		data->ytheta--;
	draw_map(data, data->map, data->change);
	return (1);
}

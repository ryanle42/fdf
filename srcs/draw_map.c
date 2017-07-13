/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:36:04 by rle               #+#    #+#             */
/*   Updated: 2017/05/23 14:31:19 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	set_z(t_data *data, int **map, int coor[], int *tmp[])
{
	if (map[coor[1]][coor[0]] != 0)
	{
		*(tmp[0]) = coor[2] + (map[coor[1]][coor[0]] * 5);
		*(tmp[2]) = map[coor[1]][coor[0]] * sin(data->ytheta * \
			(3.14159265358 / 180));
	}
	else
	{
		*(tmp[0]) = 0;
		*(tmp[2]) = 0;
	}
	if (map[coor[1]][coor[0] + 1] != 0)
	{
		*(tmp[1]) = coor[2] + (map[coor[1]][coor[0] + 1] * 5);
		*(tmp[3]) = map[coor[1]][coor[0] + 1] * sin(data->ytheta * \
			(3.14159265358 / 180));
	}
	else
	{
		*(tmp[1]) = 0;
		*(tmp[3]) = 0;
	}
}

static void	draw_help(t_data *data, int **map, int change, int coor[])
{
	int		tmp0;
	int		tmp1;
	int		sn0;
	int		sn1;
	double	cy;

	cy = cos(data->ytheta * (3.14159265358 / 180));
	set_z(data, map, (int[]){coor[0], coor[1], change}, \
		(int*[]){&tmp0, &tmp1, &sn0, &sn1});
	if (coor[2])
		b_line((float[]){(((coor[0] * data->dist.x) * \
			data->scale)) + data->start.x, ((((coor[1] * \
				data->dist.y)) * cy) - sn0 - tmp0) * data->scale \
			+ data->start.y}, (float[]){((((coor[0] + 1) * \
				data->dist.x) * data->scale)) + data->start.x, \
			((((coor[1] * data->dist.y)) * cy) - sn1 - tmp1) * \
			data->scale + data->start.y}, data);
	else
		b_line((float[]){(((coor[0] * data->dist.x) * data->scale)) \
			+ data->start.x, (((coor[1] * data->dist.y) * cy) - sn0 - \
			tmp0) * data->scale + data->start.y}, (float[]){((coor[0] \
			* data->dist.x) * data->scale) + data->start.x, (((coor[1] + 1) \
			* data->dist.y) * cy) * data->scale + data->start.y}, data);
}

void		draw_map(t_data *data, int **map, int change)
{
	int x;
	int y;

	y = -1;
	while (++y + 1 < data->dim.y)
	{
		x = -1;
		while (++x + 1 < data->dim.x)
		{
			draw_help(data, map, change, (int[]){x, y, 0});
			draw_help(data, map, change, (int[]){x, y, 1});
		}
		draw_help(data, map, change, (int[]){x, y, 0});
	}
	x = -1;
	while (++x + 1 < data->dim.x)
		draw_help(data, map, change, (int[]){x, y, 1});
}

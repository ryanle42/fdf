/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:30:49 by rle               #+#    #+#             */
/*   Updated: 2017/05/17 15:31:27 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static float	ft_fabs(float n)
{
	return (n > 0 ? n : -n);
}

static void		ft_swap(float *a, float *b)
{
	float	c;

	c = *a;
	*a = *b;
	*b = c;
}

static void		swapparoo(float a[], float b[], char steep)
{
	if (steep)
	{
		ft_swap(&a[0], &a[1]);
		ft_swap(&b[0], &b[1]);
	}
	if (a[0] > b[0])
	{
		ft_swap(&a[0], &b[0]);
		ft_swap(&a[1], &b[1]);
	}
}

static int		get_color(int color)
{
	if (color == 0)
		return (0xfffafa);
	if (color == 1)
		return (0xdda0dd);
	if (color == 2)
		return (0xffdab9);
	if (color == 3)
		return (0xf0fff0);
	if (color == 4)
		return (0x483d8b);
	if (color == 5)
		return (0xcd3278);
	if (color == 6)
		return (0xa9a9a9);
	if (color == 7)
		return (0xcd7054);
	if (color == 8)
		return (0x7cfc00);
	if (color == 9)
		return (0xafeeee);
	if (color == 10)
		return (0xffefd5);
	return (1);
}

void			b_line(float a[], float b[], t_data *data)
{
	char	steep;
	float	err;
	int		y;
	int		x;

	steep = (ft_fabs(b[1] - a[1]) > ft_fabs(b[0] - a[0]));
	swapparoo(a, b, steep);
	err = (b[0] - a[0]) / 2.0;
	y = (int)a[1];
	x = a[0] - 1;
	while (++x < (int)b[0])
	{
		if (steep)
			mlx_pixel_put(data->mlx, data->win, y, x, get_color(data->color));
		else
			mlx_pixel_put(data->mlx, data->win, x, y, get_color(data->color));
		err -= ft_fabs(b[1] - a[1]);
		if (err < 0)
		{
			y += (a[1] < b[1]) ? 1 : -1;
			err += b[0] - a[0];
		}
	}
}

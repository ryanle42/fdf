/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:13:09 by rle               #+#    #+#             */
/*   Updated: 2017/05/23 14:18:24 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
		ft_err_exit();
	data = (t_data *)malloc(sizeof(t_data));
	if (-1 == (data->fd = open(argv[1], O_RDONLY)))
		ft_err_exit();
	data->map = get_map(data);
	data->scale = 1;
	data->change = 0;
	data->ytheta = 0;
	data->color = 0;
	data_init(data, 1000);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->win_size.x, \
		data->win_size.y, "mlx 42");
	draw_map(data, data->map, data->change);
	mlx_hook(data->win, 2, 0, my_key_funct, data);
	mlx_loop(data->mlx);
	free_map(data->map, data->dim.y);
	free(data);
}

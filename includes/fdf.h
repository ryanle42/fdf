/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:38:24 by rle               #+#    #+#             */
/*   Updated: 2017/05/23 14:04:57 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

typedef struct		s_dim
{
	int				x;
	int				y;
}					t_dim;

typedef struct		s_start
{
	int				x;
	int				y;
}					t_start;

typedef struct		s_win
{
	int				x;
	int				y;
}					t_win;

typedef struct		s_dist
{
	int				x;
	int				y;
}					t_dist;

typedef struct		s_data
{
	int				**map;
	void			*mlx;
	void			*win;
	int				color;
	int				fd;
	int				change;
	int				ytheta;
	float			scale;
	struct s_dim	dim;
	struct s_start	start;
	struct s_win	win_size;
	struct s_dist	dist;
}					t_data;

typedef struct		s_doc
{
	char			*line;
	struct s_doc	*next;
}					t_doc;

/*
**	init
*/

void				data_init(t_data *data, int size);

/*
**	brensenham_alg
*/
void				b_line(float a[], float b[], t_data *data);

/*
**	draw_map
*/

void				draw_map(t_data *data, int **map, int change);

/*
**	get_map
*/

int					**get_map(t_data *data);
void				ft_err_exit(void);

/*
** get_map_help
*/

void				store_split(int **arr, char **split, int max, int i);
int					is_num(char *str);
/*
**	let_it_go
*/

void				free_map(int **map, int max);
void				free_char_arr(char **arr, int max);
void				free_doc(t_doc *doc);

/*
**	key_functs
*/

int					my_key_funct(int keycode, t_data *data);

#endif

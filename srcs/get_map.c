/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:35:10 by rle               #+#    #+#             */
/*   Updated: 2017/05/23 14:26:26 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			ft_err_exit(void)
{
	ft_printf("ERROR\n");
	exit(1);
}

static int		**make_int_arr(t_doc *curr, t_data *data, int i)
{
	t_doc	*prev;
	char	**split;
	int		**arr;

	prev = curr;
	split = ft_strsplit(curr->line, ' ');
	data->dim.x = ft_count_wds(curr->line, ' ');
	arr = (int**)malloc(sizeof(int *) * data->dim.y);
	store_split(arr, split, data->dim.x, i);
	free_char_arr(split, data->dim.x);
	while (++i < data->dim.y)
	{
		curr = curr->next;
		split = (ft_strsplit(curr->line, ' '));
		if (ft_count_wds(curr->line, ' ') != data->dim.x)
			ft_err_exit();
		store_split(arr, split, data->dim.x, i);
		free_char_arr(split, data->dim.x);
		free_doc(prev);
		prev = curr;
	}
	free_doc(curr);
	return (arr);
}

static int		file_length(t_doc *file)
{
	t_doc	*curr;
	int		length;

	length = 1;
	curr = file;
	while (curr->next)
	{
		curr = curr->next;
		length++;
	}
	return (length);
}

static t_doc	*get_doc(t_data *data)
{
	t_doc	*file;
	t_doc	*current;
	char	*line;

	if (-1 == (get_next_line(data->fd, &line)))
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	file = (t_doc*)malloc(sizeof(t_doc));
	file->line = line;
	file->next = NULL;
	current = file;
	while (get_next_line(data->fd, &line))
	{
		current->next = (t_doc*)malloc(sizeof(t_doc));
		current = current->next;
		current->line = line;
		current->next = NULL;
	}
	free(line);
	return (file);
}

int				**get_map(t_data *data)
{
	t_doc *file;

	file = get_doc(data);
	data->dim.y = file_length(file);
	return (make_int_arr(file, data, 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_it_go.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:34:12 by rle               #+#    #+#             */
/*   Updated: 2017/05/16 15:46:42 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	free_map(int **map, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_char_arr(char **arr, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_doc(t_doc *doc)
{
	free(doc->line);
	free(doc);
}

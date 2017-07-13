/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:42:54 by rle               #+#    #+#             */
/*   Updated: 2017/05/23 14:24:38 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		is_num(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

void	store_split(int **arr, char **split, int max, int i)
{
	int j;

	j = 0;
	arr[i] = (int *)malloc(sizeof(int) * max);
	while (j < max)
	{
		if (!is_num(split[j]))
		{
			ft_printf("ERROR\n");
			exit(1);
		}
		arr[i][j] = ft_atoi(split[j]);
		j++;
	}
}

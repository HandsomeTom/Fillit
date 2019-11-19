/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:20:28 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/19 21:27:41 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char **make_grid(int size)
{
	int i = -1;
	char	**map = (char **)malloc(sizeof(char **) * size);
	if (map)
	{
		while (++i < size)
		{
			if ((map[i] = ft_strnew(size)) == NULL)
			{
				i = 0;
				while (i < size)
					free(map[i]);
				free(map);
				return (NULL);
			}
			ft_memset(map[i], '.', size);
		}
	}
	return (map);
}

char **copy_grid(char **smaller, int size)
{
	char **map = make_grid(size);

	if (map != NULL)
	{
		int y = 0;
		while (y < size - 1)
		{
			int x = 0;
			while (x < size - 1)
			{
				map[y][x] = smaller[y][x];
				++x;
			}
			++y;
		}
	}
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:20:28 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/20 15:06:18 by ngontjar         ###   ########.fr       */
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

char **copy_grid(char **smaller, int size, int same_size) // 5
{
	char **map = make_grid(size); // 5x5

	ft_putstr("same size: "); ft_putendl(ft_itoa(same_size));
	ft_putendl("bigger:");
	ft_print2dstr(map, size);
	ft_putendl("smaller:");
	ft_print2dstr(smaller, size - 1 + same_size);
	ft_putendl("");

	if (map != NULL)
	{
		int y = 0;
		while (y < size - 1 + same_size) // 4
		{
			int x = 0;
			while (x < size - 1 + same_size)
			{
				// printf("copying x%d y%d\n", x, y);
				map[y][x] = smaller[y][x]; // 0 - 3
				++x;
			}
			++y;
		}
	}
	return (map);
}

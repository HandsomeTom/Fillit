/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:26:51 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/15 17:36:09 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		empty(char **map2D, int posX, int posY, t_piece *tet)
{
	int ok = 0;

	int y = 0;

	while (y < 4)
	{
		int x = 0;
		while (x < 4)
		{
			if (tet->coords[y][x] == 1 && map2D[posY + y][posX + x] == 0)
				++ok;
			++x;
		}
		++y;
	}
	return (ok == 4);
}

void	put(char **map2D, int posX, int posY, t_piece *tet)
{
	// ft_putendl("put");
	int y = 0;
	while (y < 4)
	{
		// ft_putendl(map2D[y]);
		int x = 0;
		while (x < 4)
		{
			// ft_putendl("coords");
			// ft_putendl(ft_itoa(posY));
			// ft_putendl(ft_itoa(posX));
			if (tet->coords[y][x] == 1)
			{
				map2D[posY + y][posX + x] = tet->letter;
			}
			++x;
		}
		++y;
	}
}

char	**smallest_square(char **map2D, int size, t_piece **tet, int count)
{
	if (count < 1)
		return (map2D);
	ft_putendl("recursive hell");

	char	**copy = malloc(sizeof(char *) * size);
	copy[0] = malloc(5);
	copy[1] = malloc(5);
	copy[2] = malloc(5);
	copy[3] = malloc(5);
	int		i = -1;
	while (++i < size)
		ft_strncpy(copy[i], map2D[i], 4);

	int y = 0;
	while (y < size)
	{
		ft_putstrn(copy[y], 4);
		ft_putendl("");
		int x = 0;
		while (x < size)
		{
			// ft_putendl("coords");
			// ft_putendl(ft_itoa(y));
			// ft_putendl(ft_itoa(x));
			if(empty(copy, x, y, tet[count - 1]))
			{
				put(copy, x, y, tet[--count]);

				return (smallest_square(copy, size, &tet[count], count));
			}
			++x;
		}
		++y;
	}
	return (NULL);
}

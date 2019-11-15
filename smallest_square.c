/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:26:51 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/15 14:57:45 by ngontjar         ###   ########.fr       */
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
			if (tet->coords[x][y] == 1 && map2D[posX + x][posY + y] == 0)
				++ok;
			++x;
		}
		++y;
	}
	return (ok == 4);
}

void	put(char **map2D, int posX, int posY, t_piece *tet)
{
	int y = 0;
	while (y < 4)
	{
		int x = 0;
		while (x < 4)
		{
			if (tet->coords[x][y] == 1)
				map2D[posX + x][posY + y] = tet->letter;
			++x;
		}
		++y;
	}
}

char	**smallest_square(char **map2D, int size, t_piece **tet, int count)
{
	if (count < 0)
		return (map2D);

	char	copy[size][size];
	int		i = -1;
	while (++i < size)
		ft_strncpy(copy[i], map2D[i], 4);

	int y = 0;
	while (y < size)
	{
		int x = 0;
		while (x < size)
		{
			if(empty(map2D, x, y, tet[count - 1]))
			{
				put(map2D, x, y, tet[--count]);
				return (smallest_square(map2D, size, &tet[count], count));
			}
			++x;
		}
		++y;
	}
	return (NULL);
}

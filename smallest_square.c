/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:26:51 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/18 13:47:19 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int		empty(char **map2D, int posX, int posY, t_piece *tet)
int		empty(char **map2D, t_xy pos, int size, t_piece *tet)
{
	int ok = 0;

	ft_putendl("empty?");

	int y = 0;
	while (y < 4)
	{
		int x = 0;
		while (x < 4)
		{
			// ft_putstr(ft_itoa(tet->coords[y][x]));
			// ft_putchar(map2D[pos.y + y][pos.x + x]);
			if ((pos.y + y <= size && pos.x + x <= size)
			&& tet->coords[y][x] == 1
			&& map2D[pos.y + y][pos.x + x] == '.')
				++ok;
			++x;
		}
		// ft_putchar('\n');
		++y;
	}
	// ft_putendl(ft_itoa(ok));
	return (ok == 4);
}

// void	put(char **map2D, int posX, int posY, t_piece *tet)
void	put(char **map2D, t_xy pos, t_piece *tet)
{
	// ft_putendl("put");
	int y = 0;
	while (y < 4)
	{
		// ft_putendl(map2D[y]);
		int x = 0;
		while (x < 4)
		{
			// ft_putendl("sdjhgadhgajhf");
			// ft_putendl(ft_itoa(posY));
			// ft_putendl(ft_itoa(posX));
			if (tet->coords[y][x] == 1)
			{
				map2D[pos.y + y][pos.x + x] = tet->letter;

			}
			++x;
		}
		++y;
	}
}

char	**smallest_square(char **map2D, int size, t_piece **tet, int count)
{
	ft_putendl("recursive hell");
	ft_print2dstr(map2D, 4);
	char	**copy = malloc(sizeof(char *) * size);
	copy[0] = malloc(5);
	copy[1] = malloc(5);
	copy[2] = malloc(5);
	copy[3] = malloc(5);

	if (count < 1)
		return (copy);

	int		i = -1;
	while (++i < size)
		ft_strncpy(copy[i], map2D[i], 4);
	ft_print2dstr(copy, 4);

	int y = 0;
	while (y < size)
	{
		// ft_putstrn(copy[y], 4);
		// ft_putendl("");
		int x = 0;
		while (x < size)
		{
			// ft_putendl("coords");
			// ft_putendl(ft_itoa(y));
			// ft_putendl(ft_itoa(x));
			// ft_putstr(ft_itoa(tet[count - 1]->coords[y][x]));
			if (empty(copy, (t_xy){x, y}, size, tet[count - 1]))
			{
				put(copy, (t_xy){x, y}, tet[--count]);
				return (smallest_square(copy, size, &tet[count], count));
			}
			++x;
		}
		++y;
	}
	return (NULL);
}

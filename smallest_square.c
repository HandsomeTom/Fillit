/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:26:51 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/20 15:38:03 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

char	**smallest_square(char **map2D, int size, t_piece *lst, int same_size)
{
	ft_putendl("recursive hell");
	char	**copy = copy_grid(map2D, size, same_size);
	// ft_print2dstr(copy, size); ft_putendl("");
	t_piece *prev = lst;
	// todo: count should never be < 1
	// if (count < 1)
	// 	return (copy);

	t_xy pos;
	while (lst != NULL)
	{
		pos.y = 0;
		while (pos.y < size)
		{
			pos.x = 0;
			while (pos.x < size)
			{
				if (empty(copy, pos, size, lst))
				{
					put(copy, pos, lst);
					if (smallest_square(copy, size, lst->next, TRUE))
						return (copy);
					else
						rip(copy, pos, lst);
				}
				++pos.x;
			}
			++pos.y;
		}
		if (pos.y >= size)
			return (smallest_square(copy, size + 1, lst, FALSE));
		lst = lst->next;
	}
	return (copy);
}

int		empty(char **map2D, t_xy grid, int size, t_piece *tet)
{
	int ok = 0;

	// ft_putendl("empty?");
	// printf("sq size: %d\n", size);
	// printf("tet size: x%d y%d\n", tet->width, tet->height);

	int y = 0;
	while (y < tet->height)
	{
		int x = 0;
		while (x < tet->width)
		{
			// printf("empty at x%d y%d?\n", grid.x + x, grid.y + y);
			if ((grid.y + y < size && grid.x + x < size)
			&& tet->coords[y][x]
			&& map2D[grid.y + y][grid.x + x] == '.')
			{
				// printf("ok at x%d y%d!\n", grid.x + x, grid.y + y);
				++ok;
			}

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
	int y = 0;
	while (y < tet->height)
	{
		int x = 0;
		while (x < tet->width)
		{
			// printf("put at x%d y%d?\n", pos.x + x, pos.y + y);
			if (tet->coords[y][x] == 1)
			{
				// printf("putting at x%d y%d!\n", pos.x + x, pos.y + y);
				map2D[pos.y + y][pos.x + x] = tet->letter;
			}
			++x;
		}
		++y;
	}
}

void	rip(char **map2D, t_xy pos, t_piece *tet)
{
	int y = 0;
	while (y < tet->height)
	{
		int x = 0;
		while (x < tet->width)
		{
			if (tet->coords[y][x] == 1)
			{
				map2D[pos.y + y][pos.x + x] = '.';
			}
			++x;
		}
		++y;
	}
}

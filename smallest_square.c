/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:26:51 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/19 21:15:50 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		empty(char **map2D, t_xy pos, int size, t_piece *tet);
void	put(char **map2D, t_xy pos, t_piece *tet);

char	**smallest_square(char **map2D, int size, t_piece *lst)
{
	ft_putendl("recursive hell");
	char	**copy = copy_grid(map2D, size);

	// ft_print2dstr(copy, size); ft_putendl("");

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
					// ft_print2dstr(copy, size); ft_putendl("");
					return (smallest_square(copy, size, lst->next));
				}
				++pos.x;
			}
			++pos.y;
			ft_putendl(ft_itoa(pos.y));
		}
		if (pos.y >= size)
			return (smallest_square(map2D, size + 1, lst));
		lst = lst->next;
	}
	return (copy);
}

int		empty(char **map2D, t_xy grid, int size, t_piece *tet)
{
	int ok = 0;

	ft_putendl("empty?");
	printf("tet size: x%d y%d\n", tet->width, tet->height);


	int y = 0;
	while (y < tet->height)
	{
		int x = 0;
		while (x < tet->width)
		{
			if ((grid.y + y < size && grid.x + x < size)
			&& tet->coords[y][x]
			&& map2D[grid.y + y][grid.x + x] == '.')
			{
				++ok;
			}

			++x;
		}
		ft_putchar('\n');
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
			printf("put x%d y%d\n", pos.x + x, pos.y + y);
			if (tet->coords[y][x] == 1)
			{
				printf("^ placed\n");
				map2D[pos.y + y][pos.x + x] = tet->letter;
			}
			++x;
		}
		++y;
	}
}

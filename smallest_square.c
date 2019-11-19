/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:26:51 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/19 17:12:41 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		empty(char **map2D, t_xy pos, int size, t_piece *tet);
void	put(char **map2D, t_xy pos, t_piece *tet);

char	**smallest_square(char **map2D, int size, t_piece *lst)
{
	ft_putendl("recursive hell");
	// ft_print2dstr(map2D, 4);
	// ft_putendl("");
	int i = 0;
	char	**copy = malloc(sizeof(char *) * size);
	while (i < size)
		copy[i++] = malloc(5);

	// todo: count should never be < 1
	// if (count < 1)
	// 	return (copy);

	i = -1;
	while (++i < size)
	{
		ft_strncpy(copy[i], map2D[i], 4);
	}
	ft_print2dstr(copy, 4);
	ft_putendl("");

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
					return (smallest_square(copy, size, lst->next));
				}
				++pos.x;
			}
			++pos.y;
		}
		lst = lst->next;
	}
	return (NULL);
}

// int		empty(char **map2D, int posX, int posY, t_piece *tet)
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
			ft_putstr(ft_itoa(tet->coords[y][x]));
			// if (tet->coords[y][x] == 1)
			// 	printf("tet 0 at: x%d y%d\n", x, y);
			// if (grid.y + y > size && grid.x + x > size)
			// 	printf("out of bounds: x%d y%d\n", grid.x + x, grid.y + y);
			// if (map2D[grid.y + y][grid.x + x] != '.')
			// 	printf("no '.' at x%d y%d\n", grid.x + x, grid.y + y);
			// ft_putchar(map2D[grid.y + y][grid.x + x]);
			if ((grid.y + y < size && grid.x + x < size)
			&& tet->coords[y][x]
			&& map2D[grid.y + y][grid.x + x] == '.')
			{
				// printf("OK at: x%d y%d\n", grid.x + x, grid.y + y);
				++ok;
			}

			++x;
			// printf("itr x%d y%d\n", x, y);
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:26:51 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/22 14:52:23 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		empty(char **map2d, t_xy grid, int size, t_piece *tet)
{
	int		x;
	int		y;
	int		ok;

	ok = 0;
	y = 0;
	while (y < tet->height)
	{
		x = 0;
		while (x < tet->width)
		{
			if ((grid.y + y < size && grid.x + x < size)
			&& tet->coords[y][x]
			&& map2d[grid.y + y][grid.x + x] == '.')
				++ok;
			++x;
		}
		++y;
	}
	return (ok == 4);
}

static void		put(char **map2d, t_xy pos, t_piece *tet)
{
	int x;
	int y;

	y = 0;
	while (y < tet->height)
	{
		x = 0;
		while (x < tet->width)
		{
			if (tet->coords[y][x] == 1)
			{
				map2d[pos.y + y][pos.x + x] = tet->letter;
			}
			++x;
		}
		++y;
	}
}

static void		rip(char **map2d, t_xy pos, t_piece *tet)
{
	int x;
	int y;

	y = 0;
	while (y < tet->height)
	{
		x = 0;
		while (x < tet->width)
		{
			if (tet->coords[y][x] == 1)
			{
				map2d[pos.y + y][pos.x + x] = '.';
			}
			++x;
		}
		++y;
	}
}

static int		smallest_square(char **map2d, int size, t_piece *lst)
{
	int		x;
	int		y;

	if (lst == NULL)
		return (TRUE);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (empty(map2d, (t_xy){x, y}, size, lst))
			{
				put(map2d, (t_xy){x, y}, lst);
				if (smallest_square(map2d, size, lst->next))
					return (TRUE);
				else
					rip(map2d, (t_xy){x, y}, lst);
			}
			++x;
		}
		++y;
	}
	return (FALSE);
}

void			solve(t_piece *lst)
{
	char	**map2d;
	int		size;

	size = 2;
	map2d = make_grid(size);
	while (smallest_square(map2d, size, lst) == FALSE)
	{
		free2d(map2d, size);
		++size;
		map2d = make_grid(size);
	}
	ft_print2dstr(map2d, size);
	free2d(map2d, size);
	exit(0);
}

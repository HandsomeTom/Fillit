/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:40:42 by tmaarela          #+#    #+#             */
/*   Updated: 2019/11/22 14:40:25 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set_dimensions(t_piece *piece)
{
	int		width;
	int		height;

	width = 0;
	height = -1;
	piece->width = 0;
	piece->height = 0;
	while (height++ < 4)
	{
		width = 0;
		while (width < 4)
		{
			if (piece->coords[height][width])
			{
				if (width > piece->width)
					piece->width += 1;
				if (height > piece->height)
					piece->height += 1;
			}
			++width;
		}
	}
	piece->width += 1;
	piece->height += 1;
}

static t_piece	*new_piece(void)
{
	t_piece	*piece;
	int		x;
	int		y;

	if ((piece = (t_piece *)malloc(sizeof(t_piece))))
	{
		piece->width = 0;
		piece->height = 0;
		piece->letter = 'A';
		piece->next = NULL;
		x = 0;
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				piece->coords[y][x] = 0;
				++x;
			}
			++y;
		}
	}
	return (piece);
}

t_piece			*make_piece(char *str, char letter)
{
	t_piece	*piece;
	int		len;
	int		x;
	int		y;

	piece = new_piece();
	len = ft_strlen(str);
	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4 && ((y * 4) + x) < len)
		{
			if (str[(y * 4) + x] == '#')
				piece->coords[y][x] = 1;
			else
				piece->coords[y][x] = 0;
			++x;
		}
		x = 0;
		++y;
	}
	piece->letter = letter;
	set_dimensions(piece);
	return (piece);
}

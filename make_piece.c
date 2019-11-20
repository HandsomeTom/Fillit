/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:40:42 by tmaarela          #+#    #+#             */
/*   Updated: 2019/11/21 01:13:50 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	set_dimensions(t_piece **piece)
{
	int		width = 0;
	int		height = 0;


	while (height < 4)
	{
		width = 0;
		while (width < 4)
		{
			if ((**piece).coords[height][width])
			{
				if (width > (**piece).width)
					(**piece).width += 1;
				if (height > (**piece).height)
					(**piece).height += 1;
			}
			++width;
		}
		++height;
	}
	(**piece).width += 1;
	(**piece).height += 1;
}

t_piece		*make_piece(char *str, char letter)
{
	t_piece	*piece;
	int		len;
	int		x;
	int		y;

	piece = (t_piece *)malloc(sizeof(t_piece));
	len = ft_strlen(str);
	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4 && ((y * 4) + x) < len)
		{
			if (str[(y * 4) + x] == '#')
			{
				piece->coords[y][x] = 1;
			}
			else
			{
				piece->coords[y][x] = 0;
			}
			++x;
		}
		x = 0;
		++y;
	}
	piece->letter = letter;
	set_dimensions(&piece);
	return (piece);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:40:42 by tmaarela          #+#    #+#             */
/*   Updated: 2019/11/19 17:17:21 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** make_piece(string)
** Stores the information of the piece into a struct s_piece
** in order to have the coordinates and the representing char
** for the solver function
** Example:
** The piece
** .#..
** ###.
** ....
** ....
** Or more accurately, after joining the piece into a single string
** .#..###.........
** would be respresented as
** x[0]y[0] 0
** x[1]y[0] 1
** x[0]y[1] 1
** x[1]y[1] 1
** x[2]y[1] 1
** (all other coords 0)
*/

#include <stdio.h>
#include "fillit.h"

static void	set_dimensions(t_piece **piece)
{
	unsigned int	width = 0;
	unsigned int	height = 0;

	// printf("piece adr dim: %p\n", *piece);

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
		ft_putendl("new loop");
	while (y < 4)
	{
		while (x < 4 && ((y * 4) + x) < len)
		{
			ft_putstr(&str[(y * 4) + x]);

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
		ft_putendl("end loop");
		x = 0;
		++y;
	}
	piece->letter = letter;
	// printf("piece adr src: %p\n", piece);
	set_dimensions(&piece);
	return (piece);
}

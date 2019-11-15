/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:40:42 by tmaarela          #+#    #+#             */
/*   Updated: 2019/11/15 17:47:18 by ngontjar         ###   ########.fr       */
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

#include "fillit.h"

t_piece	*make_piece(char *str, char letter)
{
	t_piece	*temp;
	int		len;
	int		x;
	int		y;

	temp = (t_piece *)malloc(sizeof(t_piece));
	len = ft_strlen(str);
	x = 0;
	y = 0;

	while (y < 4)
	{
		while (x < 4)
		{
			if (((y * 4) + x) < len
				&& str[(y * 4) + x] == '#')
			{
				temp->coords[y][x] = 1;
			}
			else
			{
				temp->coords[y][x] = 0;
			}
			++x;
		}
		x = 0;
		++y;
	}
	temp->letter = letter;
	return (temp);
}

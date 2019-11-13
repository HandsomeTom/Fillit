/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:36 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/13 17:46:56 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Validates that a single 4x4 char grid includes a valid Tetrimino.
** If the Tetrimino is valid, returns a string that represents the Tetrimino,
** including the sequence of empty spaces before the next block
** when reading the grid from top-left to bottom-right.
** Otherwise, or if allocation fails, returns NULL.
*/

char	*validate_piece(char *array[4])
{
	int		x;
	int		y;

	char	str[14];
	int		i;

	int		started;
	int		blocks;


	ft_memset(str, '\0', 14);
	x = 0;
	i = 0;
	blocks = 0;
	ft_putendl("BBBBB");
	while (x < 4)
	{
		y = 0;
		ft_putendl(array[x]);
		while (y < 4)
		{
			// if (started || (started = (!started && array[x][y] == '#')))
			if (!started && array[x][y] == '#')
				started = TRUE;
			// ft_putendl(ft_itoa(x));
			// ft_putendl(ft_itoa(y));
			if (started && array[x][y] != '\n')
			{
				str[i++] = array[x][y];
			}
			if (array[x][y] == '#')
				++blocks;
			++y;
		}
		++x;
	}

	// char *new = ft_strnew(ft_strlen(str));
	// char *idk = ft_strcpy(new, str);
	ft_putendl("FFFF");
	return (NULL);
	// return (blocks == 4 ? ft_strcpy(ft_strnew(ft_strlen(str)), str) : NULL);

}

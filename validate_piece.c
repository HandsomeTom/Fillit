/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:36 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/13 18:19:46 by tmaarela         ###   ########.fr       */
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

	char	str[20];
	int		i;

	int		started;
	int		blocks;


	ft_memset(str, '\0', 20);
	x = 0;
	i = 0;
	blocks = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			// if (started || (started = (!started && array[x][y] == '#')))
			if (!started && array[x][y] == '#')
				started = TRUE;
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
	return (blocks == 4 ? ft_strcpy(ft_strnew(ft_strlen(str)), str) : NULL);
}

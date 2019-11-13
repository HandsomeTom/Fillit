/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:36 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/13 19:47:36 by ngontjar         ###   ########.fr       */
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

int		idk(int index, char *rst)
{
	char *piece[19];

	piece[0] = "#...#...#...#";
	piece[1] = "####";
	piece[2] = "##..##";
	piece[3] = "##..#...#";
	piece[4] = "###...#";
	piece[5] = "#...#..##";
	piece[6] = "#...###";
	piece[7] = "#...#...##";
	piece[8] = "###.#";
	piece[9] = "##...#...#";
	piece[10] = "#.###";
	piece[11] = "###..#";
	piece[12] = "#..##...#";
	piece[13] = "#..###";
	piece[14] = "#...##..#";
	piece[15] = "##...##";
	piece[16] = "##.##";
	piece[17] = "#...##...#";
	piece[18] = "#..##..#";
	return (ft_strstr(piece[index], rst) != NULL);
}

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
	started = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			// if (started || (started = (!started && array[x][y] == '#')))
			if (!started && array[x][y] == '#')
				started = TRUE;
			if (started && blocks < 4 && array[x][y] != '\n')
			{
				str[i++] = array[x][y];
			}
			if (array[x][y] == '#')
				++blocks;
			++y;
		}
		++x;
	}
	y = 0;
	while (blocks == 4 && y < 19)
	{
		if (idk(y++, str))
			return (ft_strcpy(ft_strnew(ft_strlen(str)), str));
	}
	return (NULL);
}



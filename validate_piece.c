/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:36 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/19 19:42:19 by ngontjar         ###   ########.fr       */
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

int		is_piece(int index, char *rst)
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
	piece[10] = "..#.###";
	piece[11] = "###..#";
	piece[12] = ".#..##...#";
	piece[13] = ".#..###";
	piece[14] = "#...##..#";
	piece[15] = "##...##";
	piece[16] = ".##.##";
	piece[17] = "#...##...#";
	piece[18] = "#..##..#";
	return (ft_strstr_len(rst, piece[index]));
}

int		validate_size(char *str)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			ret++;
		i++;
	}
	if (ret == 4)
		return (1);
	else
		return (-1);
}

char	*validate_piece(char *array[4])
{
	char	*joined;
	char	str[14];
	int		i;
	int		j;
	int		blocks;


	ft_memset(str, '\0', 14);
	i = 0;
	blocks = 0;
	joined = (char *)malloc(21);
	while (i < 4)
		joined = ft_strjoin(joined, array[i++]);
	if (validate_size(joined) == -1)
		return (NULL);
	i = 0;
	j = -1;
	while (i < 19 && j < 0)
		j = is_piece(i++, joined);
	if (j >= 0)
	{
		i = 0;
		while (i < 14 && blocks < 4)
		{
			if (joined[j + i] == '#')
				blocks++;
			str[i] = joined[i + j];
			i++;
		}
		str[i] = '\0';
		return (ft_strcpy(ft_strnew(ft_strlen(str)), str));
	}
	return (NULL);
}



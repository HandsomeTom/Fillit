/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:36 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/28 13:47:40 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	piece_start(int index, char *piece_str)
{
	char *piece[19];

	piece[0] = "#...#...#...#";
	piece[1] = "####";
	piece[2] = "##..##";
	piece[3] = "##..#...#";
	piece[4] = "###...#";
	piece[5] = ".#...#..##";
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
	piece[18] = ".#..##..#";
	return (ft_strstr_len(piece_str, piece[index]));
}

static int	validate_size(char *piece_str)
{
	int		i;
	int		ok;

	i = 0;
	ok = 0;
	while (piece_str[i] != '\0')
	{
		if (piece_str[i] == '#')
			++ok;
		++i;
	}
	return (ok == 4);
}

static char	*make_piece_str(char *piece[4])
{
	char	*string;
	int		i;

	string = ft_strnew(20);
	i = 0;
	while (i < 4)
	{
		if (string == NULL)
			return (NULL);
		string = ft_strcat(string, piece[i]);
		ft_strdel(&piece[i]);
		++i;
	}
	return (string);
}

static char	*cut_piece(char *piece_str, int start)
{
	char	string[14];
	int		i;
	int		blocks;

	i = 0;
	blocks = 0;
	while (i < 14 && blocks < 4)
	{
		if ((string[i] = piece_str[start + i]) == '#')
			++blocks;
		++i;
	}
	string[i] = '\0';
	ft_strdel(&piece_str);
	return (ft_strdup(string));
}

char		*validate_piece(char *piece[4])
{
	char	*piece_str;
	int		start;
	int		i;

	if ((piece_str = make_piece_str(piece)))
	{
		if (validate_size(piece_str) == FALSE)
			ft_strdel(&piece_str);
		else
		{
			i = 0;
			start = -1;
			while (i < 19 && start == -1)
				start = piece_start(i++, piece_str);
			if (start == -1)
				ft_strdel(&piece_str);
			else
				piece_str = cut_piece(piece_str, start);
		}
	}
	return (piece_str);
}

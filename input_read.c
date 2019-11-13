/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:33 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/13 16:58:57 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>

int		validate(int fd, char **out)
{
	char	*line;
	char	*piece[4];
	int		piece_count;
	int		i;
	int		j;

	ft_putendl("CCCCCC");

	piece_count = validate_file(fd);

	j = 0;
	while (j < piece_count)
	{
		i = 0;
		while (i < 4)
		{
			get_next_line(fd, &line);
			piece[i++] = line;
		}

		if ((out[j++] = validate_piece(piece)) == NULL)
			return (-1);

		get_next_line(fd, &line);
		ft_strdel(&line);
	}
	return (piece_count);
}

static char	***alloc_3d(char *src[26][4], int x, int y)
{
	char ***out;
	int i;
	int j;

	printf("pf %s\n", src[0][0]);

	i = 0;
	j = 0;
	out = malloc((x + 1) * sizeof(char *));
	if (out)
	{
		while (i <= x)
		{
			out[i] = malloc((y + 1) * sizeof(char *));
			while (j <= y)
			{
				out[i][j] = ft_strcpy(ft_strnew(4), src[i][j]);
				++j;
			}
			j = 0;
			++i;
		}
	}
	return (out);
}

char	***input_read(int fd)
{
	char	*line;
	int		line_count;
	char	*array[26][4];
	int		x = 0;
	int		y = 0;
	int		ret;


	ft_putendl("DDDDDD");
	line_count = 0;
	while (x < 26 && (ret = get_next_line(fd, &line)) > 0)
	{
		array[x][y] = line;
		if (y < 4)
		{
			++y;
		}
		else
		{
			y = 0;
			++x;
		}
	}

	// printf("x = %d\n", x);
	// alloc 3d
	return (alloc_3d(array, x, y));
}

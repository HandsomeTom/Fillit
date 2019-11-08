/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:33 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/08 19:02:38 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>

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

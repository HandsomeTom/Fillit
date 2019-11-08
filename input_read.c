/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:33 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/08 17:58:37 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>

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

	int i = 0;
	int j = 0;
	while (i < 4)
	{
		printf("i = %d\n", i);
		while (j < 4)
		{
			// printf("j = %d\n", j);
			printf("%s\n", array[i][j]);
			++j;
		}
		++i;
		j = 0;
	}


	return (NULL);
}

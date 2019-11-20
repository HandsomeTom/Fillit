/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:33 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/20 18:09:34 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>

int		validate(int fd, char *out[26], char *file)
{
	char	*line;
	char	*piece[4];
	int		piece_count;
	int		i;
	int		j;


	piece_count = validate_file(fd);

	fd = open(file, O_RDONLY);
	j = 0;
	while (j < piece_count)
	{
		i = 0;
		while (i < 4)
		{
			get_next_line(fd, &line);
			piece[i++] = line;
		}

		if ((out[j] = validate_piece(piece)) == NULL)
			return (-1);
		++j;
		get_next_line(fd, &line);
		ft_strdel(&line);
	}
	return (piece_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:32 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/11 12:32:05 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include "get_next_line.h"

/*
** Main should look something like this, probably:
*/

int		main(int argc, char **argv)
{
	int fd;
	char ***array2D;

	if (argc != 2)
	{
		ft_putendl("usage: input_file");
		ft_putendl("       The file should contain 1-26 Tetrimino");
		ft_putendl("       in 4x4 grids, separated by newlines.");
		ft_putendl("       '.' marks an empty space.");
		ft_putendl("       '#' determines the shape of each Tetrimino.");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) > 2)
	{
		if ((array2D = input_read(fd)) != NULL)
		{
			show_output(smallest_square(&array2D));
		}
	}
}

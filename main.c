/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:35 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/13 17:55:54 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	// char	***pieces;
	char	*pieces[26];
	int		piece_count;

	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			piece_count = validate(fd, &pieces, argv[1]);
			// pieces = input_read(fd);

			ft_putendl("????");
			int x = 0;
			while (x < piece_count)
			{
				// printf("%s\n", pieces[x++]);
			}
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:35 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/20 15:38:43 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	// char	***pieces;
	char	*pieces[26];
	int		piece_count;
	t_piece *lst_head;

	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			piece_count = validate(fd, pieces, argv[1]);
			ft_putendl(ft_itoa(piece_count));
			if (piece_count <= 0)
			{
				ft_putendl("ERROR\n");
				return (1);
			}
			// pieces = input_read(fd);

			ft_putendl("TODO: BUILD A LINKED LIST FIRST");
			lst_head = make_piece(pieces[0], 'A');
			int i = 1;
			while (i < piece_count)
			{
				ft_piece_add_back(lst_head, make_piece(pieces[i], 'A' + i));
				++i;
			}

			// why not just 12x12?

			int size = 4;
			char **map = make_grid(size);
			ft_putendl("main"); ft_print2dstr(map, size); ft_putendl("");

			char **solution = smallest_square(map, size, lst_head, 1);
			ft_putendl("final:");
			ft_print2dstr(solution, ft_strlen(solution[0]));

			ft_putendl("wew?");
		}
	}
}

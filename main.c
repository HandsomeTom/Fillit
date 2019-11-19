/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:35 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/19 18:53:04 by tmaarela         ###   ########.fr       */
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
			int i = 0;
			lst_head = make_piece(pieces[0], 'A');
			lst_head->next = make_piece(pieces[1], 'B');
			// t_piece *array[2];
			// array[0] = make_piece(pieces[0], 'A');
			// array[1] = make_piece(pieces[1], 'B');
			// printf("w%s h%s\n",
			// 	ft_itoa(array[0]->width),
			// 	ft_itoa(array[0]->height));
			// printf("w%s h%s\n",
			// 	ft_itoa(array[1]->width),
			// 	ft_itoa(array[1]->height));

			// why not just 12x12?
			int size = 4;
			i = 0;
			char **map = malloc(sizeof(char *) * size);
			while (i < size)
			{
				map[i] = malloc(size + 1);
				ft_memset(map[i++], '.', size);
			}

			ft_putendl("main");
			ft_print2dstr(map, 4);
			ft_putendl("");

			char **solution = smallest_square(map, size, lst_head);

			ft_putendl("segvault?");
		}
	}
}

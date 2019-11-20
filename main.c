/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:35 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/20 18:00:22 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	*pieces[26];
	int		piece_count;
	t_piece *lst_head;

	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			piece_count = validate(fd, pieces, argv[1]);
			if (piece_count <= 0)
			{
				ft_putendl("error");
				return (0);
			}

			lst_head = make_piece(pieces[0], 'A');
			int i = 1;
			while (i < piece_count)
			{
				ft_piece_add_back(lst_head, make_piece(pieces[i], 'A' + i));
				++i;
			}

			solve(lst_head);
		}
	}
}

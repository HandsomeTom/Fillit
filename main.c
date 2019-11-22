/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:35 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/22 15:01:39 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_piece	*build_piece_list(char *pieces[26], int piece_count)
{
	t_piece	*lst_head;
	int		i;

	i = 0;
	lst_head = make_piece(pieces[i], 'A');
	ft_strdel(&pieces[i]);
	while (++i < piece_count)
	{
		ft_piece_add_back(lst_head, make_piece(pieces[i], 'A' + i));
		ft_strdel(&pieces[i]);
	}
	return (lst_head);
}

int				main(int argc, char **argv)
{
	char	*pieces[26];
	int		piece_count;
	int		fd;
	t_piece *lst_head;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			piece_count = validate(fd, pieces, argv[1]);
			if (piece_count < 1)
			{
				ft_putendl("error");
				return (0);
			}
			lst_head = build_piece_list(pieces, piece_count);
			solve(lst_head);
		}
	}
}

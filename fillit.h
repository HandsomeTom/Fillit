/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:09:27 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/22 15:29:54 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct	s_piece
{
	char			letter;
	int				coords[4][4];
	int				width;
	int				height;
	struct s_piece	*next;
}				t_piece;

typedef struct	s_xy
{
	int		x;
	int		y;
}				t_xy;

int				validate(int fd, char **out, char *file);
int				validate_file(int fd);
char			*validate_piece(char *array[4]);

t_piece			*make_piece(char *str, char letter);
void			ft_piece_add_back(t_piece *head, t_piece *new);

void			solve(t_piece *lst);
char			**make_grid(int size);
void			free2d(char **map, int size);

#endif

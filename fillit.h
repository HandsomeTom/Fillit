/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:09:27 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/21 01:12:58 by ngontjar         ###   ########.fr       */
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
int				smallest_square(char **map2d, int size, t_piece *lst);
char			**make_grid(int size);
int				empty(char **map2d, t_xy pos, int size, t_piece *tet);
void			put(char **map2d, t_xy pos, t_piece *tet);
void			rip(char **map2d, t_xy pos, t_piece *tet);
void			free2d(char **map, int size);

#endif

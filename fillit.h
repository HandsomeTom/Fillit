/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:09:27 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/14 13:49:16 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "get_next_line.h"

typedef struct	s_piece
{
	char			c;
	int				x[4];
	int				y[4];
	struct	s_piece	*next;
}				t_piece;

char	***input_read(int fd);
char	**smallest_square(char ***array2D);
void	show_output(char **square);
int		validate(int fd, char **out, char *file);
char	*validate_piece(char *array[4]);
int		validate_file(int fd);
char	**make_piece(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:09:27 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/13 17:42:39 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "get_next_line.h"

char	***input_read(int fd);
char	**smallest_square(char ***array2D);
void	show_output(char **square);
int		validate(int fd, char **out, char *file);
char	*validate_piece(char *array[4]);
int		validate_file(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:40:42 by tmaarela          #+#    #+#             */
/*   Updated: 2019/11/14 13:52:26 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** make_piece(string)
** Stores the information of the piece into a struct s_piece
** in order to have the coordinates and the representing char
** for the solver function
** Example:
** The piece
** .#..
** ###.
** ....
** ....
** Or more accurately, after joining the piece into a single string
** .#..###.........
** would be respresented as
** x[0]y[0] 0
** x[1]y[0] 1
** x[0]y[1] 1
** x[1]y[1] 1
** x[2]y[1] 1
** (all other coords 0)
*/

char	**make_piece(char *str)
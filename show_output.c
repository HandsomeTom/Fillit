/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:12:45 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/11 12:31:04 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	show_output(char **square)
{
	int		row;

	row = 0;
	while (square[row] != NULL)
	{
		ft_putendl(square[row]);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:24:07 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:48 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_piece_add_back(t_piece *head, t_piece *new)
{
	if (head != NULL && new != NULL)
	{
		if (head->next != NULL)
			ft_piece_add_back(head->next, new);
		else
			head->next = new;
	}
}

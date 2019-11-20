/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:34:43 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/20 13:26:42 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *head, t_list *new)
{
	if (head != NULL && new != NULL)
	{
		if (head->next != NULL)
			ft_lstadd_back(head->next, new);
		else
			head->next = new;
	}
}

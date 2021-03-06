/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:37:32 by ngontjar          #+#    #+#             */
/*   Updated: 2019/10/29 20:17:39 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *str)
{
	int length;

	if (dst && str)
	{
		length = ft_strlen(dst);
		ft_strcpy(dst + length, str);
	}
	return (dst);
}

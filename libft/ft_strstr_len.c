/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:00:18 by tmaarela          #+#    #+#             */
/*   Updated: 2019/11/19 19:46:23 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strstr_len(const char *haystack, const char *needle)
{
	size_t	start;
	size_t	i;
	size_t	ret;

	ret = 0;
	if (needle == NULL || needle[0] == '\0')
		return (-1);
	if (haystack != NULL)
	{
		start = 0;
		while (haystack[start])
		{
			i = 0;
			while (needle[i] && haystack[start + i] == needle[i])
				++i;
			if (needle[i] == '\0')
				return (ret);
			++start;
			++ret;
		}
	}
	return (-1);
}

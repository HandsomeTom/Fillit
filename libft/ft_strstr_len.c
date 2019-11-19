/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:00:18 by tmaarela          #+#    #+#             */
/*   Updated: 2019/11/19 18:24:35 by tmaarela         ###   ########.fr       */
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

int main()
{
	char	text1[50] = "Hello darkness my old friend!";
	char	text2[50] = "old";

	printf("%d\n", ft_strstr_len(text1, text2));
	return 0;
}
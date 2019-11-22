/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:16:53 by tmaarela          #+#    #+#             */
/*   Updated: 2019/11/22 13:53:02 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				retmagic(int ret)
{
	if (ret < 225)
		return (ret / 20);
	else
		return (ret / 20.5);
}

static int		file_check(char *str)
{
	int i;
	int row;

	i = 1;
	row = 1;
	while (*str)
	{
		if (*str != '#' && *str != '.' && *str != '\n' && *str != '\0')
			return (-1);
		if (str[1] == '\0' && *str != '\n')
			return (-1);
		if (*str == '\n')
		{
			if (str[1] == '\0' && row % 5 == 0)
				return (-1);
			if ((row % 5 != 0 && i < 5))
				return (-1);
			i = 0;
			row++;
		}
		if (i > 4 || (i++ > 1 && (row % 5 == 0)))
			return (-1);
		str++;
	}
	return (1);
}

int				validate_file(int fd)
{
	int		ret;
	char	*str;

	if (!(str = (char *)malloc(550)))
		return (0);
	while ((ret = read(fd, str, 549)) > 0)
		str[ret] = '\0';
	ret = ft_strlen(str);
	if (!(*str))
		return (-1);
	if (file_check(str) < 0)
		return (-1);
	free(str);
	close(fd);
	return (retmagic(ret));
}

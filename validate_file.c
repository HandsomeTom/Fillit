/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:16:53 by tmaarela          #+#    #+#             */
/*   Updated: 2019/11/12 19:09:13 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

int		retmagic(int ret)
{
	if (ret < 225)
		return (ret / 20);
	else
		return (ret / 20.5);
}

int		validate_piece(int fd)
{
	int		ret;
	int		i;
	int		row;
	char	*str;

	i = 1;
	row = 1;
	if (!(str = (char *)malloc(550)))
		return (0);
	while ((ret = read(fd, str, 549)) > 0)
		str[ret] = '\0';
	ret = ft_strlen(str);
	if (!(*str))
		return (-1);
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
		if (i > 4 || (i > 1 && (row % 5 == 0)))
			return (-1);
		i++;
		str++;
	}
	return (retmagic(ret));
}

int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	printf("RETURN: %d\n", validate_piece(fd));
	return (0);
}

		// printf("%d  ", row);
		// printf("%d  ", i);
		// printf("%c\n", str[0]);
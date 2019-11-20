/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:20:28 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/20 17:39:25 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **make_grid(int size)
{
	int i = -1;
	char	**map = (char **)malloc(sizeof(char **) * size);
	if (map)
	{
		while (++i < size)
		{
			if ((map[i] = ft_strnew(size)) == NULL)
			{
				i = 0;
				while (i < size)
					free(map[i]);
				free(map);
				return (NULL);
			}
			ft_memset(map[i], '.', size);
		}
	}
	return (map);
}


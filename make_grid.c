/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:20:28 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/22 14:42:17 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**make_grid(int size)
{
	int		i;
	char	**map;

	i = -1;
	map = (char **)malloc(sizeof(char **) * size);
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

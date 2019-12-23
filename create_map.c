/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:01:16 by calpha            #+#    #+#             */
/*   Updated: 2019/12/23 12:43:26 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_octothorpe(char *array)
{
	int i;

	i = 0;
	while (*array != '\0')
	{
		if (*array == '#')
			i++;
		array++;
	}
	return (i);
}

char	*create_map(char *array)
{
	static char *matrix;
	int i;
	int a;
	int k;

	i = 0;
	a = ft_sqrt(count_octothorpe(array));
	k = a;
	matrix = (char *)malloc(((a * a + a) + 1) * sizeof(char));
	matrix = ft_memset(matrix, '.', (a * a + a));
	matrix[(a * a + a)] = '\0';
	while (i < a)
	{
		*(matrix + k) = '\n';
		k = k + a + 1;
		i++;
	}
	return (matrix);
}

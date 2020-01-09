/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:01:16 by calpha            #+#    #+#             */
/*   Updated: 2020/01/09 18:07:58 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_size_figure(t_tetramino work_list)
{
	int i;
	int n;
	int m;
	int max_x;
	int max_y;

	i = 0;
	n = 0;
	m = 0;
	max_x = 0;
	max_y = 0;
	while (i < 8)
	{
		if (i % 2 != 0)
			n = work_list.blockcoords[i];
		if (n >= max_x)
			max_x = n;
		if (i % 2 == 0)
			m = work_list.blockcoords[i];
		if (m >= max_y)
			max_y = m;
		i++;
	}
	if (max_x >= max_y)
		return (++max_x);
	else
		return (++max_y);
}

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

char	*create_map(t_tetramino work_list, char *array)
{
	static char *matrix;
	int i;
	int a;
	int b;
	int k;
	int z;

	i = 0;
	z = 0;
	a = ft_sqrt(count_octothorpe(array));
	b = check_size_figure(work_list);
	if (a >= b)
	{
		k = a;
		z = a;
	}
	else
	{
		k = b;
		z = b;
	}
	matrix = (char *)malloc(((z * z + z) + 1) * sizeof(char));
	matrix = ft_memset(matrix, '.', (z * z + z));
	matrix[(z * z + z)] = '\0';
	while (i < z)
	{
		*(matrix + k) = '\n';
		k = k + z + 1;
		i++;
	}
	return (matrix);
}

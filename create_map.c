/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:01:16 by calpha            #+#    #+#             */
/*   Updated: 2020/01/11 18:36:07 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_size_figure(t_tetramino work_list)
{
	int	i;
	int	n;
	int	m;
	int	max_x;
	int	max_y;

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
	i = max_x >= max_y ? ++max_x : ++max_y;
	return (i);
}

static int	count_octothorpe(char *buffer)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '#')
			j++;
		i++;
	}
	return (j);
}

char		*create_map(t_tetramino work_list, char *buffer)
{
	char	*matrix;
	int		i;
	int		k;
	int		z;

	i = 0;
	k = (ft_sqrt(count_octothorpe(buffer)) >= check_size_figure(work_list)) ?
		ft_sqrt(count_octothorpe(buffer)) : check_size_figure(work_list);
	z = k;
	if (!(matrix = (char *)malloc(((z * z + z) + 1) * sizeof(char))))
		return (NULL);
	ft_memset(matrix, '.', (z * z + z));
	matrix[(z * z + z)] = '\0';
	while (i < z)
	{
		*(matrix + k) = '\n';
		k = k + z + 1;
		i++;
	}
	return (matrix);
}

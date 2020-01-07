/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_increase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:08:32 by calpha            #+#    #+#             */
/*   Updated: 2020/01/07 18:18:22 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *map_increase(char *s)
{
	char *matrix;
	int n;
	int k;
	int i;

	n = str_len_slan_n(s);
	n++;
	k = n;
	i = 0;
	matrix = (char *)malloc(((n * n + n) + 1) * sizeof(char));
	matrix = ft_memset(matrix, '.', (n * n + n));
	matrix[(n * n + n)] = '\0';
	while (i < n)
	{
		*(matrix + k) = '\n';
		k = k + n + 1;
		i++;
	}
	return (matrix);
}

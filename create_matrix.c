/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:19:07 by calpha            #+#    #+#             */
/*   Updated: 2019/12/12 17:01:54 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *create_matrix(int a)
{
	char *matrix;
	int i;
	int k;

	i = 0;
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

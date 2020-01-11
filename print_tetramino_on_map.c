/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetramino_on_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:23:13 by calpha            #+#    #+#             */
/*   Updated: 2020/01/11 18:51:57 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_print(t_tetramino *work_list, char *s, int n)
{
	int i;
	int j;
	int k;
	int z;
	int m;

	i = 0;
	j = 0;
	k = 0;
	z = 0;
	m = 0;
	while (s[i] != '\0')
	{
		if (work_list->blockcoords[j] == (z % n))
		{
			j++;
			if (work_list->blockcoords[j] == k)
			{
				if (s[i] != '.')
					break ;
				j++;
				m++;
				if (m == 4)
					return (1);
			}
			else
				j--;
		}
		z++;
		if (s[i] == '\n')
		{
			k++;
			z = 0;
		}
		i++;
	}
	return (0);
}

int			print_tetramino_on_map(t_tetramino *work_list, char *s, int n)
{
	int i;
	int j;
	int k;
	int z;

	i = 0;
	j = 0;
	k = 0;
	z = 0;
	if (check_print(work_list, s, n))
	{
		while (s[i] != '\0')
		{
			if (work_list->blockcoords[j] == (z % n))
			{
				j++;
				if (work_list->blockcoords[j] == k)
				{
					j++;
					s[i] = work_list->letter;
					if (j == 8)
						return (1);
				}
				else
					j--;
			}
			z++;
			if (s[i] == '\n')
			{
				k++;
				z = 0;
			}
			i++;
		}
	}
	return (0);
}

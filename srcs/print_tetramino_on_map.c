/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetramino_on_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:23:13 by calpha            #+#    #+#             */
/*   Updated: 2020/03/10 12:21:58 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_print(t_tetramino *work_list, char *s, int n)
{
	int j;
	int k;
	int z;
	int m;

	j = 0;
	k = 0;
	z = 0;
	m = 0;
	while (*s != '\0')
	{
		if (work_list->blockcoords[j] == (z++ % n))
		{
			if (work_list->blockcoords[++j] == k)
			{
				if (*s != '.')
					break ;
				j++;
				if (++m == 4)
					return (1);
			}
			else
				j--;
		}
		if (*s == '\n')
		{
			k++;
			z = 0;
		}
		s++;
	}
	return (0);
}

int			print_tetramino_on_map(t_tetramino *work_list, char *s, int n)
{
	int j;
	int k;
	int z;

	j = 0;
	k = 0;
	z = 0;
	if (check_print(work_list, s, n))
	{
		while (*s != '\0')
		{
			if (work_list->blockcoords[j] == (z++ % n))
			{
				if (work_list->blockcoords[++j] == k)
				{
					*s = work_list->letter;
					if (++j == 8)
						return (1);
				}
				else
					j--;
			}
			if (*s == '\n')
			{
				k++;
				z = 0;
			}
			s++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetramino_on_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:23:13 by calpha            #+#    #+#             */
/*   Updated: 2020/01/10 01:09:30 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_possible_print_tetramino(t_tetramino *work_list, char *s, int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int z = 0;
	int m = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '.')
		{
			if (work_list->blockcoords[j] == (z % n))
			{
				j++;
				if (work_list->blockcoords[j] == k)
				{
					j++;
					m++;
					if (m == 4)
						return (1);
				}
				else
					j--;
			}
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

int print_tetramino_on_map(t_tetramino *work_list, char *s, int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int z = 0;

	if (check_possible_print_tetramino(work_list, s, n))
	{
		while (s[i] != '\0')
		{
			if (s[i] == '.')
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

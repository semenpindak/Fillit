/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetramino_y.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:42:05 by calpha            #+#    #+#             */
/*   Updated: 2020/01/10 14:15:10 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_difference(t_tetramino *work_list)
{
	int i;
	int difference;
	int min;

	i = 0;
	difference = 0;
	min = 2147483647;
	while (i < 8)
	{
		if (i % 2 == 0)
			difference = work_list->blockcoords[i];
		if (min > difference)
			min = difference;
		i++;
	}
	return (min);
}

int	move_tetramino_y(t_tetramino *work_list)
{
	int i;
	int n;
	int tmpx;
	int tmpy;
	int difference;

	i = 0;
	n = 0;
	difference = check_difference(work_list);
	while (n < 8)
	{
		if (n % 2 == 0)
		{
			tmpx = work_list->blockcoords[i];
			tmpx = tmpx - difference;
			work_list->blockcoords[i] = tmpx;
		}
		if (n % 2 != 0)
		{
			tmpy = work_list->blockcoords[i];
			tmpy++;
			work_list->blockcoords[i] = tmpy;
		}
		i++;
		n++;
	}
	return (11);
}

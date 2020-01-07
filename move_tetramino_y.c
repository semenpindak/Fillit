/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetramino_y.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:42:05 by calpha            #+#    #+#             */
/*   Updated: 2020/01/07 21:10:43 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int move_tetramino_y(t_tetramino *work_list)
{
	int i;
	int n;
	int tmpx;
	int tmpy;
	int difference;

	i = 0;
	n = 0;
	while (n < 8)
	{
		if (n == 0)
			difference = work_list->blockcoords[i];
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

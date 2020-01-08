/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetramino_y.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:42:05 by calpha            #+#    #+#             */
/*   Updated: 2020/01/08 18:36:54 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_difference(t_tetramino *work_list)
{
    int i;
    int difference;
    int min;
    int max;

    i = 0;
    min = 0;
    max = 0;
    difference = 0;
    while (i < 8)
    {
        max = work_list->blockcoords[i];
        if (min < max)
            min = max;
        i++;
    }
	// printf("min=%d\n", min);
    i = 0;
    while (i < 8)
    {
		if (i % 2 == 0)
        	difference = work_list->blockcoords[i];
        if (min > difference)
            min = difference;
        i++;
    }
	// printf("min=%d\n", min);
	return(min);
}


int move_tetramino_y(t_tetramino *work_list)
{
	int i;
	int n;
	int tmpx;
	int tmpy;
	int difference;

	i = 0;
	n = 0;
	difference = check_difference(work_list);
	// printf("dif=%d", difference);
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

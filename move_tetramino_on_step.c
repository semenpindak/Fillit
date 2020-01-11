/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetramino_on_step.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2020/01/11 13:05:58 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_o(t_tetramino *work_list, int n)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (i % 2 != 0)
			if (work_list->blockcoords[i] == n)
			{
				work_list->logic = -1;
				return (-1);
			}
		i++;
	}
	return (10);
}

int check_n(t_tetramino *work_list, int n)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	while (j < 8)
	{
		if (j % 2 == 0)
		{
			tmp = work_list->blockcoords[i];
			tmp++;
			if (tmp == n)
				return (11);
		}
		i++;
		j++;
	}
	return (10);
}

int move_tetramino_on_step(t_tetramino *work_list, int n)
{
	int r;

	if (work_list->logic == -1)
		return(-1);
	r = check_n(work_list, n);
	if (r == 10)
	{
		move_tetramino_x(work_list);
		return (10);
	}
	if (r == 11)
	{
		move_tetramino_y(work_list);
		r = check_o(work_list, n);
		if (r == -1)
			return(-1);
		return(11);
	}
	return (0);
}

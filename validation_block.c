/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:29:23 by calpha            #+#    #+#             */
/*   Updated: 2020/03/13 14:27:05 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	compare_array(t_tetramino *work_list, int *intar, int check)
{
	int i;

	i = -1;
	if (check == 1)
		return (1);
	while (++i < 8)
	{
		if (work_list->blockcoords[i] != intar[i])
			return (0);
	}
	return (1);
}

static int	validation_one_struct(t_tetramino *work_list)
{
	int check;

	check = 0;
	check = compare_array(work_list, IV, check);
	check = compare_array(work_list, IH, check);
	check = compare_array(work_list, QQ, check);
	check = compare_array(work_list, LM, check);
	check = compare_array(work_list, LR, check);
	check = compare_array(work_list, LD, check);
	check = compare_array(work_list, LL, check);
	check = compare_array(work_list, JM, check);
	check = compare_array(work_list, JR, check);
	check = compare_array(work_list, JD, check);
	check = compare_array(work_list, JL, check);
	check = compare_array(work_list, TM, check);
	check = compare_array(work_list, TR, check);
	check = compare_array(work_list, TD, check);
	check = compare_array(work_list, TL, check);
	check = compare_array(work_list, SM, check);
	check = compare_array(work_list, SR, check);
	check = compare_array(work_list, ZM, check);
	check = compare_array(work_list, ZR, check);
	if (check == 0)
		return (0);
	return (1);
}

int			validation_block(t_tetramino *work_list)
{
	int check;

	check = 0;
	while (work_list)
	{
		check = validation_one_struct(work_list);
		if (check == 1)
			work_list = work_list->next;
		else
			return (0);
	}
	return (1);
}

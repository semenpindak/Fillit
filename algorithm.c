/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2020/01/10 11:21:44 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*algorithm(t_tetramino *work_list, char *s)
{
	t_tetramino *head;

	head = work_list;
	int r = 2;
	int l = 0;
	int n;

	n = str_len_slan_n(s);
	while (work_list)
	{
		while (l != -1)
		{
			r = print_tetramino_on_map(work_list, s, n);
			if (r == 1)
			{
				insertion_mark(work_list, r);
				break;
			}
			if (r == 0)
			{
				l = move_tetramino_on_step(work_list, n);
				if (l == -1)
					insertion_mark(work_list, l);
			}
		}
		if (work_list->next == NULL && l != -1)
			break;
		if (work_list->logic == -1 && work_list->letter == 'A')
		{
			s = map_increase(n);
			n++;
			work_list = head;
			zeroing_coordinates(work_list);
			l = 0;
			continue;
		}
		if (work_list->logic == 1)
		{
			work_list = work_list->next;
			zeroing_coordinates(work_list);
			work_list->logic = 0;
		}
		if (work_list->logic == -1)
		{
			work_list = call_previous_tetramino(head);
			work_list->logic = 0;
			clear_print_tetramino(work_list, s);
			move_tetramino_on_step(work_list, n);
			l = 0;
		}
	}
	return (s);
}

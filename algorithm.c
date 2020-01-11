/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2020/01/11 13:07:47 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*algorithm(t_tetramino *work_list, char *s)
{
	t_tetramino	*head;
	int			r;
	int			l;
	int			n;

	int i = 0;
	int ii = 0;
	int iii = 0;
	int iiii = 0;
	int iiiii = 0;
	int zero = 0;


	head = work_list;
	r = 0;
	l = 0;
	n = str_len_slan_n(s);
	while (work_list)
	{
		while (l != -1)
		{
			r = print_tetramino_on_map(work_list, s, n);
			if (r == 1)
			{
				insertion_mark(work_list, r);
				i++;
				break ;
			}
			if (r == 0)
			{
				l = move_tetramino_on_step(work_list, n);
				ii++;
			}
			if (l == -1)
			{
				insertion_mark(work_list, l);
				iii++;
			}
		}
		if (work_list->next == NULL && l != -1)
			break ;
		if (work_list->logic == -1 && work_list->letter == 'A')
		{
			s = map_increase(++n);
			work_list = head;
			zeroing_coordinates(work_list);
			l = 0;
			zero++;
			continue;
		}
		if (work_list->logic == 1)
		{
			work_list = work_list->next;
			zeroing_coordinates(work_list);
			work_list->logic = 0;
			iiii++;
		}
		if (work_list->logic == -1)
		{
			work_list = work_list->prev;
			work_list->logic = 0;
			clear_print_tetramino(work_list, s);
			move_tetramino_on_step(work_list, n);
			l = 0;
			iiiii++;
		}
	}
	printf("print(1)=%d\nprint(0)=%d\nmove=%d\nmove(-)=%d\nmap_increase=%d\nwl->next=%d\nwl->prev=%d", i, ii, ii, iii, zero, iiii, iiiii);
	return (s);
}

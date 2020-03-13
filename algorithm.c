/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2020/03/13 14:50:55 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*algorithm(t_tetramino *work_list, char *s, int n)
{
	t_tetramino	*head;
	int			r;
	int			l;

	head = work_list;
	l = 0;
	while (work_list)
	{
		while (l != -1)
		{
			r = print_tetramino_on_map(work_list, s, n);
			if (r == 1)
			{
				work_list->logic = 1;
				break ;
			}
			if (r == 0)
				l = move_tetramino_on_step(work_list, n);
		}
		if (work_list->next == NULL && l != -1)
			break ;
		if (work_list->logic == -1 && work_list->letter == 'A')
		{
			work_list = head;
			free(s);
			s = map_increase(++n);
			zeroing_coordinates(work_list);
			l = 0;
			continue ;
		}
		if (work_list->logic == 1)
		{
			work_list = work_list->next;
			work_list->logic = 0;
			zeroing_coordinates(work_list);
		}
		if (work_list->logic == -1)
		{
			work_list = work_list->prev;
			work_list->logic = 0;
			clear_print_tetramino(work_list, s);
			move_tetramino_on_step(work_list, n);
			l = 0;
		}
	}
	return (s);
}

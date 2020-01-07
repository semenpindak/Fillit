/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_previous_tetramino.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:24:47 by calpha            #+#    #+#             */
/*   Updated: 2020/01/07 18:10:18 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetramino *call_previous_tetramino(t_tetramino *work_list, t_tetramino *head)
{
	t_tetramino *tmp_head;
	char *string_letter;
	int i;

	tmp_head = head;
	i = 0;
	string_letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (string_letter[i] != '\0')
	{
		if (string_letter[i] == work_list->letter)
			break;
		i++;
	}
	i--;
	while (i)
	{
		tmp_head = tmp_head->next;
		i--;
	}
	return (tmp_head);
}

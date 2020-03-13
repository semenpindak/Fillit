/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:56:06 by calpha            #+#    #+#             */
/*   Updated: 2020/03/13 14:33:36 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			letter_filling(int count)
{
	char	*array_letter;
	int		i;

	array_letter = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = count / 4;
	return (array_letter[i]);
}

static t_tetramino	*get_last(t_tetramino *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void			push_back(t_tetramino *head, char *buffer, int count)
{
	t_tetramino	*last;
	t_tetramino	*tmp;
	int			*blockcoords;

	last = get_last(head);
	tmp = (t_tetramino *)malloc(sizeof(t_tetramino));
	blockcoords = (int *)malloc(8 * sizeof(int));
	tmp->blockcoords = node_filling(buffer, count, blockcoords);
	tmp->logic = 0;
	tmp->letter = letter_filling(count);
	tmp->next = NULL;
	tmp->prev = last;
	last->next = tmp;
}

static void			push(t_tetramino **head, char *buffer, int count)
{
	t_tetramino	*tmp;
	int			*blockcoords;

	tmp = (t_tetramino *)malloc(sizeof(t_tetramino));
	blockcoords = (int *)malloc(8 * sizeof(int));
	tmp->blockcoords = node_filling(buffer, count, blockcoords);
	tmp->logic = 0;
	tmp->letter = letter_filling(count);
	tmp->next = NULL;
	tmp->prev = NULL;
	*head = tmp;
}

t_tetramino			*create_list(char *buffer)
{
	t_tetramino	*list;
	int			i;
	int			count;

	list = NULL;
	i = 0;
	count = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '#')
		{
			count++;
			if (count == 4)
				push(&list, buffer, count);
			if (count % 4 == 0 && count != 4)
				push_back(list, buffer, count);
		}
		i++;
	}
	return (list);
}

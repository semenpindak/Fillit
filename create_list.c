/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:56:06 by calpha            #+#    #+#             */
/*   Updated: 2019/12/20 16:40:26 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *letter_filling(int count)
{
    char *array_letter;
    int i;

    array_letter = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    i = count / 4;
    return (&array_letter[i]);
}

t_tetramino* getLast(t_tetramino *head)
{
    if (head == NULL)
        return NULL;
    while (head->next)
        head = head->next;
    return (head);
}

void pushBack(t_tetramino *head, char *s, int count)
{
    t_tetramino *last;
    t_tetramino *tmp;
    int *blockcoords;

    last = getLast(head);
    tmp = (t_tetramino *)malloc(sizeof(t_tetramino));
    blockcoords = (int*)malloc(8 * sizeof(int));
    tmp->blockcoords = node_filling(s, count);
    tmp->x = tmp->blockcoords[0];
    tmp->y = tmp->blockcoords[1];
    tmp->letter = *letter_filling(count);
    tmp->next = NULL;
    last->next = tmp;
}


void push(t_tetramino **head, char *s, int count)
{
    t_tetramino *tmp;
    int *blockcoords;

    tmp = (t_tetramino*)malloc(sizeof(t_tetramino));
    blockcoords = (int*)malloc(8 * sizeof(int));
    tmp->blockcoords = node_filling(s, count);
    tmp->x = tmp->blockcoords[0];
    tmp->y = tmp->blockcoords[1];
    tmp->letter = *letter_filling(count);
    tmp->next = *head;
    *head = tmp;
}

t_tetramino    *create_list(char *s)
{
    t_tetramino *list;
    int i;
    int count;
    int check;

    list = NULL;
    i = 0;
    count = 0;
    check = 0;
    if (s)
    {
        while (s[i] != '\0')
        {
            if (s[i] == '#')
            {
                count++;
                if (count % 4 == 0)
                  check = 1;
            }
            if (count == 4 && check)
            {
              push(&list, s, count);
              check = 0;
            }
            if (count % 4 == 0 && check)
            {
              pushBack(list, s, count);
              check = 0;
            }
            i++;
        }
    }
    return (list);
}

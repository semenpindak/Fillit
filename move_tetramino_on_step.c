/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetramino_on_step.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2020/01/09 18:24:57 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_o(t_tetramino *work_list, char *s)
{
    int i;
    int n;

    n = str_len_slan_n(s);
    i = 0;
    while (i < 8)
    {
        if (i % 2 != 0)
            if (work_list->blockcoords[i] == n)
                return (-1);
        i++;
    }
    return (10);
}

int check_n(t_tetramino *work_list, char *s)
{
    int i;
    int n;

    n = str_len_slan_n(s);
    i = 0;
    while (i < 8)
    {
        if (i % 2 == 0)
            if (work_list->blockcoords[i] == n)
                return (11);
        i++;
    }
    return (10);
}

int move_tetramino_on_step(t_tetramino *work_list, char *s)
{
    int r;

    r = check_o(work_list, s);
        if (r == -1)
            return(-1);
    move_tetramino_x(work_list);
    r = check_n(work_list, s);
    if (r == 10)
        return (10);
    if (r == 11)
    {
        move_tetramino_y(work_list);
        r = check_o(work_list, s);
        if (r == -1)
            return(-1);
        return(11);
    }
    return (0);
}

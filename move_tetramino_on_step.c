/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetramino_on_step.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2020/01/08 20:07:27 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int count_slash_n(char *s)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (s[i] != '\0')
    {
        if(s[i] == '\n')
            n++;
        i++;
    }
    return (n);
}

int check_slash_null(t_tetramino *work_list, int *coord_o)
{
    // int i = 0;
    // t_tetramino *tmp;
    // tmp = (t_tetramino *)malloc(sizeof(t_tetramino));
    // tmp->blockcoords = (int *)malloc(8 * sizeof(int));
    // while (i < 8)
    // {
    //     tmp->blockcoords[i] = work_list->blockcoords[i];
    //     i++;
    // }
    move_tetramino_y(work_list);
    if (work_list->blockcoords[1] >= coord_o[0])
        return (-1);
    if (work_list->blockcoords[3] >= coord_o[0])
        return (-1);
    if (work_list->blockcoords[5] >= coord_o[0])
        return (-1);
    if (work_list->blockcoords[7] >= coord_o[0])
        return (-1);
    return (1);
}

int check_o(t_tetramino *work_list, int *coord_o)
{
    if (work_list->blockcoords[1] >= coord_o[0])
        return (-1);
    if (work_list->blockcoords[3] >= coord_o[0])
        return (-1);
    if (work_list->blockcoords[5] >= coord_o[0])
        return (-1);
    if (work_list->blockcoords[7] >= coord_o[0])
        return (-1);
    return (1);
}


void fill_coordinate_n(int *coord_n, char *s, int n)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '\n')
        {
            coord_n[j] = i % (n + 1);
            j++;
            coord_n[j] = i / (n + 1);
            j++;
        }
        i++;
    }
}

int check_transfer(t_tetramino *work_list, char *s)
{
    int i;
    int j;
    int n;
    int m;
    int *coord_n;

    n = count_slash_n(s);
    m = str_len_slan_n(s);
    coord_n = (int *)malloc(n * 2 * sizeof(int));
    fill_coordinate_n(coord_n, s, m);

    j = 0;
    while (j < n * 2)
    {
        i = 0;
        while (i < 8)
        {
            if (work_list->blockcoords[i] == coord_n[j])
            {
                i++;
                j++;
                if (work_list->blockcoords[i] == coord_n[j])
                    return (11);
                else
                {
                    i--;
                    j--;
                }
            }
            i = i + 2;
        }
        j = j + 2;
    }
    return (10);
}


int move_tetramino_on_step(t_tetramino *work_list, char *s)
{
    int *coord_o = NULL;
    int n;
    int r = 0;
    int ro = 0;

    n = count_slash_n(s);
    coord_o = (int *)malloc(1 * sizeof(int));
    coord_o[0] = n;
    ro = check_o(work_list, coord_o);
    if (ro == -1)
        return (-1);
    move_tetramino_x(work_list);
    r = check_transfer(work_list, s);

    if (r == -1)
        return (-1);
    if (r == 10)
        return (10);
    if (r == 11)
    {
        if (check_slash_null(work_list, coord_o) == -1)
            return (-1);
        return(11);
    }
    return (0);
}

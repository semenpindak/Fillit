/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetramino_on_step.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2020/01/07 21:10:07 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void copy_struct(t_tetramino *dst, t_tetramino *src)
{
    int i;

    i = 0;
    while (i < 8)
    {
        dst->blockcoords[i] = src->blockcoords[i];
        i++;
    }
}

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

int check_slash_null(t_tetramino *check, int *coord_o)
{
    t_tetramino *tmp;

    tmp = (t_tetramino *)malloc(sizeof(t_tetramino));
    tmp->blockcoords = (int *)malloc(8 * sizeof(int));
    copy_struct(tmp, check);
    move_tetramino_y(tmp);
    if (tmp->blockcoords[1] == coord_o[1])
        return (-1);
    if (tmp->blockcoords[3] == coord_o[1])
        return (-1);
    if (tmp->blockcoords[5] == coord_o[1])
        return (-1);
    if (tmp->blockcoords[7] == coord_o[1])
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

void fill_coordinate_o(int *coord_o, int n)
{
    coord_o[0] = 0;
    coord_o[1] = ++n;
}


int check_transfer(t_tetramino *work_list, char *s)
{
    int i;
    int j;
    // int k = 0;
    int n;
    int m;
    int *coord_n;
    int *coord_o;
    t_tetramino *check;

    n = count_slash_n(s);
    m = str_len_slan_n(s);
    coord_n = (int *)malloc(n * 2 * sizeof(int));
    coord_o = (int *)malloc(2 * sizeof(int));
    check = (t_tetramino *)malloc(sizeof(t_tetramino));
    check->blockcoords = (int *)malloc(8 * sizeof(int));
    fill_coordinate_n(coord_n, s, m);
    fill_coordinate_o(coord_o, n);
    copy_struct(check, work_list);

    move_tetramino_x(check);


    j = 0;
    while (j < n * 2)
    {
        i = 0;
        while (i < 8)
        {

            if (check->blockcoords[i] == coord_n[j])
            {
                i++;
                j++;
                if (check->blockcoords[i] == coord_n[j])
                {
                    if (check_slash_null(check, coord_o) == 1)
                        return (1);
                    else
                        return (-1);
                }
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
    return (0);
}


int move_tetramino_on_step(t_tetramino *work_list, char *s)
{
    int r = 0;

    r = check_transfer(work_list, s);
    if (r == 0)
        return (move_tetramino_x(work_list));
    if (r == 1)
        return(move_tetramino_y(work_list));
    if (r == -1)
        return (-1);
    return (0);
}

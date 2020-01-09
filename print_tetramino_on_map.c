/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetramino_on_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:23:13 by calpha            #+#    #+#             */
/*   Updated: 2020/01/09 17:57:03 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_possible_print_tetromino(t_tetramino *work_list, char *s, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int z = 0;
    int m = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '.')
        {
            if (work_list->blockcoords[j] == (z % n))
            {
                j++;
                if (work_list->blockcoords[j] == k)
                {
                    j++;
                    m++;
                    if (m == 4)
                        return (1);
                }
                else
                    j--;
            }
        }
        z++;
        if (s[i] == '\n')
        {
            k++;
            z = 0;
        }
        i++;
    }
    return (0);
}

int print_tetramino_on_map(t_tetramino *work_list, char *s)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int z = 0;
    int n = 0;

    n = str_len_slan_n(s);
    if (check_possible_print_tetromino(work_list, s, n))
    {
        while (s[i] != '\0')
        {
            if (s[i] == '.')
            {
                if (work_list->blockcoords[j] == (z % n))
                {
                    j++;
                    if (work_list->blockcoords[j] == k)
                    {
                        j++;
                        s[i] = work_list->letter;
                        if (j == 8)
                            return (1);
                    }
                    else
                        j--;
                }
            }
            z++;
            if (s[i] == '\n')
            {
                k++;
                z = 0;
            }
            i++;
        }
    }
    return (0);
}

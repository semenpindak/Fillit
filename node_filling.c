/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_filling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:06:32 by calpha            #+#    #+#             */
/*   Updated: 2020/01/09 17:38:44 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     *move_tetramino_to_zero(int *s)
{
    int i;
    int minx;
    int miny;

    i = 0;
    minx = 4;
    miny = 4;
    while (i < 8)
    {
        if (i % 2 == 0)
        {
            if (minx > s[i])
                minx = s[i];
        }
        else
        {
            if (miny > s[i])
                miny = s[i];
        }
        i++;
    }
    i = 0;
    while (i < 8)
    {
        if (i % 2 == 0)
            s[i] = s[i] - minx;
        else
            s[i] = s[i] - miny;
        i++;
    }
    return(s);
}

int *converting_array_to_coord(char *s)
{
    int *array_coord;
    int i;
    int j;

    i = 0;
    j = 0;
    if (!(array_coord = (int*)malloc(8 * sizeof(int))))
        return (NULL);
    while (s[i] != '\0')
    {
        if (s[i] == '#')
        {
            array_coord[j] = i % 4;
            j++;
            array_coord[j] = i / 4;
            j++;
        }
        if (j == 8)
          break;
        i++;
    }
    array_coord = move_tetramino_to_zero(array_coord);
    return(array_coord);
}

char    *fillit_strsub(char const *s, unsigned int start, size_t len)
{
    size_t    i;
    size_t    j;
    char    *new;

    i = 0;
    j = 0;
    new = NULL;
    if (!s)
        return (NULL);
    if (!(new = (char *)malloc(len + 1)))
        return (NULL);
    while (i < len)
    {
        if (s[start + j] == '\n')
        {
          j++;
          continue;
        }
        new[i] = s[start + j];
        i++;
        j++;
    }
    new[i] = '\0';
    return (new);
}

int *node_filling(char *s, int count)
{
    int i;
    char *tmp;

    i = 21 * (count / 4 - 1);
    tmp = fillit_strsub(s, i, 16);
    return (converting_array_to_coord(tmp));
}

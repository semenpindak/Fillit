/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_filling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:06:32 by calpha            #+#    #+#             */
/*   Updated: 2019/12/20 17:30:01 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*move_octothorpe(int k, char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == '#')
		{
			s[i] = '.';
			s[i - k] = '#';
		}
		i++;
	}
	return (s);
}

char		*move_tetramino_to_zero(char *s)
{
	int i;

	i = 0;
	while (s[i] != '#')
		i++;
	move_octothorpe(i, s);
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
    tmp = move_tetramino_to_zero(tmp);
    return (converting_array_to_coord(tmp));
}

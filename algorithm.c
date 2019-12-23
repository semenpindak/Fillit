/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2019/12/23 17:33:53 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *insert_tetramino_on_map(t_tetramino *work_list, char *s)
{
    int i = 0;
    int j = 0;
    int k = 0;
    printf("1.\n%s\n", s);
    while (s[i] != '\0')
	{
		if (s[i] == '.')
        {
            if (work_list->blockcoords[j] == ((i - k) % 4))
            {
                j++;
                if (work_list->blockcoords[j] == ((i - k) / 4))
                {
                    j++;
                    s[i - k] = work_list->letter;
                }
            }
        }
        if (s[i] == '\n')
            k++;
        i++;
    }
    printf("2.\n%s\n", s);
    return (s);
}


char *algorithm(t_tetramino *work_list, char *s)
{
    static char *sm = NULL;

    // printf("%s\n", s);
    sm = ft_strdup(s);
    while (work_list != NULL)
    {
        sm = insert_tetramino_on_map(work_list, s);
        // printf("%s\n", sm);
        work_list = work_list->next;
        // printf("%s\n", sm);
    }

	return (s);
}

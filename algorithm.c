/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2019/12/20 19:17:16 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *algorithm(t_tetramino *work_list, char *s)
{
	int i = 0;
	int j = 0;
	int *check;

	check = (int *)malloc(8 * sizeof(int));
	while (s[i] != '\0')
	{
		if (s[i] == '.')
        {

            // if (work_list->blockcoords[j] == i % 4)
            // 	j++;
            // if (work_list->blockcoords[j] = i / 4)
            // 	j++;
        }
        // if (j == 8)
        //   break;
        i++;
    }


	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetramino_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:37:07 by calpha            #+#    #+#             */
/*   Updated: 2020/01/11 12:22:36 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	move_tetramino_x(t_tetramino *work_list)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	while (j < 8)
	{
		if (j % 2 == 0)
		{
			tmp = work_list->blockcoords[i];
			tmp++;
			work_list->blockcoords[i] = tmp;
		}
		i++;
		j++;
	}
	return (10);
}

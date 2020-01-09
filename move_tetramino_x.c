/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetramino_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:37:07 by calpha            #+#    #+#             */
/*   Updated: 2020/01/10 00:42:24 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int move_tetramino_x(t_tetramino *work_list)
{
	int i;
	int n;
	int tmp;

	i = 0;
	n = 0;
	while (n < 8)
	{
		if (n % 2 == 0)
		{
			tmp = work_list->blockcoords[i];
			tmp++;
			work_list->blockcoords[i] = tmp;
		}
		i++;
		n++;
	}
	return (10);
}

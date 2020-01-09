/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_mark.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:28:55 by calpha            #+#    #+#             */
/*   Updated: 2020/01/09 14:14:00 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	insertion_mark(t_tetramino *work_list, int mark)
{
	if (mark == -1)
		work_list->logic = -1;
	if (mark == 1)
		work_list->logic = 1;
}

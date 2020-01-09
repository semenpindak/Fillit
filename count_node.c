/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:31:48 by calpha            #+#    #+#             */
/*   Updated: 2020/01/09 13:34:49 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_node(t_tetramino *work_list)
{
	int i;

	i = 0;
	while (work_list != NULL)
	{
		work_list = work_list->next;
		i++;
	}
	return (i);
}

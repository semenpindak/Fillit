/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_print_tetramino.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:01:04 by calpha            #+#    #+#             */
/*   Updated: 2020/01/10 10:38:08 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_print_tetramino(t_tetramino *work_list, char *s)
{
	while (*s != '\0')
	{
		if (work_list->letter == *s)
			*s = '.';
		s++;
	}
}

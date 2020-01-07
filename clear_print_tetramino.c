/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_print_tetramino.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:01:04 by calpha            #+#    #+#             */
/*   Updated: 2020/01/07 18:08:51 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void clear_print_tetramino(t_tetramino *work_list, char *s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (work_list->letter == s[i])
			s[i] = '.';
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_print_tetramino.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:01:04 by calpha            #+#    #+#             */
/*   Updated: 2020/01/10 00:04:39 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_print_tetramino(t_tetramino *work_list, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (work_list->letter == s[i])
			s[i] = '.';
		i++;
	}
}

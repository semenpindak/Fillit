/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino_installation_label.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:28:55 by calpha            #+#    #+#             */
/*   Updated: 2020/01/08 16:32:23 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void tetramino_installation_label(t_tetramino *work_list, int mark)
{
	work_list->logic = mark;
}

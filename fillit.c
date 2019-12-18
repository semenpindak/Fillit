/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:43:46 by calpha            #+#    #+#             */
/*   Updated: 2019/12/18 16:14:09 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int argc, char *argv[])
{
	char buffer[BUFF_SIZE + 1];

	if (argc == 2)
	{
		read(open(argv[1], O_RDONLY), buffer, BUFF_SIZE);
		buffer[BUFF_SIZE] = '\0';
	}
	if (argc != 2)
		ft_putstr("usage\n");

	algoritm(buffer);
	return (0);
}

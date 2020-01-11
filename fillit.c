/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:43:46 by calpha            #+#    #+#             */
/*   Updated: 2020/01/10 14:17:53 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char *argv[])
{
	char		buffer[BUFF_SIZE + 1];
	t_tetramino	*work_list;
	char		*s;

	s = NULL;
	if (argc == 2)
	{
		read(open(argv[1], O_RDONLY), buffer, BUFF_SIZE);
		buffer[BUFF_SIZE] = '\0';
	}
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [file name] source file\n");
		exit(0);
	}
	work_list = create_list(buffer);
	s = create_map(*work_list, buffer);
	s = algorithm(work_list, s);
	ft_putstr(s);
	ft_strdel(&s);
	return (0);
}

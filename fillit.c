/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:43:46 by calpha            #+#    #+#             */
/*   Updated: 2020/01/11 18:31:33 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_fillit(t_tetramino *work_list, char *s)
{
	while (work_list->next != NULL)
	{
		free(work_list->blockcoords);
		work_list = work_list->next;
		free(work_list->prev);
	}
	free(work_list->blockcoords);
	free(work_list);
	work_list = NULL;
	free(s);
	s = NULL;
}

int			main(int argc, char *argv[])
{
	char		buffer[BUFF_SIZE + 1];
	t_tetramino	*work_list;
	char		*s;
	int			read_r;

	if (argc == 2)
	{
		read_r = read(open(argv[1], O_RDONLY), buffer, BUFF_SIZE);
		buffer[read_r] = '\0';
	}
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [file name] source file\n");
		exit(0);
	}
	work_list = create_list(buffer);
	s = algorithm(work_list, create_map(*work_list, buffer));
	ft_putstr(s);
	free_fillit(work_list, s);
	return (0);
}

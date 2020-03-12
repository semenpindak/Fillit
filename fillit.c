/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:43:46 by calpha            #+#    #+#             */
/*   Updated: 2020/03/12 16:04:25 by calpha           ###   ########.fr       */
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
	int			r;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source file [file name]\n");
		exit(0);
	}
	if (argc == 2)
	{
		r = read(open(argv[1], O_RDONLY), buffer, BUFF_SIZE);
		buffer[r] = '\0';
	}
	if (validation(buffer) == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
	work_list = create_list(buffer);
	if (validation_block(work_list) == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
	s = create_map(*work_list, buffer);
	ft_putstr(algorithm(work_list, s, str_len_slan_n(s)));
	free_fillit(work_list, s);
	return (0);
}

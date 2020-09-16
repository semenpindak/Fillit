/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:43:46 by calpha            #+#    #+#             */
/*   Updated: 2020/09/17 01:29:18 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_fillit(t_tetramino *work_list, char *s)
{
	while (work_list->next)
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
	char		buffer[BUFF_SIZE_F + 1];
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
		r = read(open(argv[1], O_RDONLY), buffer, BUFF_SIZE_F);
		if (r > 545)
		{
			ft_putstr("error\n");
			exit(0);
		}
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
	s = algorithm(work_list, s, str_len_slan_n(s));
	ft_putstr(s);
	free_fillit(work_list, s);
	return (0);
}

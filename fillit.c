/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:43:46 by calpha            #+#    #+#             */
/*   Updated: 2020/01/05 17:49:03 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int argc, char *argv[])
{
	char		buffer[BUFF_SIZE + 1];
	t_tetramino	*work_list;
	char *s;
	// int i;

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
	printf("%s", s);



	// printf("%s\n", s);
	// while (work_list->next != NULL)
	// {
	// 	i = 0;
	// 	while (i < 8)
	// 	{
	// 		printf("%d", work_list->blockcoords[i]);
	// 		i++;
	// 	}
	// 	printf("\n");
	// 	printf("%d\n", work_list->x);
	// 	printf("%d\n", work_list->y);
	// 	printf("%c\n", work_list->letter);
	// 	work_list = work_list->next;
	// 	printf("\n");
	// }
	// i = 0;
	// while (i < 8)
	// {
	// 	printf("%d", work_list->blockcoords[i]);
	// 	i++;
	// }
	// printf("\n");
	// printf("%d\n", work_list->x);
	// printf("%d\n", work_list->y);
	// printf("%c\n", work_list->letter);
	// work_list = work_list->next;
	// printf("\n");


	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:43:46 by calpha            #+#    #+#             */
/*   Updated: 2019/12/18 14:10:58 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int argc, char *argv[])
{
	int i;
	char buffer[BUFF_SIZE + 1];
	char *matrix;
	char **ws;
	int j = 0;

	if (argc == 2)
	{
		read(open(argv[1], O_RDONLY), buffer, BUFF_SIZE);
		buffer[BUFF_SIZE] = '\0';
	}
	if (argc != 2)
		ft_putstr("usage\n");

	/*нарезка тетрамино поштучно и помещение их в отдельный массив; смещение терамино в 0,0;*/
	ws = cut_tetramino(buffer);
	ws = move_tetramino_to_zero(ws);

	/*изменение октотропов на буквы, применить ф-цию, когда найдено решение*/
	ws = letter_replacement(ws);


	while (j < 26)
	{
		printf("%s\n", ws[j]);
		j++;
	}

	/*подсчет кол-ва октотропов и взятии корня из этого числа*/
	i = ft_sqrt(count_octothorpe(buffer));
	if (i > 4)
		matrix = create_matrix(i); /*формирование матрицы*/
	else
		matrix = NULL; //дописать


	// printf("%s", matrix);
	return (0);
}

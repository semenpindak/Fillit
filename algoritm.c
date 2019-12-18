/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:04:10 by calpha            #+#    #+#             */
/*   Updated: 2019/12/18 17:47:57 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	algoritm(char *s)
{
	int i = 0;
	// int j = 0;
	char *matrix;
	char **ws;

	ws = cut_tetramino(s);
	ws = move_tetramino_to_zero(ws);

	// // ws = letter_replacement(ws);

	i = ft_sqrt(count_octothorpe(s));
	matrix = create_matrix(i);

	printf("%s", matrix);




	// while (j <= 26)
	// {
	// 	printf("%s\n", ws[j]);
	// 	j++;
	// }
}

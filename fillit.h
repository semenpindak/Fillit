/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:06:23 by calpha            #+#    #+#             */
/*   Updated: 2019/12/18 17:58:58 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h> //не забыть потом удалить

# define BUFF_SIZE 545

typedef struct			s_tetramino
{
	int					blockcoords[8];
	char				letter;
	int					x;
	int					y;
	struct s_tetramino	*next;
}						t_tetramino;

char					**cut_tetramino(char const *s);
char					**move_tetramino_to_zero(char **s);

void					algoritm(char *s);

int						count_octothorpe(char *array);
char					*create_matrix(int a);

char					**letter_replacement(char **s);

#endif

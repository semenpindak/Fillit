/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:06:23 by calpha            #+#    #+#             */
/*   Updated: 2019/12/18 13:06:02 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include <stdio.h> //не забыть потом удалить

# define BUFF_SIZE 545

typedef struct			s_tetramino
{
	unsigned short		form;
	int					x;
	int					y;
	int					nwords;
	unsigned long long	*word;
	struct s_tetramino	*next;
}						t_tetramino;

int						count_octothorpe(char *array);
char					*create_matrix(int a);
char					**cut_tetramino(char const *s);
char					**move_tetramino_to_zero(char **s);
char					**letter_replacement(char **s);
char					*algoritm(char **tetramino_slicing, const char *matrix);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:06:23 by calpha            #+#    #+#             */
/*   Updated: 2020/01/05 20:43:16 by calpha           ###   ########.fr       */
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
	int					*blockcoords;
	int					x;
	int					y;
	char				letter;
	struct s_tetramino	*next;
}						t_tetramino;

t_tetramino				*create_list(char *s);
int						*node_filling(char *s, int count);
char					*create_map(t_tetramino work_list, char *array);
char					*algorithm(t_tetramino *t, char *s);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:06:23 by calpha            #+#    #+#             */
/*   Updated: 2020/01/11 12:22:16 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "stdio.h"

# define BUFF_SIZE 545

typedef struct			s_tetramino
{
	int					*blockcoords;
	int					logic;
	char				letter;
	struct s_tetramino	*next;
	struct s_tetramino	*prev;
}						t_tetramino;

t_tetramino				*create_list(char *s);
int						*node_filling(char *s, int count);
char					*create_map(t_tetramino work_list, char *array);
char					*map_increase(int n);
char					*algorithm(t_tetramino *t, char *s);
t_tetramino				*zeroing_coordinates(t_tetramino *work_list);
void					clear_print_tetramino(t_tetramino *work_list, char *s);
int						str_len_slan_n(char *s);
void					insertion_mark(t_tetramino *work_list, int mark);
int						print_tetramino_on_map(t_tetramino *work_list, char *s, int n);
int						move_tetramino_on_step(t_tetramino *work_list, int n);
int						move_tetramino_x(t_tetramino *work_list);
int						move_tetramino_y(t_tetramino *work_list);
#endif

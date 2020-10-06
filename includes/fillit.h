/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:06:23 by calpha            #+#    #+#             */
/*   Updated: 2020/10/06 12:25:21 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../Libft/includes/libft.h"

# define BUFF_SIZE_F 546

# define IV (int[8]) {0, 0, 0, 1, 0, 2, 0, 3}
# define IH (int[8]) {0, 0, 1, 0, 2, 0, 3, 0}

# define QQ (int[8]) {0, 0, 1, 0, 0, 1, 1, 1}

# define LM (int[8]) {0, 0, 0, 1, 0, 2, 1, 2}
# define LR (int[8]) {0, 0, 1, 0, 2, 0, 0, 1}
# define LD (int[8]) {0, 0, 1, 0, 1, 1, 1, 2}
# define LL (int[8]) {2, 0, 0, 1, 1, 1, 2, 1}

# define JM (int[8]) {1, 0, 1, 1, 0, 2, 1, 2}
# define JR (int[8]) {0, 0, 0, 1, 1, 1, 2, 1}
# define JD (int[8]) {0, 0, 1, 0, 0, 1, 0, 2}
# define JL (int[8]) {0, 0, 1, 0, 2, 0, 2, 1}

# define TM (int[8]) {1, 0, 0, 1, 1, 1, 2, 1}
# define TR (int[8]) {0, 0, 0, 1, 1, 1, 0, 2}
# define TD (int[8]) {0, 0, 1, 0, 2, 0, 1, 1}
# define TL (int[8]) {1, 0, 0, 1, 1, 1, 1, 2}

# define SM (int[8]) {1, 0, 2, 0, 0, 1, 1, 1}
# define SR (int[8]) {0, 0, 0, 1, 1, 1, 1, 2}

# define ZM (int[8]) {0, 0, 1, 0, 1, 1, 2, 1}
# define ZR (int[8]) {1, 0, 0, 1, 1, 1, 0, 2}

typedef struct			s_tetramino
{
	int					*blockcoords;
	int					logic;
	char				letter;
	struct s_tetramino	*next;
	struct s_tetramino	*prev;
}						t_tetramino;

int						validation(char *s);
int						validation_block(t_tetramino *work_list);
t_tetramino				*create_list(char *s);
int						*node_filling(char *s, int count, int *blockcoords);
char					*create_map(t_tetramino work_list, char *array);
char					*map_increase(int n);
char					*algorithm(t_tetramino *t, char *s, int n);
t_tetramino				*zeroing_coordinates(t_tetramino *work_list);
void					clear_print_tetramino(t_tetramino *work_list, char *s);
int						str_len_slan_n(char *s);
int						print_tetramino_on_map(t_tetramino *work_list,
						char *s, int n);
int						move_tetramino_on_step(t_tetramino *work_list, int n);
int						move_tetramino_x(t_tetramino *work_list);
int						move_tetramino_y(t_tetramino *work_list);
#endif

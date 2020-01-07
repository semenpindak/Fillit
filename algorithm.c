/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2020/01/07 21:13:20 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *algorithm(t_tetramino *work_list, char *s)
{
    t_tetramino *head;
    char *sm = NULL;
    sm = ft_strdup(s);
    head = work_list;
    int r = 1;

    print_tetramino_on_map(work_list, sm);
    // work_list = work_list->next;
    // print_tetramino_on_map(work_list, sm);
    r = move_tetramino_on_step(work_list, sm);
    // sm = ft_strdup(s);
    printf("%d\n", r);
    print_tetramino_on_map(work_list, sm);
r = move_tetramino_on_step(work_list, sm);
// sm = ft_strdup(s);
printf("%d\n", r);
r = move_tetramino_on_step(work_list, sm);
printf("%d\n", r);
print_tetramino_on_map(work_list, sm);
    // move_tetramino_on_step(work_list, s);




    return (sm);
}

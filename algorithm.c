/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2020/01/08 20:07:36 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *algorithm(t_tetramino *work_list, char *s)
{
    t_tetramino *head;
    char *sm = NULL;
    sm = ft_strdup(s);
    head = work_list;
    // int r = 1;

    printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    sm = ft_strdup(s);
    printf("m=%d ", move_tetramino_on_step(work_list, sm));
    printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    sm = ft_strdup(s);
    printf("m=%d ", move_tetramino_on_step(work_list, sm));
    printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    sm = ft_strdup(s);
    printf("m=%d ", move_tetramino_on_step(work_list, sm));
    printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    int k = 0;
    while (k < 8)
    {
        printf("%d ", work_list->blockcoords[k]);
        k++;
    }
    printf("\n");
    sm = ft_strdup(s);
    printf("m=%d ", move_tetramino_on_step(work_list, sm));
    printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    k = 0;
    while (k < 8)
    {
        printf("%d ", work_list->blockcoords[k]);
        k++;
    }
    printf("\n");

    sm = ft_strdup(s);
    printf("m=%d ", move_tetramino_on_step(work_list, sm));
    printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    k = 0;
    while (k < 8)
    {
        printf("%d ", work_list->blockcoords[k]);
        k++;
    }
    printf("\n");

    // sm = ft_strdup(s);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    //     sm = ft_strdup(s);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    //     sm = ft_strdup(s);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    //     sm = ft_strdup(s);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // int k = 0;
    // while (k < 8)
    // {
    //     printf("%d ", work_list->blockcoords[k]);
    //     k++;
    // }
    // printf("\n");

    //         sm = ft_strdup(s);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // k = 0;
    // while (k < 8)
    // {
    //     printf("%d ", work_list->blockcoords[k]);
    //     k++;
    // }
    // printf("\n");

    // tetramino_installation_label(work_list, r);
    // printf("logic=%d\n", work_list->logic);
    // work_list = work_list->next;
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", r = move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // tetramino_installation_label(work_list, r);
    // printf("logic=%d\n", work_list->logic);

    // work_list = work_list->next;
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", r = move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", r = move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", r = move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", r = move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // tetramino_installation_label(work_list, r);
    // printf("logic=%d\n", work_list->logic);

    // work_list = call_previous_tetramino(head);
    // clear_print_tetramino(work_list, sm);
    // printf("%c\n", work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    // work_list = work_list->next;
    // zeroing_coordinates(work_list);
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    // work_list = call_previous_tetramino(head);
    // clear_print_tetramino(work_list, sm);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    // work_list = work_list->next;
    // zeroing_coordinates(work_list);
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    // work_list = call_previous_tetramino(head);
    // clear_print_tetramino(work_list, sm);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    // work_list = call_previous_tetramino(head);
    // clear_print_tetramino(work_list, sm);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // sm = map_increase(sm);
    // work_list = head;
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // work_list = work_list->next;
    // work_list = zeroing_coordinates(work_list);
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // work_list = work_list->next;
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // work_list = work_list->next;
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    //     // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);
    //     // printf("m=%d ", move_tetramino_on_step(work_list, sm));
    // // printf("p=%d %c\n", print_tetramino_on_map(work_list, sm), work_list->letter);

    return (sm);
}

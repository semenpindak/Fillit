/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2019/12/27 15:50:31 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_transfer(t_tetramino *work_list, int j, int si)
{
    int tmp;

    tmp = work_list->blockcoords[j - 3];
    printf ("check tmp = %d ", tmp);
    tmp++;
    printf ("j = %d ", j);
    printf ("check si = %d ", si);
    printf ("check tmp++ = %d\n", tmp);
    if (si == tmp)
        return (1);
    else
        return (0);
}


void move_tetramino_on_step(t_tetramino *work_list, char *s)
{
    int i = 0;
    int j = 0;
    int m = 0;
    int si = 0;
    int k = 0;
    int tmp;
    int tmpx;
    int tmpy;
    int raznica = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '\n')
        {
            k = i + 1;
            si = i % k;
            break;
        }
        i++;
    }

    j = 0;
    while (j < 8)
    {
        if ((j % 2) != 0)
        {
            if ((work_list->blockcoords[j] - work_list->blockcoords[j - 2]) == 1)
            {
                // printf ("j = %d\n", j);
                break;
            }
        }
        j++;
    }

    k = 0;
    while (k < 8)
    {
        printf("%d ", work_list->blockcoords[k]);
        k++;
    }
    printf("\n");

    if (check_transfer(work_list, j, si) == 0)
    {
        j = 0;
        m = 0;
        while (m < 8)
        {
            if (m % 2 == 0)
            {
                tmp = work_list->blockcoords[j];
                tmp++;
                work_list->blockcoords[j] = tmp;
            }
            j++;
            m++;
        }
    }

    k = 0;
    while (k < 8)
    {
        printf("%d ", work_list->blockcoords[k]);
        k++;
    }
    printf("\n");

    if (check_transfer(work_list, j, si) == 1)
    {
        j = 0;
        m = 0;
        while (m < 8)
        {
            if (m == 0)
                raznica = work_list->blockcoords[j];
            if (m % 2 == 0)
            {
                tmpx = work_list->blockcoords[j];
                tmpx = tmpx - raznica;
                work_list->blockcoords[j] = tmpx;
            }
            if (m % 2 != 0)
            {
                tmpy = work_list->blockcoords[j];
                tmpy++;
                work_list->blockcoords[j] = tmpy;
            }
            j++;
            m++;
        }
    }

    k = 0;
    while (k < 8)
    {
        printf("%d ", work_list->blockcoords[k]);
        k++;
    }
    printf("\n");

}

int insert_tetramino_on_map(t_tetramino *work_list, char *s)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int getup;
    int a;
    int z = 0;
     while (s[i] != '\0')
    {
        if (s[i] == '.')
        {
            a = (z % 4);
            if (work_list->blockcoords[j] == a)
            {
                j++;
                if (work_list->blockcoords[j] == k)
                {
                    j++;
                    s[i] = work_list->letter;
                }
            }
        }
        z++;
        if (s[i] == '\n')
        {
            k++;
            z = 0;
        }
        i++;
        if (j == 8)
            getup = 0;
        else
            getup = 1;
    }
    return (getup);
}


char *algorithm(t_tetramino *work_list, char *s)
{
    // int k = 0;
    static char *sm = NULL;
    // int n = 0;
    // printf("%s\n", s);
    sm = ft_strdup(s);
    // while (work_list != NULL)
    // {
        insert_tetramino_on_map(work_list, sm);
        printf("1.\n%s\n", sm);

        move_tetramino_on_step(work_list, sm);
        sm = ft_strdup(s);
        insert_tetramino_on_map(work_list, sm);
        printf("2.\n%s\n", sm);

        move_tetramino_on_step(work_list, sm);
        sm = ft_strdup(s);
        insert_tetramino_on_map(work_list, sm);
        printf("3.\n%s\n", sm);

        move_tetramino_on_step(work_list, sm);
        sm = ft_strdup(s);
        insert_tetramino_on_map(work_list, sm);
        printf("4.\n%s\n", sm);

        // work_list = work_list->next;

        // insert_tetramino_on_map(work_list, sm);
        // printf("\n2.\n%s\n", sm);
    //     while (k < 8)
    // {
    //     printf("%d ", work_list->blockcoords[k]);
    //     k++;
    // }
// printf("\n");
        // move_tetramino_on_step(work_list, sm);
    //     k =0;
    //     while (k < 8)
    // {
    //     printf("%d ", work_list->blockcoords[k]);
    //     k++;
    // }
        // printf("\n");
        // insert_tetramino_on_map(work_list, sm);
        // printf("\n3.\n%s\n", sm);


    // }

	return (s);
}

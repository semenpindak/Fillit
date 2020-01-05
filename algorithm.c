/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:56:29 by calpha            #+#    #+#             */
/*   Updated: 2020/01/05 20:43:29 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int count_slash_n(char *s)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (s[i] != '\0')
    {
        if(s[i] == '\n')
            n++;
        i++;
    }
    return (n);
}

int move_start_down_string(int *check_trans, int *checko)
{
    int i = 0;
    int m = 0;
    int *tmp;
    int tmpx = 0;
    int tmpy = 0;
    int raznica = 0;
    tmp = (int *)malloc(8 * sizeof(int));

    i = 0;
    while (i < 8)
    {
        tmp[i] = check_trans[i];
        i++;
    }
    // printf("%d %d %d %d %d %d %d %d\n", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], tmp[6], tmp[7]);

    i = 0;
        while (m < 8)
        {
            if (m == 0)
                raznica = tmp[i];
            if (m % 2 == 0)
            {
                tmpx = tmp[i];
                tmpx = tmpx - raznica;
                tmp[i] = tmpx;
            }
            if (m % 2 != 0)
            {
                tmpy = tmp[i];
                tmpy++;
                tmp[i] = tmpy;
            }
            i++;
            m++;
        }
        // printf("%d %d %d %d %d %d %d %d\n", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], tmp[6], tmp[7]);
        // printf("%d %d \n", checko[0], checko[1]);
        if (tmp[1] == checko[1])
            return (-1);
        if (tmp[3] == checko[1])
            return (-1);
        if (tmp[5] == checko[1])
            return (-1);
        if (tmp[7] == checko[1])
            return (-1);
        return (1);
}

int check_transfer(t_tetramino *work_list, char *s)
{
    int i;
    int j;
    // int k = 0;
    int n;
    int m = 0;
    int tmp;
    int *coord_n;
    int *coord_terminate;
    int *check_trans;

    i = 0;
    j = 0;
    n = count_slash_n(s);
    coord_n = (int *)malloc(n * 2 * sizeof(int));
    coord_terminate = (int *)malloc(2 * sizeof(int));
    check_trans = (int *)malloc(8 * sizeof(int));
    while (s[i] != '\0')
    {
        if (s[i] == '\n')
        {
            coord_n[j] = i % 4;
            j++;
            coord_n[j] = i / 4;
            j++;
        }
        i++;
    }
    j = 0;
    if (s[i] == '\0')
    {
        coord_terminate[j] = i % 4;
        j++;
        coord_terminate[j] = i / 4;
    }

    i = 0;
    while (i < 8)
    {
        check_trans[i] = work_list->blockcoords[i];
        i++;
    }

    i = 0;
    while (m < 8)
    {
        if (m % 2 == 0)
        {
            tmp = check_trans[i];
            tmp++;
            check_trans[i] = tmp;
        }
        i++;
        m++;
    }

    // printf("%d %d %d %d %d %d %d %d\n", check_trans[0], check_trans[1], check_trans[2], check_trans[3], check_trans[4],check_trans[5], check_trans[6], check_trans[7]);

    j = 0;
    while (j < n * 2)
    {
        i = 0;
        while (i < 8)
        {

            if (check_trans[i] == coord_n[j])
            {
                i++;
                j++;
                if (check_trans[i] == coord_n[j])
                {
                    if (move_start_down_string(check_trans, coord_terminate) == 1)
                        return (1);
                    else
                        return (-1);
                }
                else
                {
                    i--;
                    j--;
                }
            }
            i = i + 2;
        }
        j = j + 2;
    }
    return (0);
}


int move_tetramino_on_step(t_tetramino *work_list, char *s)
{
    int i = 0;
    int m = 0;
    // int k = 0;
    int tmp;
    int tmpx;
    int tmpy;
    int raznica = 0;
    int r = 0;

    // k = 0;
    // while (k < 8)
    // {
    //     printf("%d ", work_list->blockcoords[k]);
    //     k++;
    // }
    // printf("\n");
    r = check_transfer(work_list, s);
    if (r == 0)
    {
        while (m < 8)
        {
            if (m % 2 == 0)
            {
                tmp = work_list->blockcoords[i];
                tmp++;
                work_list->blockcoords[i] = tmp;
            }
            i++;
            m++;
        }
        return (1);
    }
    if (r == 1)
    {
        while (m < 8)
        {
            if (m == 0)
                raznica = work_list->blockcoords[i];
            if (m % 2 == 0)
            {
                tmpx = work_list->blockcoords[i];
                tmpx = tmpx - raznica;
                work_list->blockcoords[i] = tmpx;
            }
            if (m % 2 != 0)
            {
                tmpy = work_list->blockcoords[i];
                tmpy++;
                work_list->blockcoords[i] = tmpy;
            }
            i++;
            m++;
        }
        return (1);
    }
    if (r == -1)
        return (-1);
    return (0);


}

int insert_tetramino_on_map(t_tetramino *work_list, char *s)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int z = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '.')
        {
            if (work_list->blockcoords[j] == (z % 4))
            {
                j++;
                if (work_list->blockcoords[j] == k)
                {
                    j++;
                    s[i] = work_list->letter;
                }
                else
                    j--;
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
            return (1);
    }
    return (0);
}


char *algorithm(t_tetramino *work_list, char *s)
{
    char *sm = NULL;
    sm = ft_strdup(s);
    int r = 0;
    int rm = 0;

    // while (r != 1)
    // {
    //     r = insert_tetramino_on_map(work_list, sm);
    //     printf("r=%d", r);
    //     if (r == 1)
    //     {
    //         if (work_list->next != NULL)
    //         {
    //             work_list = work_list->next;
    //             r = 0;
    //         }
    //     }
    //     if (r == 0)
    //         rm  = move_tetramino_on_step(work_list, sm);
    //     if (rm == -1)
    //         break;
    // }


	return (sm);
}

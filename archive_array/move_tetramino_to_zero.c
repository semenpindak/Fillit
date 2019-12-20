/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetramino_to_zero.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:50:22 by calpha            #+#    #+#             */
/*   Updated: 2019/12/18 12:55:06 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**move_octothorpe(int i, char *s[], int k)
{
	int j;

	j = 0;
	while(s[i][j] != '\0')
	{
		if (s[i][j] == '#')
		{
			s[i][j] = '.';
			s[i][j - k] = '#';
		}
		j++;
	}
	return (s);
}

char		**move_tetramino_to_zero(char **s)
{
	int i;
	int j;
	int k;

	i = 0;
	while (s[i] != NULL)
	{
		j = 0;
		k = 0;
		while(s[i][j] != '#')
		{
			k++;
			j++;
		}
		j = 0;
		if (k != 0)
			move_octothorpe(i, s, k);
		i++;
	}
	return(s);
}

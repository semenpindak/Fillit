/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_filling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:06:32 by calpha            #+#    #+#             */
/*   Updated: 2020/01/11 18:48:01 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	*rec_new_coordinate(int *array_coord, int minx, int miny)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
			array_coord[i] = array_coord[i] - minx;
		else
			array_coord[i] = array_coord[i] - miny;
		i++;
	}
	return (array_coord);
}

static int	*move_tetramino_to_zero(int *array_coord)
{
	int i;
	int minx;
	int miny;

	i = 0;
	minx = 4;
	miny = 4;
	while (i < 8)
	{
		if (i % 2 == 0)
		{
			if (minx > array_coord[i])
				minx = array_coord[i];
		}
		else
		{
			if (miny > array_coord[i])
				miny = array_coord[i];
		}
		i++;
	}
	array_coord = rec_new_coordinate(array_coord, minx, miny);
	return (array_coord);
}

static int	*converting_array_to_coord(char *new_s, int *array_coord)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (new_s[i] != '\0')
	{
		if (new_s[i] == '#')
		{
			array_coord[j] = i % 4;
			j++;
			array_coord[j] = i / 4;
			j++;
		}
		if (j == 8)
			break ;
		i++;
	}
	free(new_s);
	array_coord = move_tetramino_to_zero(array_coord);
	return (array_coord);
}

static char	*fillit_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	new = NULL;
	if (!s)
		return (NULL);
	if (!(new = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		if (s[start + j] == '\n')
		{
			j++;
			continue ;
		}
		new[i] = s[start + j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

int			*node_filling(char *s, int count, int *blockcoords)
{
	int		i;
	char	*tmp;

	i = 21 * (count / 4 - 1);
	tmp = fillit_strsub(s, i, 16);
	return (converting_array_to_coord(tmp, blockcoords));
}

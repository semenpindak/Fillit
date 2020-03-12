/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:51:28 by calpha            #+#    #+#             */
/*   Updated: 2020/03/12 19:00:14 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_character(char *s)
{
	while (*s != '\0')
	{
		if (*s != '#' && *s != '.' && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}

static int	check_line_length(char *s)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (*s != '\0')
	{
		if (*s == '\n' && x == 4)
		{
			y++;
			x = 0;
			s++;
			if (*s == '\0' && y == 4)
				return (1);
			if (*s != '\n' && y == 4)
				return (0);
			if (*s == '\n')
			{
				s++;
				if (y != 4)
					return (0);
				y = 0;
			}
		}
		x++;
		s++;
	}
	return (0);
}

static int	check_number_octothorpe(char *s)
{
	int j;
	int k;
	int z;
	int n;

	j = 0;
	k = 0;
	z = 1;
	n = 1;
	while (*s != '\0')
	{
		if (*s == '#')
			j++;
		if ((n % (20 * z + k)) == 0)
		{
			k++;
			z++;
		}
		n++;
		s++;
	}
	if ((double)(j / k) != 4)
		return (0);
	return (1);
}

int			validation(char *s)
{
	if ((check_character(s)) == 0)
		return (0);
	if ((check_line_length(s)) == 0)
		return (0);
	if ((check_number_octothorpe(s)) == 0)
		return (0);
	return (1);
}

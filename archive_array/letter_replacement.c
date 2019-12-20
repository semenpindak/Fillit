/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_replacement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:00:11 by calpha            #+#    #+#             */
/*   Updated: 2019/12/20 12:30:39 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**letter_replacement(char **s)
{
	char *letter;
	int i;
	int j;

	i = 0;
	letter = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (s[i] != NULL)
	{
		j = 0;
		while(s[i][j] != '\0')
		{
			if (s[i][j] == '#')
				s[i][j] = letter[i];
			j++;
		}
		i++;
	}
	return (s);
}

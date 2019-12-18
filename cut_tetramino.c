/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_tetramino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:56:06 by calpha            #+#    #+#             */
/*   Updated: 2019/12/17 14:44:48 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	word_count(char const *s)
{
	int n_words;
	int inword;

	n_words = 0;
	inword = 0;
	while (*s != '\0')
	{
		if (*s == '\n')
			inword++;
		if (*s == '\n' && inword == 4)
		{
			s++;
			if (*s == '\n')
			{
				n_words++;
				inword = 0;
			}
			if (*s == '\0')
			{
				n_words++;
				break;
			}
		}
		s++;
	}
	return (n_words);
}

static void	clear(char **aop, int i)
{
	int n;

	n = 0;
	while (i >= n)
	{
		free(aop[i]);
		aop[i] = NULL;
		i--;
	}
	free(aop);
	aop = NULL;
}

static char	**fill_string_array(char **aop, char const *s, int i)
{
	int j;
	int count;

	j = 0;
	count = 0;
	while (*s != '\0')
	{
		aop[i][j] = *s;
		if (*s == '\n')
			count++;
		if (*s == '\n' && count == 4)
		{
			s++;
			if (*s == '\n' || *s == '\0')
			{
				j++;
				aop[i][j] = '\0';
				break;
			}
		}
		s++;
		j++;
	}
	return (aop);
}

static char	**create_str_array(char **aop, char const *s, int n_words)
{
	int i;
	int n_letters;
	int count;

	i = 0;
	while (i < n_words)
	{
		count = 0;
		n_letters = 0;
		while (*s != '\0')
		{
			n_letters++;
			if (*s == '\n')
				count++;
			if (*s == '\n' && count == 4)
			{
				s++;
				if (*s == '\n' || *s == '\0')
					break;
			}
			s++;
		}
		if (!(aop[i] = (char *)malloc((n_letters + 1) * sizeof(char))))
		{
			if (i > 0)
				clear(aop, i - 1);
		}
		else
		{
			s = s - n_letters;
			fill_string_array(aop, s, i);
			i++;
		}
		s = s + n_letters + 1;
	}
	return (aop);
}

char		**cut_tetramino(char const *s)
{
	char	**aop;
	int		n_words;

	aop = NULL;
	n_words = 0;
	if (s)
	{
		n_words = word_count(s);
		if ((aop = (char **)malloc((n_words + 1) * sizeof(char *))))
		{
			aop[n_words] = NULL;
			aop = create_str_array(aop, s, n_words);
		}
	}
	return (aop);
}

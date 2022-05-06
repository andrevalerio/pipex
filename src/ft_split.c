/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 23:03:03 by avalerio          #+#    #+#             */
/*   Updated: 2022/02/13 15:45:53 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_wds(char const *str, char c)
{
	int	words;
	int	is_word;

	words = 0;
	is_word = 0;
	while (*str)
	{
		if (*str == c)
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			words++;
		}
		str++;
	}
	return (words);
}

static int	w_len(char const *str, char c)
{
	int	length;

	length = 0;
	while (*str != c && *str)
	{
		length++;
		str++;
	}
	return (length);
}

static void	*ft_free(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

static void	wds_gen(char **wds, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			wds[i] = (char *)malloc(sizeof(char) * (w_len(s, c) + 1));
			if (wds[i] == NULL)
			{
				ft_free(wds);
				break ;
			}
			while (*s && *s != c)
				wds[i][j++] = (char)*s++;
			wds[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	wds[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**wds;

	wds = (char **)malloc(sizeof(char *) * (count_wds(s, c) + 1));
	if (!s || wds == NULL)
		return (NULL);
	wds_gen(wds, s, c);
	if (wds != NULL)
		return (wds);
	return (NULL);
}

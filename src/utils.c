/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:45:26 by avalerio          #+#    #+#             */
/*   Updated: 2022/02/20 19:21:37 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0' && i + j < len)
			j++;
		if (j == ft_strlen(needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(dup + i) = *(s + i);
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len && *(s + start) != '\0')
	{
		*(new + i) = *(s + start);
		i++;
		start++;
	}
	*(new + i) = '\0';
	return (new);
}

char	*path_join(char *path, char *cmd)
{
	char	*fullpath;
	int		i;
	int		j;

	fullpath = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	i = 0;
	j = 0;
	while (path[j])
		fullpath[i++] = path[j++];
	fullpath[i++] = '/';
	j = 0;
	while (cmd[j])
		fullpath[i++] = cmd[j++];
	fullpath[i] = '\0';
	return (fullpath);
}

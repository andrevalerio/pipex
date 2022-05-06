/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:26:54 by avalerio          #+#    #+#             */
/*   Updated: 2022/03/06 00:03:12 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

/*
** main.c
*/
void	pipexf(char *cmd, char **envp);
void	execute(char *cmd, char **envp);
char	*read_path(char *cmd, char **envp);
char	*get_path(char **envp);
/*
** ft_split.c
*/
char	**ft_split(char const *s, char c);
/*
** utils.c
*/
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*path_join(char *path, char *cmd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 02:09:12 by avalerio          #+#    #+#             */
/*   Updated: 2022/03/06 00:38:36 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	char	*fullpath;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		fullpath = ft_strnstr(envp[i], "PATH=", 10);
		if (fullpath != NULL)
			return (fullpath);
		i++;
	}
	return (NULL);
}

char	*read_path(char *cmd, char **envp)
{
	char	*fullpath;
	char	**my_paths;
	char	*path_cmd;
	int		i;

	fullpath = get_path(envp);
	fullpath = ft_substr(fullpath, 5, 1000);
	my_paths = ft_split(fullpath, ':');
	free(fullpath);
	i = 0;
	while (my_paths[i] != NULL)
	{
		path_cmd = path_join(my_paths[i], cmd);
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		free(my_paths[i]);
		i++;
	}
	free(my_paths);
	return (cmd);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (*args[0] == '/')
		path = args[0];
	else
		path = read_path(args[0], envp);
	execve(path, args, envp);
	write(STDERR_FILENO, "pipex: ", 7);
	write(STDERR_FILENO, args[0], ft_strlen(args[0]));
	write(STDERR_FILENO, ": command not found\n", 20);
	exit(EXIT_FAILURE);
}

void	pipexf(char *cmd, char **envp)
{
	pid_t	id;
	int		end[2];

	if (pipe(end) == -1)
		return (perror("Pipe:"));
	id = fork();
	if (id < 0)
		return (perror("Fork:"));
	if (id)
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		waitpid(id, NULL, 0);
	}
	else
	{
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		execute(cmd, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc != 5)
		write(1, "pipex: invalid number of arguments\n", 35);
	else
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd1 == -1 || fd2 == -1)
		{
			perror("pipex");
			return (-1);
		}
		dup2(fd1, STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		pipexf(argv[2], envp);
		execute(argv[3], envp);
	}
	return (0);
}

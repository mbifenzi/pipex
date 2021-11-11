/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:40:15 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/11/11 03:24:29 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_close(int infile, int outfile)
{
	close(0);
	close(1);
	close(outfile);
	close(infile);
	free(g_pid);
	return (0);
}

void	read_heredoc(int *fd, int pid)
{
	close(fd[1]);
	dup2(fd[0], 0);
	waitpid(pid, NULL, 0);
	close(fd[0]);
}

void	error(void)
{
	ft_putstr_fd("ERROR\n", 1);
	exit(0);
}

char	*find_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**paths;
	char	*tmp;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	path = ft_strdup(env[i] + 5);
	paths = ft_split(path, ':');
	free(path);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	execute_exe(char *argv, char **env)
{
	char	**cmd;
	char	*file_path;

	cmd = ft_split(argv, ' ');
	file_path = find_path(cmd[0], env);
	if (execve(file_path, cmd, env) == -1)
		error();
}

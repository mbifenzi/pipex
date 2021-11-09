/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:18:07 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/11/09 19:36:19 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int i;

	i = 0;
	if (pipe(fd) == -1)
		error();
	pid = fork();
	g_pid[g_count] = pid;
	g_count++;
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execute_exe(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		error();
	pid = fork();
	
	if (pid == 0)
	{
		close(fd[0]);
		while (get_next_line(0, &line) != 0)
		{
			if(ft_strncmp(line, limiter,ft_strlen(limiter)) == 0)
				exit (0);
			ft_putstr_fd(line, fd[1]);
			ft_putstr_fd("\n", fd[1]);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		// wait(NULL);
	}
}

int ft_open(char *file, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 2)
		fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		error();
	return (fd);
}

int main(int argc, char **argv, char **env)
{
    int i;
	int infile;
	int outfile;

	g_pid = malloc(sizeof(int) * ft_strlen(*argv) - 2);
	if (argc < 5)
		error();
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i  = 3;
		outfile = ft_open(argv[argc - 1], 0);
		here_doc(argv[2]);
	}
	else
	{
		i = 2;
		outfile = ft_open(argv[argc - 1], 1);
		infile = ft_open(argv[1], 2);
		dup2(infile, 0);
	}
	while (i < argc - 2)
		child_process(argv[i++], env);
	dup2(outfile, 1);
	// pid = fork();
	// if(pid == 0)
		execute_exe(argv[argc - 2], env);
	// while (g_pid[i--])
	// 	waitpid(g_pid[i], NULL, 0);
	return (0);
}

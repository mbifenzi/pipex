/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:07:45 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/11/06 20:11:11 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int *fd, char **argv, char **env)
{
	int outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	if (outfile == -1)
		error();
	close(fd[1]);
	execute_exe(argv[3], env);
}

void	child_process(int *fd, char **argv, char **env)
{
	int infile;

	infile = open(argv[1], O_RDONLY, 0777);
	dup2(fd[1], 1);
	dup2(infile, 0);
	if (infile == -1)
		error();
	close(fd[1]);
	execute_exe(argv[2], env);
}

int main(int argc, char **argv, char **env)
{
    int fd[2];
	int pid;

	if(argc != 5)
		error();
	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == 0)
		child_process(fd, argv, env);
	waitpid(pid, NULL, 0);
	parent_process(fd, argv, env);
}

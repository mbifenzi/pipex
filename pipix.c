/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:43:03 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/20 20:14:17 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipix.h"

char find_path(char *cmd, char **env)
{
	
}

void execute_exe(char **argv, char **env)
{
	char	**cmd;
	char	*file_path;

	cmd = ft_split(argv, ' ');
	file_path = find_path(cmd[0], env);
	if (execve(file_path, cmd, env) == -1)
		write(1, "ERROR\n",6);
}
void	parent_process(char **argv, char **env)
{
	exit (0);
}

void	child_process(char **argv, char **env)
{
	int infile;

	infile = open(argv[1], O_RDONLY | O_CREAT, 0777);
	if (infile == -1)
		write(1, "ERROR\n",6);
	execute_exe(argv, env);
}

int main(int argc, char **argv, char **env)
{
    int fd[2];
	int pid;
    
	if(argc == 5)
		write(1, "ERROR\n", 6);
	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == 0)
		child_process(argv, env);
	parent_process(argv, env);
}
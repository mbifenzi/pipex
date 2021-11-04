/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:07:45 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/11/04 15:07:47 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipix.h"

char *find_path(char *cmd, char **env)
{
	int 	i;
	char	*path;
	char 	**paths;
	char 	*tmp;

	i = 0;
	while (ft_strnstr(env[i],"PATH", 4) == 0)
		i++;
	path = ft_strdup(env[i] + 5);
	paths = ft_split(path, ':');
	free(path);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp,cmd);
		if (access(path,F_OK) == 0)
			return(path);
		i++;
	}
	return(0);
}

void execute_exe(char *argv, char **env)
{
	char	**cmd;
	char	*file_path;

	cmd = ft_split(argv, ' ');
	file_path = find_path(cmd[0], env);
	if (execve(file_path, cmd, env) == -1)
		write(1, "Exec Error\n", 11);
	
}
void	parent_process(int *fd, char **argv, char **env)
{
	int outfile;
	
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	if (outfile == -1)
		write(1, "Child Error\n",12);
	close(fd[1]);
	execute_exe(argv[3], env);
}

void	child_process(int *fd, char **argv, char **env)
{
	int infile;

	infile = open(argv[1], O_RDONLY, 0777);
	dup2(fd[1], 1);
	dup2(infile, 0);
	printf("%d\n", infile);
	if (infile == -1)
		write(1, "Child Error\n",12);
	close(fd[1]);
	execute_exe(argv[2], env);
}

int main(int argc, char **argv, char **env)
{
    int fd[2];
	int pid;
    
	if(argc != 5)
		write(1, "ERROR\n", 6);
	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == 0)
		child_process(fd, argv, env);
	waitpid(pid, NULL, 0);
	parent_process(fd, argv, env);
}
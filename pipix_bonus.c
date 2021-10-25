/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipix_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:18:07 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/25 17:24:01 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipix.h"

void	here_doc(char *limiter)
{
	int fd[2];
	pid_t pid;
	char *line;

	if(pipe(fd) == -1)
		error();
	pid = fork();
	while ()
	{
		/* code */
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
    int fd[2];
	int infile;
	int outfile;
	
	if (argc < 5)
	{
		ft_putstr_fd("error\n", 1);
		exit (0);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		outfile = ft_open(argv[argc - 1], 0);
		here_doc(argv[2]);
	}
}
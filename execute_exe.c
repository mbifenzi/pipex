/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:40:15 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/11/05 18:17:18 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error()
{
	ft_putstr_fd("ERROR\n", 1);
	exit(0);
}


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
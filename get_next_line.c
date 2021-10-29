/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:12:12 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/27 12:08:18 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipix.h"

int		ft_finish(char **str, char **line)
{
	if (!(*line = ft_strdup(*str)))
		return (-1);
	free(*str);
	*str = NULL;
	return (0);
}

int		ft_remplissage(char **str, char **line, int len)
{
	char *tmp;

	if (!(*line = ft_substr(*str, 0, len)))
		return (-1);
	if (!(tmp = ft_strdup((*str) + len + 1)))
		return (-1);
	free(*str);
	if (!(*str = ft_strdup(tmp)))
		return (-1);
	free(tmp);
	return (1);
}

int		ft_read(int fd, char **str)
{
	int		ret;
	char	*buff;
	char	*tmp;

	if (!(buff = malloc(sizeof(char) * (30 + 1))))
		return (-1);
	while ((ret = read(fd, buff, 30)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin((*str), buff)))
			return (-1);
		free(*str);
		*str = NULL;
		if (!(*str = ft_strdup(tmp)))
			return (-1);
		free(tmp);
		if (ft_strchr((*str), '\n'))
			break ;
	}
	free(buff);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char		*str;
	int				ret;
	int				len;

	len = 0;
	if (fd < 0 || 30 < 0)
		return (-1);
	if (!str)
	{
		if (!(str = ft_strdup("")))
			return (-1);
	}
	ret = ft_read(fd, &str);
	if (ret < 0)
		return (-1);
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
	{
		return (ft_remplissage(&str, line, len));
	}
	else if (str[len] == '\0')
		return (ft_finish(&str, line));
	return (0);
}

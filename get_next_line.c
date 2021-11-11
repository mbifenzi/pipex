/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:12:12 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/11/11 03:26:20 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	remplir_line(char **line, char **str, int len)
{
	char	*tmp;

	*line = ft_substr(*str, 0, len);
	if (!(*line))
		return (-1);
	tmp = ft_strdup((*str) + len + 1);
	if (!(tmp))
		return (-1);
	free(*str);
	*str = ft_strdup(tmp);
	if (!(*str))
		return (-1);
	free(tmp);
	return (1);
}

int	remplir_fin(char **line, char **str)
{
	*line = ft_strdup(*str);
	if (!(*line))
		return (-1);
	free(*str);
	*str = NULL;
	return (0);
}

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}

int	ft_read(int fd, char **str)
{
	char	*buff;
	char	*tmp;
	int		ret;

	buff = malloc(32 + 1 * sizeof(char));
	if (!buff)
		return (-1);
	ret = read(fd, buff, 32);
	while (ret > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strdup(*str);
		if (!tmp)
			return (-1);
		free_str(str);
		*str = ft_strjoin(tmp, buff);
		if (!(*str))
			return (-1);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
		ret = read(fd, buff, 32);
	}
	free(buff);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	int			len;

	len = 0;
	if (fd < 0)
		return (-1);
	if (str == NULL)
	{
		str = ft_strdup("");
		if (!(str))
			return (-1);
	}
	ret = ft_read(fd, &str);
	if (ret < 0)
		return (-1);
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
		return (remplir_line(line, &str, len));
	else if (str[len] != '\n' && len > 0)
		return (-1);
	else if (str[len] == '\0')
		return (remplir_fin(line, &str));
	return (0);
}

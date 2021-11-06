/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:57:04 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/11/05 18:19:01 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (0);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > ft_strlen(s))
		return (new = ft_strdup(""));
	while (i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:44:20 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/20 19:57:23 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipix.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*a;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if (!(a = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_memcpy(a, s1, i + 1);
	return (a);
}

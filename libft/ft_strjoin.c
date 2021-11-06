/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:12:45 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/11/05 18:19:01 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new;

	k = 0;
	i = ft_strlen((char *)s2);
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(new = (char *)malloc((sizeof(char) *
						(ft_strlen((char *)s1) + i + 1)))))
		return (0);
	while (k < ft_strlen((char *)s1) && s1[k])
	{
		new[k] = s1[k];
		k++;
	}
	while (k < (i + ft_strlen((char *)s1)) && s2[j])
	{
		new[k++] = s2[j];
		j++;
	}
	new[k] = '\0';
	return (new);
}

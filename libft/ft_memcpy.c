/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 23:56:45 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/11/05 18:19:01 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	if (dst == src || !ft_memcmp(dst, src, n))
		return (dst);
	if (dest == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

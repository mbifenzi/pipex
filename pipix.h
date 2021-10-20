/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:42:41 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/20 20:16:56 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPIX_H
#define PIPIX_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

char				**ft_split(char const *s, char c);
char	            *ft_substr(char const *s, unsigned int start, size_t len);
void	            child_process(char **argv, char **env);
void	            parent_process(char **argv, char **env);
void                execute_exe(char **argv, char **env);
char	            *ft_strdup(const char *s1);
char	            *ft_strnstr(const char *str, const char *to_find, size_t len);

#endif
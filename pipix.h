/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:42:41 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/10/25 16:06:35 by mbifenzi         ###   ########.fr       */
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

/* libft*/
char				**ft_split(char const *s, char c);
char	            *ft_substr(char const *s, unsigned int start, size_t len);
char	            *ft_strdup(const char *s1);
char	            *ft_strnstr(const char *str, const char *to_find, size_t len);
size_t		        ft_strlen(const char *str);
void	            *ft_memcpy(void *dst, const void *src, size_t n);
char	            *ft_substr(char const *s, unsigned int start, size_t len);
int		            ft_memcmp(const void *s1, const void *s2, size_t n);
char	            *ft_strjoin(char const *s1, char const *s2);
void	            ft_putstr_fd(char *s, int fd);
void	            ft_putchar_fd(char c, int fd);




/*exec*/
void	            child_process(int *fd, char **argv, char **env);
void	            parent_process(int *fd, char **argv, char **env);
void                execute_exe(char *argv, char **env);

#endif
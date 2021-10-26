
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 14:33:22 by mbifenzi          #+#    #+#              #
#    Updated: 2019/11/05 15:47:48 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_split.c ft_strlen.c  ft_strncmp.c \
		ft_memcmp.c	ft_strdup.c ft_substr.c \
		ft_memcpy.c ft_strjoin.c ft_strchr.c \
 		ft_putchar_fd.c ft_putstr_fd.c ft_strnstr.c \

OBJECT = *.o

NAME = ../libft.a

all : $(NAME)

$(NAME) : $(SRC)
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

bonus : 
	@echo "hello world"

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 13:45:06 by mbifenzi          #+#    #+#              #
#    Updated: 2021/11/12 01:36:14 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus

SRC =	pipex.c execute_exe.c
BONUS_SRC = pipex_bonus.c get_next_line.c execute_exe.c

all :	$(NAME)

bonus : $(BONUS_NAME)
		
$(NAME): $(SRC)
		@cd ./libft ; make all
		@gcc -Wall -Wextra -Werror $(SRC) libft.a -o $(NAME) libft.a #-fsanitize=address -g
		
$(BONUS_NAME): $(BONUS_SRC)
		@cd ./libft ; make all
		@gcc -Wall -Wextra -Werror $(BONUS_SRC) -o $(BONUS_NAME) libft.a #-fsanitize=address -g

clean:
	@rm -f $(OBJECT)
	@cd ./libft ; make clean
bonus_clean:
	@rm -f $(BONUS_OBJECT)
	@cd ./libft ; make clean
fclean: clean
	@rm -f $(NAME)
	@cd ./libft ; make fclean
bonus_fclean: clean
	@rm -f $(BONUS_NAME)
	@cd ./libft ; make fclean
re: fclean all
bonus_re : bonus_fclean bonus

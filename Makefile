# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 13:45:06 by mbifenzi          #+#    #+#              #
#    Updated: 2021/10/29 16:50:41 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipix
BONUS_NAME = pipix_bonus

SRC =	pipix.c execute_exe.c
BONUS_SRC = pipix_bonus.c get_next_line.c execute_exe.c

all :	$(NAME)

bonus : $(BONUS_NAME)
		
$(NAME): $(SRC)
		@cd ./libft ; make all
		@gcc -Wall -Wextra -Werror $(SRC) libft.a -o $(NAME) libft.a
		
$(BONUS_NAME): $(BONUS_SRC)
		@cd ./libft ; make all
		@gcc -Wall -Wextra -Werror $(BONUS_SRC) libft.a -o $(BONUS_NAME)

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
re: fclean all
bonus_re : bonus_fclean bonus_all

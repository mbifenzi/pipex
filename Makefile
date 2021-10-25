# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 13:45:06 by mbifenzi          #+#    #+#              #
#    Updated: 2021/10/25 16:13:57 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipix
BONUS_NAME = pipix_bonus

SRC =	pipix.c

BONUS_SRC = pipix_bonus.c

all :	
		@cd ./libft ; make all

bonus : $(BONUS_NAME)
		@cd ./libft ; make all

$(NAME): $(SRC)
		@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)		
		
$(BONUS_NAME):
		@gcc -Wall -Wextra -Werror $(BONUS_SRC) -o $(BONUS_NAME)

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
	@cd ./libft ; make re
	@cd ./libft ; make fclean
bonus_re : bonus_fclean bonus_all
			@cd ./libft ; make re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 16:00:21 by rpapagna          #+#    #+#              #
#    Updated: 2019/04/05 13:20:51 by rpapagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
CFLAGS	= -Wall -Wextra -Werror
DEBUG	= .debug.c
MAIN	= main.c
SRCS	= checkit.c \
		errors.c \
		tetris.c \
		map.c \
		math.c \
		solveit.c

#COLOR OUTPUT OPIONS
RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
NC		=\033[0m

all: $(NAME)

$(NAME):
		@make -C libft
		@echo "Building $(NAME) ..."
		@gcc $(CFLAGS) -o $(NAME) $(MAIN) $(SRCS) -I fillit.h -L ./libft/ -lft
		@SLEEP 1
		@echo "$(RED)Success!$(NC)"
		@echo "$(NC)run with $(GREEN)./$(NAME) $(NC)... $(GREEN)input file$(NC)"

clean:
		@make -C libft clean
		@SLEEP .3
fclean: clean
		@make -C libft fclean
		@SLEEP .1
		@echo "Removing program$(NC)"
		@rm -f $(NAME)
		@rm -rf fillit.dSYM
		@SLEEP .8
		@echo "all clean! $(RED)<3$(NC)"

re:		fclean all

debug:
		@echo "$(YELLOW)creating $(NAME) for debug$(NC)"
		@gcc -g $(CFLAGS) -o $(NAME) $(DEBUG) $(SRCS) -I fillit.h -L ./libft/ -lft

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 16:00:21 by rpapagna          #+#    #+#              #
#    Updated: 2019/03/27 17:13:05 by rpapagna         ###   ########.fr        #
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
FILES_O	= $(SRCS:%.c=%.o)

#COLOR OUTPUT OPIONS
RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
NC		=\033[0m

all: $(NAME)

$(NAME):
		@make -C libft
		@echo "Building $(NAME) ..."
		@gcc $(CFLAGS) -c $(MAIN) $(SRCS) -I fillit.h
		@gcc $(CFLAGS) -o $(NAME) $(FILES_O) -L ./libft/ -lft
		@echo "$(RED)Success!$(NC)"
		@SLEEP .5
		@echo "$(NC)run with $(GREEN)./$(NAME) $(NC)... $(GREEN)input file$(NC)"

clean:
		@make -C libft clean
		@rm -f $(FILES_O)
		@echo "objects removed"
		@SLEEP .5

fclean: clean
		@make -C libft fclean
		@SLEEP .5
		@echo "$(GREEN)Removing program$(NC)"
		@rm -f $(NAME)
		@SLEEP .5
		@rm -rf $(NAME).dSYM
		@echo "all clean! $(RED)<3$(NC)"
		@SLEEP .5

re:		fclean all

debug:
		@echo "$(YELLOW)creating $(NAME) for debug$(NC)"
		@gcc $(CFLAGS) -c $(DEBUG) $(SRCS) -I includes/fillit.h
		@gcc $(CFLAGS) -o $(NAME) $(FILES_O) -L ./libft/ -lft

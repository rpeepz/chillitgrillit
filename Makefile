# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 16:00:21 by rpapagna          #+#    #+#              #
#    Updated: 2019/03/22 16:49:48 by rpapagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
CFLAGS	= -Wall -Wextra -Werror
DIR_H	= .
INCL	= -I $(DIR_H) -L libft -lft
SRCS	= main.c \
		  checkit.c \
		  get_next_line.c \
		  tetris.c \
		  solvit.c \
		  printit.c
FILES_O	= $(SRCS:%.c=%.o)

#COLOR OUTPUT OPIONS
RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
NC		=\033[0m

all: $(NAME)

$(NAME):
		@echo "Building $(NAME) ..."
		@gcc $(CFLAGS) $(SRCS) -o $(NAME) $(INCL)
		@SLEEP .5
		@echo "$(RED)Success!"
		@SLEEP .5
		@echo "$(NC)run with $(GREEN)./$(NAME) $(NC)... $(GREEN)input file$(NC)"

clean:
		@rm -f $(FILES_O)

fclean: clean
		@echo "Removing program "
		@rm -f $(NAME)
		@SLEEP .5
		@rm -rf $(NAME).dSYM
		@echo "all clean! $(RED)<3$(NC)"

re: fclean all

debug:
		@echo "$(YELLOW)creating $(NAME) for debug$(NC)"
		@gcc -g $(CFLAGS) $(SRCS) -o $(NAME) $(INCL)

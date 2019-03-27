# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 16:00:21 by rpapagna          #+#    #+#              #
#    Updated: 2019/03/22 17:13:05 by rpapagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
CFLAGS	= -Wall -Wextra -Werror
DIR_H	= .
LIBDIR	= libft/
INCL	= -I $(DIR_H) -L libft -lft
MAIN	= main.c
DEBUG	= .debug.c
SRCS	= checkit.c \
		  get_next_line.c \
		  tetris.c \
		  solvit.c \
		  printit.c \
		  initit.c
FILES_O	= $(SRCS:%.c=%.o)

#COLOR OUTPUT OPIONS
RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
NC		=\033[0m

all: $(NAME)

$(NAME):
		@cd $(LIBDIR) && make
		@cd ..
		@echo "Building $(NAME) ..."
		@gcc $(CFLAGS) $(MAIN) $(SRCS) -o $(NAME) $(INCL)
		@SLEEP .5
		@echo "$(RED)Success!$(NC)"
		@SLEEP .5
		@echo "$(NC)run with $(GREEN)./$(NAME) $(NC)... $(GREEN)input file$(NC)"

clean:
		@cd $(LIBDIR) && make clean
		@cd ..
		@rm -f $(FILES_O)

fclean: clean
		@cd $(LIBDIR) && make fclean
		@cd ..
		@echo "Removing program "
		@rm -f $(NAME)
		@SLEEP .5
		@rm -rf $(NAME).dSYM
		@echo "all clean! $(RED)<3$(NC)"
		@SLEEP .5

re: fclean all

change:
		gcc $(CFLAGS) $(MAIN) $(SRCS) -o $(NAME) $(INCL)

debug:
		@echo "$(YELLOW)creating $(NAME) for debug$(NC)"
		@gcc -g $(CFLAGS) $(DEBUG) $(SRCS) -o $(NAME) $(INCL)

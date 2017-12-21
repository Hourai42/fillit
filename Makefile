# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 19:40:55 by ttran             #+#    #+#              #
#    Updated: 2017/12/19 18:40:36 by ttran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Werror -Wextra
CC = gcc
SRCS = srcs/checkfill.c srcs/parsefill.c srcs/miscfill.c srcs/solvefill.c srcs/main.c

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -o $(NAME) -I includes $(SRCS)

clean:

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

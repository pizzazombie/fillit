# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/08 16:19:04 by dholiday          #+#    #+#              #
#    Updated: 2019/06/04 18:46:20 by dholiday         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c list.c putter.c rotate.c check_figure.c check_valid.c clean.c

SRC = ./src

FLAGS = -Wall -Wextra -Werror

INCLUDES = ./src/fillit.h

LIB = ./libft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIB) re
	gcc $(FLAGS) -L $(LIB) -lft $(SRC)/*.c -I $(INCLUDES) -o $(NAME)

clean:
	@make -C $(LIB) clean

fclean:
	@make -C $(LIB) fclean
	/bin/rm -f $(NAME)

re:	fclean $(NAME)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 19:07:10 by jwon              #+#    #+#              #
#    Updated: 2024/07/14 20:20:17 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= app

LIB		= ./lib/
WIN		= $(LIB)win/
HOOK	= $(WIN)hook/*.c
IMG		= $(WIN)img/*.c
MAP		= $(LIB)map/*.c
PLAYER	= $(LIB)player/*.c

LIBFT	= ./libft/
MINILIBX = ./minilibx

SRC		= $(WIN)*.c\
		  $(IMG) \
		  $(MAP) \
		  $(HOOK) \
		  $(PLAYER) 

FLAGS		= -Wall -Werror -Wextra

CP			= gcc

all:
	$(MAKE) -C $(LIBFT) rec
	$(CP) -c main.c $(SRC) -I ./includes
	$(CP) -o $(NAME) *.o -I ./includes -L$(MINILIBX) -lmlx -lXext -lX11 -lm -L$(LIBFT) -lft

clean:
	rm -f *.o
	$(MAKE) -C $(LIBFT) clean

fclean:
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

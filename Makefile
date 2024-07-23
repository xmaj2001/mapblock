# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 19:07:10 by jwon              #+#    #+#              #
#    Updated: 2024/07/18 14:29:56 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

LIB		= ./libftx/
WIN		= $(LIB)win/
HOOK	= $(WIN)hook/*.c
IMG		= $(WIN)img/*.c
FILE_SRC = ./src/

LIBFT	= ./libftx/libft/
MINILIBX = ./minilibx-linux

SRC		= $(WIN)*.c\
		  $(IMG) \
		  $(HOOK) \
		  $(FILE_SRC)map/*.c \
		  $(FILE_SRC)ui/*.c \
		  $(FILE_SRC)player/*.c \
		  $(FILE_SRC)enemy/*.c \
		  $(FILE_SRC)game/*.c 
		

FLAGS		= -Wall -Werror -Wextra

CP			= cc

all:$(NAME)

$(NAME):
	# $(MAKE) -C $(MINILIBX) 
	$(MAKE) -C $(LIBFT)
	$(CP) -c main.c $(SRC) -I ./inc
	$(CP) -o $(NAME) *.o -L$(MINILIBX) -lmlx -lXext -lX11 -lm -L$(LIBFT) -lft

clean:
	# $(MAKE) -C $(MINILIBX) clean
	$(MAKE) -C $(LIBFT) clean
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

rec: fclean all
	$(MAKE) -C $(LIBFT) clean
	rm -f *.o
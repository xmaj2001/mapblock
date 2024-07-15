# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 19:07:10 by jwon              #+#    #+#              #
#    Updated: 2024/07/15 19:02:06 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

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

all:$(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT) re
	$(CP) $(FLAGS) -c main.c $(SRC) -I ./includes
	$(CP) $(FLAGS) -o $(NAME) *.o -I ./includes -L$(MINILIBX) -lmlx -lXext -lX11 -lm -L$(LIBFT) -lft

run:
	$(MAKE) -C $(LIBFT) rec
	$(CP) $(FLAGS) -c main.c $(SRC) -I ./includes
	$(CP) $(FLAGS) -o $(NAME) *.o -I ./includes -L$(MINILIBX) -lmlx -lXext -lX11 -lm -L$(LIBFT) -lft
	rm -f *.o

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

rec: run
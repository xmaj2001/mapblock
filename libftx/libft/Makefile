# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 19:07:10 by jwon              #+#    #+#              #
#    Updated: 2024/07/14 19:27:36 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

IS		= ./is/
MEM		= ./mem/
PRINT	= ./print/
PRINTF	= ./printf/
STRING	= ./string/
CONVERT	= ./convert/
		
FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c -I ./
	ar rc $(NAME) *.o
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

rec: fclean all
	rm -f *.o
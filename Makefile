# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 19:52:17 by obelaizi          #+#    #+#              #
#    Updated: 2023/01/15 20:46:52 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

SRCS = 1.c 2.c functions_helpers.c parsing.c
OBJS= $(SRCS:.c=.o)


%.o: %.c push_swap.h
	cc -c $(FLAGS) $<

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 19:52:17 by obelaizi          #+#    #+#              #
#    Updated: 2023/01/16 15:58:43 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

SRCS = main_file.c mandatory_func1.c mandatory_func2.c lst_functions.c functions_helpers1.c functions_helpers2.c parsing.c split.c 
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
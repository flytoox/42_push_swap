# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 19:52:17 by obelaizi          #+#    #+#              #
#    Updated: 2023/01/20 11:37:00 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
FLAGS = -Wall -Wextra -Werror -g


SRCS = $(wildcard *.c)
OBJS= $(SRCS:.c=.o)

SRCS_BONUS = $(wildcard ./BONUS/*.c ./BONUS/GET_NEXT_LINE/*.c)
OBJS_BONUS= $(SRCS_BONUS:.c=.o)


all : $(NAME)

%_bonus.o: %_bonus.c ./BONUS/checker_bonus.h ./BONUS/GET_NEXT_LINE/get_next_line.h
	cc -c $(FLAGS) $< -o $@

%.o: %.c push_swap.h
	cc -c $(FLAGS) $<

	
$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)

bonus: $(OBJS_BONUS)
	cc $(OBJS_BONUS) -o $(NAME_BONUS)

clean: 
	rm -f $(OBJS) $(OBJS_BONUS) 

fclean:clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
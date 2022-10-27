# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 00:59:15 by mravera           #+#    #+#              #
#    Updated: 2022/10/27 18:08:24 by mravera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS := -Wall -Werror -Wextra

CC := gcc

RM := rm -f
NAME := philo

SRCS := philo.c \
		pl_parsing.c \
#		fichier3.c \
#		fichier4.c \

OBJ := $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -pthread $(CFLAGS) $^ -o $@

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
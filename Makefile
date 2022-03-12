# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhanda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 11:18:30 by selhanda          #+#    #+#              #
#    Updated: 2022/02/02 11:18:35 by selhanda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME=pipex
SRC=main.c utils.c
FLAGS=-c $< -o $@
CFLAGS=-Wall -Wextra -Werror
OBJ=$(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(FLAGS)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)
fclean:clean
	rm -f $(NAME)
re:fclean $(NAME)

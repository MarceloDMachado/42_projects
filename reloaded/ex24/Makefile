# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:56:35 by madias-m          #+#    #+#              #
#    Updated: 2023/10/09 16:35:52 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./srcs/
HEADER_PATH = ./includes/
FLAGS = -Wall -Wextra -Werror
OPTIONS = -c -I $(HEADER_PATH)
NAME = libft.a
SRC = $(SRC_PATH)ft_putchar.c \
	$(SRC_PATH)ft_putstr.c \
	$(SRC_PATH)ft_strcmp.c \
	$(SRC_PATH)ft_strlen.c \
	$(SRC_PATH)ft_swap.c 
OBJ = ft_putchar.o \
	ft_putstr.o ft_strlen.o \
	ft_strcmp.o ft_swap.o 

all:	$(NAME)

$(NAME):
	gcc $(FLAGS) $(OPTIONS) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean 
	rm -f $(NAME)

re: fclean	all
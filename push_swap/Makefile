# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 20:17:15 by madias-m          #+#    #+#              #
#    Updated: 2024/06/11 12:39:34 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

W_FLAGS = -Wall -Wextra -Werror -g3
NAME = push_swap
INC = -I ./includes/\
	  -I ./libft/
SRC = main.c stack.c swap.c rotate.c reverse.c print.c utils.c push.c sort.c
SRC_PATH = src/
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	cc $(W_FLAGS) -o $(NAME) $(OBJ) $(LIB) $(INC)

%.o: $(SRC_PATH)%.c
	cc $(W_FLAGS) -c $< -o $@ $(INC)

$(LIB):
	make -sC libft/ all

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	rm -f $(LIB)

re: fclean all

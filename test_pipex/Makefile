# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 20:17:15 by madias-m          #+#    #+#              #
#    Updated: 2024/04/07 16:02:51 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

W_FLAGS = -Wall -Wextra -Werror -g3
NAME = pipex
INC = -I ./includes/\
	  -I ./libft/
SRC = main.c exec_handler.c \
	parent_process.c matrix_utils.c \
	ctrl_utils.c child_process.c 
SRC_PATH = src/
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	cc $(W_FLAGS) -o $(NAME) $(OBJ) $(LIB) $(INC)

%.o: $(SRC_PATH)%.c
	cc -c $< -o $@ $(INC)

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

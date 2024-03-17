# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 20:17:15 by madias-m          #+#    #+#              #
#    Updated: 2024/03/17 10:24:22 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

W_FLAGS = -Wall -Wextra -Werror
ML_FLAGS = -lmlx -lX11 -lXext
NAME = so_long
INC = -I ./includes/\
	  -I ./libft/
SRC = so_long.c \
	  validate_map.c
SRC_PATH = src/
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	cc $(W_FLAGS) -o $(NAME) $(OBJ) $(LIB) $(INC) $(ML_FLAGS)

%.o: $(SRC_PATH)%.c
	cc $(C_FLAGS) -c $< -o $@ $(INC)

$(LIB):
	make -sC libft/ all

bonus: all

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	rm -f $(LIB)

re: fclean all

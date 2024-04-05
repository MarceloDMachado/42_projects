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

W_FLAGS = -Wall -Wextra -Werror -g3
ML_FLAGS = -lmlx -lX11 -lXext
NAME = so_long
INC = -I ./includes/\
	  -I ./libft/
SRC = so_long.c \
	  validate_map.c validate_map_utils.c \
	  read_map.c map_utils.c \
	  draw.c draw_utils.c \
	  quit.c start.c \
	  key_handler.c move_handler.c \
	  flood_fill.c
SRC_PATH = src/
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	cc $(W_FLAGS) -o $(NAME) $(OBJ) $(LIB) $(INC) $(ML_FLAGS)

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

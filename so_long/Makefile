# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 20:17:15 by madias-m          #+#    #+#              #
#    Updated: 2024/02/26 19:35:45 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

W_FLAGS = -Wall -Wextra -Werror
ML_FLAGS = -lmlx -lX11 -lXext
NAME = so_long
SRC = test.c
OBJ = $(SRC:.c=.o)
LIB = libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cc $(OBJ) $(LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 

%.o: %.c 
	cc $(W_FLAGS) -I/usr/include -Imlx_linux -03 -c $< -o $@

$(LIB):
	make -C libft/ all
	cp libft/$(LIB) .

bonus: all

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	rm -f $(LIB)

re: fclean all

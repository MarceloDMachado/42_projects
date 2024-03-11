# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 20:17:15 by madias-m          #+#    #+#              #
#    Updated: 2024/03/11 18:03:07 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

W_FLAGS = -Wall -Wextra -Werror
ML_FLAGS = -lmlx -lX11 -lXext
NAME = so_long
SRC = test.c
SRC_PATH = src/
OBJ = $(SRC:.c=.o)
LIB = libft.a

all: $(NAME)


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

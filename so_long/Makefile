# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 20:17:15 by madias-m          #+#    #+#              #
#    Updated: 2024/02/26 18:26:44 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

W_FLAGS = -Wall -Wextra -Werror
ML_FLAGS = -lmlx -lX11 -lXext
OPTIONS = -c $< -I ./
NAME = so_long
SRC = put_nbr.c put_char.c \
	  put_str.c ft_printf.c \
	  put_nbr_hex.c put_space.c \
	  put_zero.c
OBJ = $(SRC:.c=.o)
LIB = libft.a

all: $(NAME) $(OBJ)

$(NAME):
	make -C libft/ all
	cp libft/$(LIB) $(NAME)

%.o: %.c 
	cc $(W_FLAGS) $(OPTIONS) -o $@
	ar rc $(NAME) $@

bonus: all

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	rm -f $(LIB)

re: fclean all

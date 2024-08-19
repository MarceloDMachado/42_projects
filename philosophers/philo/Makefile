# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 17:12:43 by madias-m          #+#    #+#              #
#    Updated: 2024/08/05 17:23:33 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

W_FLAGS = -Wall -Wextra -Werror -pthread
NAME = philo
INC = -I ./includes/
SRC = main.c ft_atoi.c dinner.c action.c ft_calloc.c handler.c
SRC_PATH = src/
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(W_FLAGS) -o $(NAME) $(OBJ) $(INC)

%.o: $(SRC_PATH)%.c
	cc $(W_FLAGS) -c $< -o $@ $(INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

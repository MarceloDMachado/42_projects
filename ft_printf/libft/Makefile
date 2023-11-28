# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 11:40:10 by madias-m          #+#    #+#              #
#    Updated: 2023/11/08 20:13:10 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./
FLAGS = -Wall -Wextra -Werror
OPTIONS = -c $< -I ./
NAME = libft.a
SRC = $(SRC_PATH)ft_isalpha.c $(SRC_PATH)ft_isdigit.c \
      $(SRC_PATH)ft_isalnum.c $(SRC_PATH)ft_isprint.c \
      $(SRC_PATH)ft_isascii.c $(SRC_PATH)ft_strlen.c \
      $(SRC_PATH)ft_memset.c $(SRC_PATH)ft_bzero.c \
      $(SRC_PATH)ft_memcpy.c $(SRC_PATH)ft_memmove.c \
      $(SRC_PATH)ft_strlcpy.c $(SRC_PATH)ft_strlcat.c \
      $(SRC_PATH)ft_toupper.c $(SRC_PATH)ft_tolower.c \
      $(SRC_PATH)ft_strchr.c $(SRC_PATH)ft_strrchr.c \
      $(SRC_PATH)ft_strncmp.c $(SRC_PATH)ft_memchr.c \
      $(SRC_PATH)ft_memcmp.c $(SRC_PATH)ft_strnstr.c \
      $(SRC_PATH)ft_atoi.c $(SRC_PATH)ft_calloc.c \
      $(SRC_PATH)ft_strdup.c $(SRC_PATH)ft_substr.c \
      $(SRC_PATH)ft_strjoin.c $(SRC_PATH)ft_strtrim.c \
      $(SRC_PATH)ft_split.c $(SRC_PATH)ft_itoa.c \
	  $(SRC_PATH)ft_strmapi.c $(SRC_PATH)ft_striteri.c \
	  $(SRC_PATH)ft_putchar_fd.c $(SRC_PATH)ft_putstr_fd.c \
	  $(SRC_PATH)ft_putendl_fd.c $(SRC_PATH)ft_putnbr_fd.c
B_SRC = $(SRC_PATH)ft_lstnew.c $(SRC_PATH)ft_lstadd_front.c \
		$(SRC_PATH)ft_lstsize.c $(SRC_PATH)ft_lstlast.c \
		$(SRC_PATH)ft_lstadd_back.c $(SRC_PATH)ft_lstdelone.c \
		$(SRC_PATH)ft_lstclear.c $(SRC_PATH)ft_lstiter.c \
		$(SRC_PATH)ft_lstmap.c
OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all:	$(NAME)

%.o: %.c
	cc $(FLAGS) $(OPTIONS) -o $@
	ar rc $(NAME) $@

$(NAME): $(OBJ) 
#	cc $(FLAGS) $(OPTIONS) $(SRC)
#	ar rc $(NAME) $(OBJ)

bonus: $(B_OBJ)
#	cc $(FLAGS) $(OPTIONS) $(SRC) $(B_SRC)
#	ar rc $(NAME) $(OBJ) $(B_OBJ)

clean:
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

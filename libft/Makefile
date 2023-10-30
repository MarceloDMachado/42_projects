# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madias-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 13:12:13 by madias-m          #+#    #+#              #
#    Updated: 2023/10/30 13:17:04 by madias-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC_PATH = ./
FLAGS = -Wall -Wextra -Werror
OPTIONS = -c -I ./
NAME = libft.a
SRC = $(SRC_PATH)ft_isalpha.c \
      $(SRC_PATH)ft_isdigit.c \
      $(SRC_PATH)ft_isalnum.c \
      $(SRC_PATH)ft_isprint.c \
      $(SRC_PATH)ft_isascii.c \
      $(SRC_PATH)ft_strlen.c \
      $(SRC_PATH)ft_memset.c \
      $(SRC_PATH)ft_bzero.c \
      $(SRC_PATH)ft_memcpy.c \
      $(SRC_PATH)ft_memmove.c \
      $(SRC_PATH)ft_strlcpy.c \
      $(SRC_PATH)ft_strlcat.c \
      $(SRC_PATH)ft_toupper.c \
      $(SRC_PATH)ft_tolower.c \
      $(SRC_PATH)ft_strchr.c \
      $(SRC_PATH)ft_strrchr.c \
      $(SRC_PATH)ft_strncmp.c \
      $(SRC_PATH)ft_memchr.c \
      $(SRC_PATH)ft_memcmp.c \
      $(SRC_PATH)ft_strnstr.c \
      $(SRC_PATH)ft_atoi.c \
      $(SRC_PATH)ft_calloc.c \
      $(SRC_PATH)ft_strdup.c $(SRC_PATH)ft_substr.c \
      $(SRC_PATH)ft_strjoin.c $(SRC_PATH)ft_strtrim.c \
      $(SRC_PATH)ft_split.c $(SRC_PATH)ft_itoa.c \
	  $(SRC_PATH)ft_strmapi.c $(SRC_PATH)ft_striteri.c \
	  $(SRC_PATH)ft_putchar_fd.c $(SRC_PATH)ft_putstr_fd.c
OBJ = ft_isalpha.o ft_isdigit.o \
	ft_isalnum.o ft_isascii.o \
	ft_isprint.o ft_strlen.o \
	ft_memset.o ft_bzero.o \
	ft_memcpy.o ft_memmove.o \
	ft_strlcpy.o ft_strlcat.o \
	ft_toupper.o ft_tolower.o \
	ft_strchr.o ft_strrchr.o \
	ft_strncmp.o ft_memchr.o \
	ft_memcmp.o ft_strnstr.o \
	ft_atoi.o ft_calloc.o ft_strdup.o \
	ft_substr.o ft_strjoin.o ft_strtrim.o \
	ft_split.o ft_itoa.o ft_strmapi.o \
	ft_striteri.o ft_putchar_fd.o \
	ft_putstr_fd.o

all:	$(NAME)

$(NAME):
	gcc $(FLAGS) $(OPTIONS) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

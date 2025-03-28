W_FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = zombies
SRC = main.cpp Zombie.cpp
SRC_PATH = ./src/
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(W_FLAGS) -o $(NAME) $(OBJ)

%.o: $(SRC_PATH)%.cpp
	c++ $(W_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

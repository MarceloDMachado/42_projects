W_FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = btc
SRC = main.cpp BitcoinExchange.cpp
SRC_PATH = ./src/
INC = -I ./inc/
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(W_FLAGS) -o $(NAME) $(OBJ) $(INC)

%.o: $(SRC_PATH)%.cpp
	c++ $(W_FLAGS) -c $< -o $@ $(INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

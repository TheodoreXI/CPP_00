SRC = Account.cpp tests.cpp
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.cpp=.o)
CC = c++
NAME = Account 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp Account.hpp
	$(CC) $(FALGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
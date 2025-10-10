SRC= phonebook.cpp
OBJ= $(SRC:.cpp=.o)
NAME= phonebook
CC= c++
FLAGS= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.cpp phonebook.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	

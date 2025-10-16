SRC= PhoneBook.cpp Contact.cpp
OBJ= $(SRC:.cpp=.o)
NAME= PhoneBook
CC= c++
FLAGS= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.cpp PhoneBook.hpp Contact.hpp 
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	

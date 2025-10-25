SRC= MegaPhone.cpp
OBJ= $(SRC:.cpp=.o)
CC= c++
FLAGS= -Wall -Wextra -Werror
NAME= Megaphone

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all
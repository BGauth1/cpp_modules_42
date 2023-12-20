NAME = Fixed

SRC = main.cpp Fixed.cpp

OBJ	= $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

CC = c++

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all
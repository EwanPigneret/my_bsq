SRC = my_bsq.c
OBJ = $(SRC:.c=.o)

NAME = my_bsq

COMPILER = gcc
INCLUDE = my_bsq.h
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all : $(OBJ)
	$(COMPILER) $(SRC) -o $(NAME) $(FLAGS)

re : fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.c.o:
	$(COMPILER) $(FLAGS) $< -o $@ $(INCLUDE)
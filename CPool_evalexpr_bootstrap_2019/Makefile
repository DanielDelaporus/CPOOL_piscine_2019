##
## EPITECH PROJECT, 2019
## CPool_Day13_2019
## File description:
## No file there, just an epitech header example
##
CC= gcc
EXEC= evalexpr
SRC= evalexpr.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)

$(EXEC):
	$(CC) -o $(EXEC) -W -Werror -Wall -Wextra $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: re clean fclean

##
## EPITECH PROJECT, 2019
## MUL_my_defender_2018
## File description:
## makefile
##

CC	= gcc -g

RM	= rm -f

NAME	= my_rpg

SRC	=   main.c

OBJ	= $(addprefix src/,$(SRC:.c=.o))

CFLAGS	= -lcsfml-graphics -lcsfml-window -lcsfml-system -l csfml-audio -W -Wextra -Wall -I include/

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

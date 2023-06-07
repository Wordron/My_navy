##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC    =	main.c	\
			get_boat_from_script.c	\
			display.c	\
			create_map.c	\
			shoot.c	\
			victory.c	\
			sig_related_function.c	\
			interpet_signals.c	\
			send_signal.c	\
			conditions.c	\
			interpret_interpret_signal.c	\
			start_round.c	\
			check_nb_boats.c	\
			player_two.c	\

OBJ    =    $(SRC:.c=.o)

CFLAGS = -g

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) -Llib -lmy

clean:
		rm $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

##
## EPITECH PROJECT, 2018
## oskour
## File description:
## aled
##

SRC	=

OBJ	=	${SRC:.cpp=.o}

NAME	=	nanotekspice

LDFLAGS	=	-Iinclude -W -Wall -Wextra -g

CC	=	g++ ${LDFLAGS}

all: ${NAME}

${NAME}:	${OBJ}
	${CC} -o ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re:	clean all

##
## EPITECH PROJECT, 2018
## oskour
## File description:
## aled
##

SRC	=   src/pin/APin.cpp    \
                src/pin/APinExt.cpp \
                src/pin/PinOutput.cpp   \
                src/pin/PinInput.cpp    \
                src/pin/APinComponent.cpp   \
                src/pin/PinComponentOut.cpp \
                src/pin/PinComponentIn.cpp  \
                src/components/AComponent.cpp   \
                src/components/gates/ComponentAND.cpp   \
                src/operator/TristateOperator.cpp   \
                src/components/gates/ComponentOR.cpp    \
                src/components/Components4000/Component4Gate.cpp    \
                src/components/gates/ComponentNOT.cpp   \
                src/components/gates/ComponentNAND.cpp  \
                src/components/gates/ComponentNOR.cpp   \
                src/components/gates/ComponentXOR.cpp   \
                src/components/gates/ComponentXNOR.cpp  \
                src/Circuit.cpp \
                src/componentList.cpp   \
                src/components/singleComponents/ComponentTrue.cpp   \
                src/components/singleComponents/ComponentFalse.cpp  \
                src/Parser.cpp  \
                src/exception/NtsException.cpp  \
                src/InGame.cpp  \
                src/components/gates/AGate.cpp  \
                src/components/Components4000/Component4069.cpp \
                src/components/ComponentFF.cpp  \
                src/components/Components4000/Component4013.cpp \
                src/components/Components4000/Component4017.cpp \
                src/components/Components4000/Component4040.cpp \
                src/components/Components4000/Component4503.cpp \
                src/components/Components4000/Component4514.cpp \
                src/components/Components4000/Component4008.cpp \
                src/components/Components4000/Component4094.cpp \
                src/other/ClockManager.cpp  \
                src/main.cpp

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

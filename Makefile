#comment
CC = gcc

SRC = ./Src/Csrc.c
CEL = ./Src/Celsius.c
LIN = ./Src/Lines.c
MAT = ./Src/Maths.c
GUI = ./Src/GUI.c

OBJ = ${SRC:.c=}
OCL = ${CEL:.c=}
OLI = ${LIN:.c=}
OMA = ${MAT:.c=}
OGU = ${GUI:.c=}

SAFTEY = -Wall -Werror -Wpedantic -lncurses -DNCURSES_STATIC

all: Prog Celsius Lines Maths Gui

Prog:
	${CC} ${SRC} -o ${OBJ} ${SAFTEY}

Celsius:
	${CC} ${CEL} -o ${OCL}

Lines:
	${CC} ${LIN} -o ${OLI}

Maths:
	${CC} ${MAT} -o ${OMA}

Gui:
	${CC} ${GUI} -o ${OGU}

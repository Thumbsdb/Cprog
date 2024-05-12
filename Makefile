#comment
CC = cc

SRC = Cprog.c
OBJ = ${SRC:.c=.o}

all: Prog

Prog:
	${CC} -o $@ ${OBJ} ${SRC}

OBJECTS=
INCLUDES= -I./

all: ${OBJECTS}
	gcc ./src/main.c ${INCLUDES} ${OBJECTS} -g -o ./bin/kentcc

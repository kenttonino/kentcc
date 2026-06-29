OBJECTS= ./build/compiler.o ./build/compiler_process.o ./build/utils/vector.o
INCLUDES= -I./

all: ${OBJECTS}
	gcc ./src/main.c ${INCLUDES} ${OBJECTS} -g -o ./bin/kentcc

./build/compiler.o: ./src/compiler/compiler.c
	# -c: Compile and assemble but do not link.
	gcc ./src/compiler/compiler.c ${INCLUDES} -o ./build/compiler.o -g -c

./build/compiler_process.o: ./src/compiler_process/compiler_process.c
	# -c: Compile and assemble but do not link.
	gcc ./src/compiler_process/compiler_process.c ${INCLUDES} -o ./build/compiler_process.o -g -c

./build/utils/vector.o: ./src/utils/vector.c
	gcc ./src/utils/vector.c ${INCLUDES} -o ./build/utils/vector.o -g -c

clean:
	rm ./bin/kentcc
	rm -rf ${OBJECTS}

run: all
	./bin/kentcc

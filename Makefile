OBJECTS=
INCLUDES= -I./

build: ${OBJECTS}
	gcc ./src/main.c ${INCLUDES} ${OBJECTS} -g -o ./bin/kentcc

clean:
	rm ./bin/kentcc
	rm -rf ${OBJECTS}

run: build
	./bin/kentcc

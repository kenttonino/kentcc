build:
	gcc -g -o ./bin/kentcc ./src/main.c

run: build
	./bin/kentcc

shell: main.o source.o scanner.o parser.o node.o executor.o prompt.o
	gcc -o shell main.c source.c scanner.c parser.c node.c executor.c prompt.c

main.o: main.c
	gcc -c main.c -o main.o

source.o: source.c
	gcc -c source.c -o source.o

scanner.o: scanner.c
	gcc -c scanner.c -o scanner.o

parser.o: parser.c
	gcc -c parser.c -o parser.o

node.o: node.c 
	gcc -c node.c -o node.o

executor.o: executor.c
	gcc -c executor.c -o executor.o

prompt.o: prompt.c 
	gcc -c prompt.c -o prompt.o

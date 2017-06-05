all: estatico

estatico: main.o libCod.a
	gcc main.o libCod.a -lm -o estatico

main.o: main.c
	gcc -Wall -c main.c
	
libCod.a: codificacion.o cifrado.o
	ar rcs libCod.a codificacion.o cifrado.o
	
cifrado.o: cifrado.c
	gcc -Wall -c cifrado.c
	
codificacion.o: codificacion.c
	gcc -Wall -c codificacion.c

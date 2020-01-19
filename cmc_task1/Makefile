all: prg
prg: main.o funcs.o num_meths.o tests.o
	gcc -m32 -o prg main.o funcs.o num_meths.o tests.o -lm
main.o: main.c decls.h
	gcc -std=c99 -m32 -c -o main.o main.c
num_meths.o: num_meths.c
	gcc -std=c99 -m32 -c -o num_meths.o num_meths.c
tests.o: tests.c
	gcc -std=c99 -m32 -c -o tests.o tests.c
funcs.o: funcs.asm
	nasm -f elf32 -o funcs.o funcs.asm
clean:
	rm -f *.o prg
	

bank.exe:main.o arbre.o
	gcc main.o arbre.o -o arbre.exe
main.o:main.c arbre.h
	gcc -c -g main.c
arbre.o:arbre.c arbre.h
	gcc -c -g arbre.c
clean:
	rm *.o arbre.exe

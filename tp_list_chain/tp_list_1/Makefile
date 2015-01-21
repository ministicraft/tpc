liste.exe:main.o fonctions.o
	gcc main.o fonctions.o -o liste.exe
main.o:main.c liste.h
	gcc -c -g main.c
fonctions.o:fonctions.c liste.h
	gcc -c -g fonctions.c
clean:
	rm *.o liste.exe

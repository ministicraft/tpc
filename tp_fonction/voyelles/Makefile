voyelles.exe:main.o fonctions.o
	gcc main.o fonctions.o -o voyelles.exe
main.o:main.c voyelles.h
	gcc -c main.c
fonctions.o:fonctions.c voyelles.h
	gcc -c fonctions.c
clean:
	rm *.o voyelles.exe

crypto.exe:main.o fonctions.o
	gcc main.o fonctions.o -o crypto.exe
main.o:main.c crypto.h
	gcc -c main.c
fonctions.o:fonctions.c crypto.h
	gcc -c fonctions.c
clean:
	rm *.o crypto.exe

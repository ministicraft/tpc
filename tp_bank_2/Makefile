bank.exe:main.o fonctions.o
	gcc main.o fonctions.o -o bank.exe
main.o:main.c bank.h
	gcc -c -g main.c
fonctions.o:fonctions.c bank.h
	gcc -c -g fonctions.c
clean:
	rm *.o bank.exe

sdl2.exe:main.o sdl.o
	gcc main.o sdl.o -g -lSDL -lm -o sdl2.exe
main.o:main.c sdl.h
	gcc -c main.c
sdl.o:sdl.c sdl.h
	gcc -c sdl.c
clean:
	rm *.o sdl2.exe

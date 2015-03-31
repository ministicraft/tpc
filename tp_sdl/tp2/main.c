#include "sdl.h"

int main() 
{
	SDL_Surface *floor = NULL; 
	SDL_Surface *ecran = init ( "floor.bmp", &floor );
	SDL_Surface *sprites = LoadSprites ( "roach.bmp" );
	SDL_Surface *tapis = LoadImage ( "bathmat.bmp", X_INIT_TAPIS, Y_INIT_TAPIS ); 
	//Roach roach = CreateRoach ( ecran, sprites );
	Roach *roaches = CreateRoaches ( ecran, sprites, MAX_ROACHES );
	SDL_Flip(ecran);

	srand (time(NULL)); //graine de génération aléatoire pour rand()

	int continuer = 1;
	SDL_Event event;
	while ( continuer )
	{
		//MoveRoach( &roach, ROACH_SPEED, ecran);
		//DrawRoach ( roach, ecran );
		SDL_BlitSurface(floor, NULL, ecran, NULL);

		MoveRoaches( roaches, MAX_ROACHES, ROACH_SPEED, ecran);
		DrawRoaches ( roaches, MAX_ROACHES, ecran );
		DrawImage ( tapis, ecran );

		SDL_Flip(ecran);
		while ( SDL_PollEvent ( &event ) )  // tant qu'il y a un évènement
		{
			switch ( event.type )
			{
				case SDL_QUIT :
					continuer = 0;
					break;
			}
		}
	SDL_Delay(DELAI_P_TOUR);
	}
	SDL_Quit ();
	return EXIT_SUCCESS;
}

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROACH_ORIENTATIONS	24	/* nbre d'orientations distinctes */ 
#define ROACH_ANGLE		15	/* angle (deg) entre orientations */ 
#define ROACH_WIDTH		48	/* pixels */ 
#define ROACH_HEIGHT		48	/* pixels */ 
#define NB_SPRITES_P_LINE	6 	/* dans bitmap des sprites */
#define ROACH_SPEED		20.0	/* pixels/tour */
#define MAX_STEPS		50	/* nb de deplacements max avant
						   changement d'orientation */ 
#define DELAI_P_TOUR		0  // en millisecondes
#define MAX_ROACHES		20	/* nb maxi de cafards */
#define X_INIT_TAPIS		100
#define Y_INIT_TAPIS		100

typedef struct Roach { 
    SDL_Surface *sprites; 
    int dir; // orientation (0 à ROACH_ORIENTATIONS-1) 
    int x; // pixels 
    int y; // pixels 
    int hidden; // 0 : visible, 1 : caché
    float angle; // orientation en radians 
    int turnLeft; // 0 : droitier, 1 : gaucher
    int steps; 
} Roach; 

SDL_Surface *init ( char * imgFond_filename, SDL_Surface **pFond );
SDL_Surface *LoadSprites ( char * sprites_filename );
void DrawRoach ( Roach roach, SDL_Surface *ecran );
int RandInt(int maxVal);
Roach CreateRoach( SDL_Surface *ecran, SDL_Surface *sprites );
int RoachInRect(int x, int y, int rectx, int recty, int rectwidth, int rectheight);
void TurnRoach(Roach *roach);
//void MoveRoach(Roach *roach, float roachSpeed, SDL_Surface *ecran);
/* Version avec gestion des collisions */
void MoveRoach(Roach *roaches, int nbRoaches, int index, float roachSpeed, SDL_Surface *ecran);

Roach *CreateRoaches ( SDL_Surface *ecran, SDL_Surface *sprites, int nbRoach );
void DrawRoaches ( Roach *roaches, int nbRoach, SDL_Surface *ecran );
void MoveRoaches ( Roach *roaches, int nbRoach, float roachSpeed, SDL_Surface *ecran);
//void CleanRoaches ( Roach *roaches,int nbRoach, SDL_Surface *ecran, SDL_Surface *floor);

SDL_Surface *LoadImage ( char * img_filename, int x, int y );
void DrawImage (SDL_Surface *img, SDL_Surface *ecran);
int MarkHiddenRoaches(Roach *roaches,int nbRoaches,SDL_Surface *rect);

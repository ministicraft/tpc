#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	if (SDL_Init (SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		exit (EXIT_FAILURE); // On quite le programme
	}
	//fonctions pour créer une fenetre d'affichage
	SDL_Surface *ecran = NULL;
	ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
	if (ecran == NULL)
	{
		fprintf(stderr,"Impossible de charger le mode video: %s\n", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	//Fonction pour nommer la fenêtre
	SDL_WM_SetCaption("Ma première fenêtre !", NULL);
	
	//Ajouter un couleur de fond
	
	SDL_FillRect (ecran, NULL, 0x326E00);
	//SDL_FillRect (ecran, NULL, SDL_MapRGB (ecran->format, 0, 255, 0));

	//Chargement d'une image
	
	SDL_Surface *fleur;
	// Chargement d'un fichier BMP dans une surface
	fleur = SDL_LoadBMP("fleur1a.bmp");
	if (fleur == NULL)
	{
		fprintf(stderr, "Impossible de charger lee fichier bmp: %s\n", SDL_GetError());
	}

	//transparence du fond d'écran

	//SDL_SetColorKey (fleur, SDL_SRCCOLORKEY, 0x000000);
	//ou avec le canal alpha
	
	SDL_SetAlpha (fleur, SDL_SRCALPHA, 0);
	fleur->format->Amask = 0xFF000000;
	fleur->format->Ashift = 24;

	//Blitting de l'image (replacement du sprite)

	//SDL_BlitSurface (fleur, NULL, ecran, NULL);
	SDL_Rect rect_fleur;
	rect_fleur.x = 100;
	rect_fleur.y = 50;
	SDL_BlitSurface (fleur, NULL, ecran, &rect_fleur);
	
	//rafraichissement de la fenètre

	SDL_Flip (ecran);

	//ajout de fleur au clique de la souris
	
	char chaine[12];
	int continuer = 1;
	int i = 1;
	srand (time(NULL)); //graine de génération aléatoire pour rand()
	SDL_Event event;
	while (continuer)
	{
		SDL_WaitEvent (&event); //attente d'un evenement
		switch (event.type)
		{
			case SDL_QUIT :
				continuer = 0;
				break;
			case SDL_MOUSEBUTTONDOWN :
				// Chargement d'un des fichier image
				i = rand() % 8 +1; // i entier aléatoire entre 1 et 8
				sprintf(chaine, "fleur%da.bmp", i);

				fleur = SDL_LoadBMP(chaine);
				if (fleur == NULL)
				{
					fprintf(stderr, "Impossible de charger lee fichier bmp: %s\n", SDL_GetError());
					break;
				}
				SDL_SetAlpha (fleur, SDL_SRCALPHA, 0);
				fleur->format->Amask = 0xFF000000;
				fleur->format->Ashift = 24;
				rect_fleur.x = event.button.x - ((fleur->w)/2);
				rect_fleur.y = event.button.y - fleur->h + 10;
				SDL_BlitSurface (fleur, NULL, ecran, &rect_fleur);
				SDL_Flip (ecran);
				SDL_FreeSurface (fleur);
				break;		
		}
	}


	//Boucle d'attente d'évenement

	/*int continuer = 1;
	SDL_Event event;
	while(continuer)
	{
		SDL_WaitEvent (&event); // attente d'un évènement
		switch (event.type)
		{
			// Cas ou l'on clique sur la croix de fermeture
			case SDL_QUIT : 
				continuer = 0; // On sort du programme
				break;
		}
	}
	*/

	SDL_Quit();
	return EXIT_SUCCESS;
}

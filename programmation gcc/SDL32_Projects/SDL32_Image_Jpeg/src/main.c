#include <SDL.h>					//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
//#include <SDL_image.h>				//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Height_Windows 600
#define Width_Windows 800


// -mwindows rajouter à la fin de la ligne de commande permet de lancer uniquement la fenetre SDL sans la console


void SDL_exit_with_error(const char* message);
void DrawCosSin(int Ampl, int Freq, SDL_Renderer *rdr, int H, int W,char SinCos);
void clean_ressources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t);
SDL_TimerCallback refreshScreen(SDL_Renderer *r);
int Frequency;
int Amplitude;

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Rect RectA;
	SDL_Rect RectImage;
	SDL_Surface *Image = NULL;
	SDL_Texture *Texture = NULL;

/*
	SDL_RENDERER_SOFTWARE
	SDL_RENDERER_ACCELERATED
	SDL_RENDERER_PRESENTVSYNC
	SDL_RENDERER_TARGETTEXTURE
*/

/*-------------------------------------------------------------------------------------------------------------------------*/

int main(int argc,char **argv)
{
	

/*--------InitVideo et timer---------------------------------------------------------------------------------------------------------*/

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		clean_ressources(NULL,NULL,NULL);
		SDL_exit_with_error("initialisation Video");
		exit(EXIT_FAILURE);
	}

/*-------------------------------------------------------------------------------------------------------------------------*/

/*--------Init timer et refresh---------------------------------------------------------------------------------------------------------*/

//SDL_TimerID Montimer = SDL_AddTimer(34, refreshScreen,renderer);

/*-------------------------------------------------------------------------------------------------------------------------*/

/*--------initWindow---------------------------------------------------------------------------------------------------------*/

	window = SDL_CreateWindow("Pemière fenêtre SDL 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width_Windows, Height_Windows,0);
	if(window == NULL)
	{
		SDL_exit_with_error("Erreur : initialisation window");
		clean_ressources(NULL,NULL,NULL);
		exit(EXIT_FAILURE);
		}

/*-------------------------------------------------------------------------------------------------------------------------*/

/*--------Création d'un rendu---------------------------------------------------------------------------------------------------------*/

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if(renderer == NULL)
	{
		SDL_exit_with_error("Erreur : initialisation Rendu");
		clean_ressources(window, NULL, NULL);
		exit(EXIT_FAILURE);
	}
/*-------------------------------------------------------------------------------------------------------------------------*/

/*--------Creation Texture Surface---------------------------------------------------------------------------------------------------------*/

	Image = SDL_LoadBMP("src/planet.bmp");
	//Image = IMG_Load("src/planet.bmp");

	if(Image == NULL)
	{
		clean_ressources(window, renderer, NULL);
		SDL_exit_with_error("Impossible de charger l'image");
		exit(EXIT_FAILURE);
	}

	Texture = SDL_CreateTextureFromSurface(renderer, Image);
	SDL_FreeSurface(Image);

	if(Texture == NULL)
	{
		clean_ressources(window, renderer, NULL);
		SDL_exit_with_error("Impossible de charger la texture");
		exit(EXIT_FAILURE);
	}
/*-------------------------------------------------------------------------------------------------------------------------*/

/*--------Requete texture memoire---------------------------------------------------------------------------------------------------------*/


	if(SDL_QueryTexture(Texture, NULL, NULL, &RectImage.w, &RectImage.h) != 0)
	{
		clean_ressources(window, renderer, Texture);
		SDL_exit_with_error("Erreur lors de la requete de chargement en memoire");
		exit(EXIT_FAILURE);
	}

	RectImage.x = (Width_Windows - RectImage.w)/2;
	RectImage.y = (Height_Windows - RectImage.h)/2;

	if(SDL_RenderCopy(renderer, Texture, NULL, &RectImage) != 0)
	{
		SDL_exit_with_error("Erreur lors de la requete de chargement en memoire");
		clean_ressources(window, renderer, Texture);
		exit(EXIT_FAILURE);
	}
/*-------------------------------------------------------------------------------------------------------------------------*/



/*--------Création de forme et affichage---------------------------------------------------------------------------------------------------------*/

	if(SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
		{	
		SDL_exit_with_error("Erreur Couleur");
		clean_ressources(window, renderer, Texture);
		exit(EXIT_FAILURE);
		}
		

	if(SDL_RenderDrawLine(renderer, 50, 50,500,500) != 0)
		{
		SDL_exit_with_error("Erreur lors du dessein de point");
		clean_ressources(window, renderer, Texture);
		exit(EXIT_FAILURE);
		}


	if(SDL_SetRenderDrawColor(renderer, 255, 20, 10, SDL_ALPHA_OPAQUE) != 0)
		{
		SDL_exit_with_error("Erreur Couleur");
		clean_ressources(window, renderer, Texture);
		exit(EXIT_FAILURE);
		}

	RectA.h = 50;
	RectA.w = 50;
	RectA.x = 400;
	RectA.y = 111;

	if(SDL_RenderFillRect(renderer, &RectA) != 0)
		{
		SDL_exit_with_error("Erreur lors du dessein d'un rectangle");
		clean_ressources(window, renderer, Texture);
		exit(EXIT_FAILURE);
		}

		SDL_bool prog_launched = SDL_TRUE;
		
		while(prog_launched)
		{
			SDL_Event event;
			while(SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					prog_launched = SDL_FALSE;
					break;

				case SDL_KEYUP:
					switch (event.key.keysym.sym)
					{
					case SDLK_DOWN:
						Amplitude -= 1;
						printf("Touche up enfoncer, valeur amp : %d\n", Amplitude);
						continue;

					case SDLK_UP:
						Amplitude +=1;
						printf("Touche down enfoncer, valeur amp : %d\n", Amplitude);
						continue;
					
					default:
						break;
					}

				default:
					break;
				}
			}


			if(SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE) != 0)
			{	
				SDL_exit_with_error("Erreur Couleur");
				clean_ressources(window, renderer, Texture);
				exit(EXIT_FAILURE);
			}

			DrawCosSin(Amplitude , 5 , renderer , 20 , Width_Windows, 0);
			DrawCosSin(Amplitude , 5 , renderer , 20 , Width_Windows, 1);
			SDL_RenderPresent(renderer);
		}


/*-------------------------------------------------------------------------------------------------------------------------*/

/*--------Fermeture SDL---------------------------------------------------------------------------------------------------------*/

	//SDL_Delay(5000);
	clean_ressources(window, renderer, Texture);
	SDL_Quit();
	return EXIT_SUCCESS;

/*-------------------------------------------------------------------------------------------------------------------------*/
}


/*-------------------------------------------------------------------------------------------------------------------------*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------------------------------------------------------------------------------------------------*/



/*-------------------Fonctions-----------------------------------------------------------------------------*/

void SDL_exit_with_error(const char* message)
{
	SDL_Log("Erreur : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}




void DrawCosSin(int Ampl, int Freq, SDL_Renderer *rdr, int H, int W,char SinCos)
{
	int lastPoint;
	int y = H/2;

	if(SDL_SetRenderDrawColor(rdr, 10, 200, 20, SDL_ALPHA_OPAQUE) != 0)
		SDL_exit_with_error("Erreur Couleur");

	for(int i = 0 ; i < (W * H); i++)
	{
		double omega = 6.283 * (double)Freq * ((double)i / (double)W);
		switch(SinCos)
		{
			case 0:
				y += (int)(Ampl * cos(omega));
				break;
			case 1:
				y += (int)(Ampl * sin(omega));
				break;
			default:
				printf("Erreur Aucun type de courbe définie");
				return;
		}
		y += (int)(Ampl * cos(omega));
		if(SDL_RenderDrawPoint(rdr , i , y) != 0)
			SDL_exit_with_error("Erreur lors de l'affichage de la sinusoide");
		if(SDL_RenderDrawLine(rdr,(i-1),lastPoint,i,y) != 0)
			SDL_exit_with_error("Erreur lors de l'affichage de la sinusoide");
		lastPoint = y;
	}
}




void clean_ressources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t)
{
	if(t != NULL)
		SDL_DestroyTexture(t);
	if(r != NULL)
		SDL_DestroyRenderer(r);
	if(w != NULL)
		SDL_DestroyWindow(w);
}

/*
SDL_TimerCallback refreshScreen(uint32_t interval, void *r)
{
	if(SDL_SetRenderDrawColor(r, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
	{	
		SDL_exit_with_error("Erreur Couleur");
		clean_ressources(window, renderer, Texture);
		exit(EXIT_FAILURE);
	}
	SDL_RenderClear(r);
}
*/

/*------------------------------------------------------------------------------------------------*/
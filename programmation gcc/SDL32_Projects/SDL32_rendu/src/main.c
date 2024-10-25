#include <SDL.h>					//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2			//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Height_Windows 600
#define Width_Windows 800


// -mwindows rajouter à la fin de la ligne de commande permet de lancer uniquement la fenetre SDL sans la console


void SDL_exit_with_error(const char* message);
void DrawSin(int Ampl, int Freq, SDL_Renderer *rdr, int H, int W);

/*
	SDL_RENDERER_SOFTWARE
	SDL_RENDERER_ACCELERATED
	SDL_RENDERER_PRESENTVSYNC
	SDL_RENDERER_TARGETTEXTURE
*/

/*-------------------------------------------------------------------------------------------------------------------------*/

int main(int argc,char **argv)
{
	
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Rect RectA;
	SDL_Rect RectImage;
	SDL_Surface *Image = NULL;
	SDL_Texture *Texture = NULL;



/*--------InitVideo*---------------------------------------------------------------------------------------------------------*/

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_exit_with_error("initialisation Video");

/*------------------------------------------------------------------------------------------------------------------------*/


/*--------initWindow---------------------------------------------------------------------------------------------------------*/

	window = SDL_CreateWindow("Pemière fenêtre SDL 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width_Windows, Height_Windows,0);
	if(window == NULL)
		SDL_exit_with_error("Erreur : initialisation window");

/*-------------------------------------------------------------------------------------------------------------------------*/

/*--------Création d'un rendu---------------------------------------------------------------------------------------------------------*/

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if(renderer == NULL)
		SDL_exit_with_error("Erreur : initialisation Rendu");

/*-------------------------------------------------------------------------------------------------------------------------*/

/*--------Creation Texture Surface---------------------------------------------------------------------------------------------------------*/

	Image = SDL_LoadBMP("src/planet.bmp");

	if(Image == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_exit_with_error("Impossible de charger l'image");
	}

	Texture = SDL_CreateTextureFromSurface(renderer, Image);
	SDL_FreeSurface(Image);

	if(Texture == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_exit_with_error("Impossible de charger la texture");
	}
/*-------------------------------------------------------------------------------------------------------------------------*/

/*--------Requete texture memoire---------------------------------------------------------------------------------------------------------*/


	if(SDL_QueryTexture(Texture, NULL, NULL, &RectImage.w, &RectImage.h) != 0)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_exit_with_error("Erreur lors de la requete de chargement en memoire");
	}

	RectImage.x = (Width_Windows - RectImage.w)/2;
	RectImage.y = (Height_Windows - RectImage.h)/2;

	if(SDL_RenderCopy(renderer, Texture, NULL, &RectImage) != 0)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_exit_with_error("Erreur lors de la requete de chargement en memoire");
	}
/*-------------------------------------------------------------------------------------------------------------------------*/


/*--------Création d'un rendu + d'une fenetre en meme temps---------------------------------------------------------------------------------------------------------*/

	//if(SDL_CreateWindowAndRenderer(800,600, 0, &window, &renderer))
		//SDL_exit_with_error("Erreur lors de la création de la fenetre et du rendu");

/*-------------------------------------------------------------------------------------------------------------------------*/


/*--------Création de forme et affichage---------------------------------------------------------------------------------------------------------*/

	if(SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
		SDL_exit_with_error("Erreur Couleur");

	if(SDL_RenderDrawLine(renderer, 50, 50,500,500) != 0)
		SDL_exit_with_error("Erreur lors du dessein de point");

	if(SDL_SetRenderDrawColor(renderer, 255, 20, 10, SDL_ALPHA_OPAQUE) != 0)
		SDL_exit_with_error("Erreur Couleur");

	RectA.h = 50;
	RectA.w = 50;
	RectA.x = 400;
	RectA.y = 111;

	if(SDL_RenderFillRect(renderer, &RectA) != 0)
		SDL_exit_with_error("Erreur lors du dessein d'un rectangle");

	DrawSin(400 , 100000 , renderer , 220 , Width_Windows);


	SDL_RenderPresent(renderer);
/*-------------------------------------------------------------------------------------------------------------------------*/

/*--------Fermeture SDL---------------------------------------------------------------------------------------------------------*/

	SDL_Delay(5000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(Texture);
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


void DrawSin(int Ampl, int Freq, SDL_Renderer *rdr, int H, int W)
{
	if(SDL_SetRenderDrawColor(rdr, 10, 200, 20, SDL_ALPHA_OPAQUE) != 0)
		SDL_exit_with_error("Erreur Couleur");

	for(int i = 0 ; i < (W * H); i++)
	{
		double omega = 6.283 * (double)Freq * ((double)i / (double)W);
		int y = H/2 +  (int)(Ampl * sin(omega));
		if(SDL_RenderDrawPoint(rdr , (i/4) , y) != 0)
			SDL_exit_with_error("Erreur lors de l'affichage de la sinusoide");
	}
}

/*------------------------------------------------------------------------------------------------*/
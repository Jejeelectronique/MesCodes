#include <SDL.h>					//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
#include <SDL_image.h>				//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Height_Windows 600
#define Width_Windows 800


// -mwindows rajouter à la fin de la ligne de commande permet de lancer uniquement la fenetre SDL sans la console

#define FPSlimits 16


void SDL_exit_with_error(const char* message);
void SDL_Limit_FPS(unsigned int limit);
/*
	SDL_RENDERER_SOFTWARE
	SDL_RENDERER_ACCELERATED
	SDL_RENDERER_PRESENTVSYNC
	SDL_RENDERER_TARGETTEXTURE
*/
//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows			//Lance uniquement la fenetre SDL sans la ligne de commande


/*-------------------------------------------------------------------------------------------------------------------------*/

int main(int argc,char **argv)
{
	
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;



/*--------InitVideo*---------------------------------------------------------------------------------------------------------*/

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_exit_with_error("initialisation Video");

/*-------------------------------------------------------------------------------------------------------------------------*/


/*--------initWindow---------------------------------------------------------------------------------------------------------*/

	window = SDL_CreateWindow("Pemière fenêtre SDL 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width_Windows, Height_Windows,0);
	if(window == NULL)
		SDL_exit_with_error("Erreur : initialisation window");

/*-------------------------------------------------------------------------------------------------------------------------*/



SDL_bool prog_launched = SDL_TRUE;

while(prog_launched)
{
	SDL_Event event;
	
	while(SDL_PollEvent(&event))			//s'éxecute uniquement quand un event est détecter, cette une fonction non bloquante contrairement à SDL_WaitEvent(&event)
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_b:
				printf("Vous avez appuyer sur B\n");
				continue;
			
			default:
				break;
			}

		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_b:
				printf("vous avez relacher B\n");
				continue;
			
			default:
				break;
			}

		case SDL_MOUSEMOTION:	//event.motion.x
			printf("souris en : %d /  %d\n" , event.motion.x, event.motion.y);
			break;

		case SDL_MOUSEBUTTONDOWN:	//event.motion.x
			if(event.button.clicks >= 2)
			printf("clique en : %d /  %d\n" , event.button.x, event.button.y);
			break;



		case SDL_QUIT:
			prog_launched = SDL_FALSE;
			break;

		case SDL_WINDOWEVENT: //SDL_SYSWMEVENT event systeme
			if(event.window.event == SDL_WINDOWEVENT_LEAVE)
				printf("La souris est sortie de la fenetre.\n");
			if(event.window.event == SDL_WINDOWEVENT_ENTER)
				printf("La souris est rentrer dans la fenetre.\n");
			break;
		
		default:
			continue;
		}
	}
}


/*----------------------------------------------------------------------------------------------------------------------*/

/*--------Fermeture SDL---------------------------------------------------------------------------------------------------------*/

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
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




void SDL_Limit_FPS(unsigned int limit)
{
	unsigned int ticks = SDL_GetTicks();

	if(limit < ticks)
		return;
	else if(limit > (ticks + FPSlimits))
		SDL_Delay(FPSlimits);
	else
		SDL_Delay(limit - ticks);
}

/*------------------------------------------------------------------------------------------------*/
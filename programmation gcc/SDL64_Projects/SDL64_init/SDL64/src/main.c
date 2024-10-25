#include <SDL.h>					//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
// #include <SDL_image.h>				//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Height_Windows 600
#define Width_Windows 800


// -mwindows rajouter à la fin de la ligne de commande permet de lancer uniquement la fenetre SDL sans la console

int main(int argc,char **argv)
{
	SDL_Window *window = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Erreur : initialisation SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	//Execution du programme
	window = SDL_CreateWindow("Pemière fenêtre SDL 2",
							   SDL_WINDOWPOS_CENTERED,
							   SDL_WINDOWPOS_CENTERED,
							   800,
							   600,
							   0);

	if(window == NULL)
	{
		SDL_Log("Erreur : initialisation SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Delay(5000);

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}


//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
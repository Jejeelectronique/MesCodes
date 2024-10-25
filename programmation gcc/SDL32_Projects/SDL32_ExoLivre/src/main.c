#include <SDL.h>					//éze ;compile la biblio personnalisé avec
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL_MySDL.h"

#define Height_Windows 600
#define Width_Windows 800


// -mwindows rajouter à la fin de la ligne de commande permet de lancer uniquement la fenetre SDL sans la console
/*
	SDL_RENDERER_SOFTWARE
	SDL_RENDERER_ACCELERATED
	SDL_RENDERER_PRESENTVSYNC
	SDL_RENDERER_TARGETTEXTURE
*/


typedef struct MonRendu{
	char Rouge; 
	char Bleu;
	char Vert;

}MonRendu;


MonRendu CouleurRendu = {200, 120, 80};

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *Surface = NULL;
SDL_bool ProgInProgress = SDL_TRUE;
SDL_Color MySdlColor  = {170,170,170,SDL_ALPHA_OPAQUE};


/*-------------------------------------------------------------------------------------------------------------------------*/
int main(int argc,char *argv[])
{
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0){fprintf(stderr, "Erreur initialisation SDL %s\n" , SDL_GetError()); exit(EXIT_FAILURE);}


	Surface = SDL_CreateRGBSurface(0,50,50,20,255,255,255,255);
	window = SDL_CreateWindow("Mon Jeu", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Width_Windows,Height_Windows,0);

	if(window == NULL)
		SDL_exit_with_error("Echec creation de fenetre");

	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
	if(renderer == NULL)
		SDL_exit_with_error("Echec lors de la creaetion du rendu");

	if(SDL_SetRenderDrawColor(renderer, CouleurRendu.Rouge, CouleurRendu.Vert, CouleurRendu.Bleu, SDL_ALPHA_OPAQUE) != 0)
		SDL_exit_with_error("Erreur Couleur");

	
	

	while(ProgInProgress)
	{
		DrawCosSin(50,10,renderer,Height_Windows,Width_Windows,0);
		// Refreshframe(renderer);

		// TimerIntervalInterruptInit(5000,QuitterProgramme);
		// CallFunc(backScreenWrapper, "Test");
		LeaveProg();
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	free(Surface);
	SDL_Quit();
	return EXIT_SUCCESS;
}

// int backScreen(SDL_Renderer *rdr,SDL_Color *clr)
// {
// 	if(SDL_SetRenderDrawColor(rdr, clr->r, clr->g, clr->b, clr->a) != 0)
// 	{
// 		SDL_exit_with_error("Erreur Couleur");
// 		return 1;
// 	}

// 	if(SDL_RenderClear(rdr) != 0)
// 	{
// 		SDL_exit_with_error("Erreur Effacement rendue");
// 		return 1;
// 	}

// 	return 0;

// }

// void CallFunc(int (*f)(void) , const char* MesErreur)
// {
// 	if((f)() != 0)
// 	{
// 		SDL_Log("Erreur ligne %d : [%s] SDL_GetError : %s\n ,", __LINE__,  MesErreur, SDL_GetError());
// 		SDL_Quit();
// 		exit(EXIT_FAILURE);
// 	}
// }

// void CallFuncWithArgs(int (*f)(SDL_Renderer*, SDL_Color*), SDL_Renderer *rdr, SDL_Color *clr, const char* MesErreur)
// {
//     if (f(rdr, clr) != 0)
//     {
//         SDL_Log("Erreur ligne %d : [%s] SDL_GetError : %s\n", __LINE__, MesErreur, SDL_GetError());
//         SDL_Quit();
//         exit(EXIT_FAILURE);
//     }
// }

// int backScreenWrapper(void)
// {
//     return backScreen(renderer, &MySdlColor);
// }


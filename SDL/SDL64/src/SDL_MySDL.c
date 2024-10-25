#include "SDL_MySDL.h"

SDL_TimerCallback Mycallback;


SDL_TimerID TimerIntervalInterruptInit(Uint32 interval,void* Ma_fonction_a_executer)
{
	return SDL_AddTimer(interval,Mycallback,Ma_fonction_a_executer);
}

void QuitterProgramme()
{
	ProgInProgress = SDL_FALSE;
}


void LeaveProg()
{
	SDL_Event Monevent;
		SDL_PollEvent(&Monevent);
		if(Monevent.type == SDL_QUIT)
			ProgInProgress = SDL_FALSE;
}

void SDL_exit_with_error(const char* message)
{
	SDL_Log("Erreur : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}

void DrawCosSin(int Ampl, unsigned int Freq, SDL_Renderer *rdr, int H, int W,char SinCos)
{
	int lastPoint;
	int y = H/2;
	if(SDL_SetRenderDrawColor(rdr, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0){SDL_Log("Erreur : initialisation SDL SC1 > %s\n", SDL_GetError());exit(EXIT_FAILURE);}
	for(int i = 0 ; i < (W); i++)
	{
		double omega = (6.283 * (double)Freq) * ((double)i / (double)W);
		switch(SinCos)
		{
			case 0:
				y = (int)(Ampl * cos(omega)) + H/2;
				break;
			case 1:
				y = (int)(Ampl * sin(omega)) + H/2;
				break;
			default:
				printf("Erreur Aucun type de courbe définie");
				return;
		}
		if(SDL_RenderDrawLine(rdr,(i-1),lastPoint,i,y) != 0){SDL_Log("Erreur : initialisation SDL SC2> %s\n", SDL_GetError());exit(EXIT_FAILURE);}
		lastPoint = y;
	}
}

void RefreshFrame(int Delays,int *timerNow,int *lastTimer,void (*f)(void))
{
	*timerNow = SDL_GetTicks64();
	if((TimerNow  - LastTimer) >= Mydelais)
	{
		*lastTimer = SDL_GetTicks64();
		(*f)();
	}
	Frame = SDL_TRUE;
}



void backScreen()
{
	Mycolor.g = 54; Mycolor.r = 25; Mycolor.b =36; Mycolor.a = 66;
	SDL_SetRenderDrawColor(rdr,Mycolor.r,Mycolor.g,Mycolor.b,Mycolor.a);
	SDL_RenderClear(rdr);
}



void Degrader()
{
	for (int i = 0; i < Height_Windows; i++)
	{
		MyRect.h = 1; MyRect.w = Width_Windows; MyRect.x = 0; MyRect.y=i;
		Mycolor.r = (255 - ((i*255)/Height_Windows)); Mycolor.g = ((i*255)/Height_Windows); Mycolor.b = 0; Mycolor.a = SDL_ALPHA_TRANSPARENT;
		SDL_SetRenderDrawColor(rdr,Mycolor.r,Mycolor.g,Mycolor.b,Mycolor.a);
		SDL_RenderFillRect(rdr,&MyRect);
	}
}	












/*------commande muiltithreading-------------------------------------------------------------------*/

/*--------INIT--------------------*/
// HANDLE hTread;									//Multithreading
// DWORD WINAPI MonThread(LPVOID lParam);			//Multithreading

/*--------Main-----------*/
// hTread = CreateThread(NULL,0,MonThread,NULL,0,NULL); if (hTread == NULL) {printf("Erreur lors de la création du thread\n"); return 1;}


/*----------While---------------*/
// WaitForSingleObject(hTread,INFINITE);		//Multithreading
// CloseHandle(hTread);							//Multithreading

// DWORD WINAPI MonThread(LPVOID lParam)
// {
// 	DrawCosSin(Amplitude, Frequence,rdr,Height_Windows,Width_Windows,1);
// 	return 0;
// }
//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
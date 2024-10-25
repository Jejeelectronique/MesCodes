#include "SDL_MySDL.h"

SDL_TimerCallback Mycallback;
SDL_bool ProgInProgress = SDL_TRUE;


void TimerIntervalInterruptInit(Uint32 interval,void* Ma_fonction_a_executer)
{
	Mycallback = MytimmerCallBack;
	SDL_AddTimer(interval,Mycallback,Ma_fonction_a_executer);
}

Uint32 MytimmerCallBack(Uint32 interval, void *param)	//Fonction timercallback qui s'éxecute via une interruption lorsque l'interval est depasser et prend un 
{
	void(*quitfonction)(void*) = param;
	quitfonction(NULL);
	return interval;
}

void QuitterProgramme(void *param)		//fonction appeler et executer par le pointeur de fonction *param
{
	ProgInProgress = SDL_FALSE;
}

void TestPrintF()
{
	printf("Salut\n");
}
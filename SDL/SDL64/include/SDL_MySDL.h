#ifndef __SDL_MySDL_h
#define __SDL_MySDL_h

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


SDL_TimerID TimerIntervalInterruptInit(Uint32 interval,void* Ma_fonction_a_executer);
Uint32 MytimmerCallBack(Uint32 interval, void *param);
void QuitterProgramme();
void LeaveProg();
void SDL_exit_with_error(const char* message);
void DrawCosSin(int Ampl, unsigned int Freq, SDL_Renderer *rdr, int H, int W,char SinCos);
void RefreshFrame(int Delays,int *timerNow,int *lastTimer,void (*f)(void));
void backScreen();
void Degrader();

extern SDL_bool ProgInProgress;

#endif

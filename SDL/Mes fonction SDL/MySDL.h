#ifndef __MY__SDL_H
#define __MY__SDL_H

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

void TimerIntervalInterruptInit(Uint32 interval,void* Ma_fonction_a_executer);
Uint32 MytimmerCallBack(Uint32 interval, void *param);
void QuitterProgramme(void *param);

SDL_TimerCallback Mycallback;

#endif

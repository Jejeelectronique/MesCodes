#ifndef __SDL_MySDL_h
#define __SDL_MySDL_h

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum StateBtn{
    NoKey,
    Zkey,
    Skey,
    Qkey,
    Dkey
}StateBtn;


SDL_TimerID TimerIntervalInterruptInit(Uint32 interval,void* Ma_fonction_a_executer);
SDL_bool LeaveProg(SDL_Event *Monevent);
SDL_bool TimerCompare(Uint64 Delays,Uint64 *timerNow,Uint64 *lastTimer);
SDL_bool CallFunction(void (*f)(), SDL_Renderer *rdr, SDL_Color *Mycolor);


void SDL_exit_with_error(const char* message);
void DrawCosSin(int Ampl, unsigned int Freq, SDL_Renderer *rdr, int H, int W,char SinCos);
void RefreshFrame(int Delays,int *timerNow,int *lastTimer,void (*f)(void));
void backScreen(SDL_Renderer *rdr, SDL_Color *Mycolor);
void Degrader(SDL_Rect *Rec, SDL_Color *Mycolor,SDL_Renderer *rdr, SDL_Window *Wdw);
void DeplacementPerso(StateBtn StBtn, unsigned char *Dep, SDL_Rect *PositionPerso, unsigned int Height_Windows, unsigned int Width_Windows);
void IncreaseDep(StateBtn *StBtn, Uint16 *CtrlKey, Uint16 *CtrlRealeaseKey, Uint8 *Dep, Uint8 MaxdDep, Uint8 MinDep, Uint16 delaysAppuie, Uint8 FPS);
void PrintImage(SDL_Renderer *rdr,SDL_Texture *texture,SDL_Rect *rect);
void CleanAndDestroy(SDL_Renderer *rdr, SDL_Window *wdw, SDL_Surface *surf, SDL_Texture *txt);




extern SDL_bool ProgInProgress;

#endif

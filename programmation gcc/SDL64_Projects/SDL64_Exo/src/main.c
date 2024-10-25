#include <SDL.h>					//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
//#include <SDL_image.h>				//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <Windows.h>					//Multithreading

#define Mydelais 30

#define Height_Windows 600
#define Width_Windows 800

void RefreshFrame();
void backScreen();
void DrawCosSin(int Ampl, unsigned int Freq, SDL_Renderer *rdr, int H, int W,char SinCos);
void MyPersonnage(unsigned int PosX, unsigned int PosY);
void RefreshFrame(int Delays,int *timerNow,int *lastTimer,void (*f)(void));
void Degrader();
void My_DrawCircle(SDL_Renderer *rdr,unsigned int radius, unsigned int PosX, unsigned int PosY);

int Amplitude = 10, Frequence = 50, Hscreen = Height_Windows, Wscreen = Width_Windows;

SDL_TimerCallback Mytimer;
// -mwindows rajouter à la fin de la ligne de commande permet de lancer uniquement la fenetre SDL sans la console
SDL_bool ProgramEnCours = SDL_TRUE;
SDL_Window *window = NULL;
SDL_Surface *surf = NULL;
SDL_Renderer *rdr = NULL;
SDL_Event event;
SDL_Rect MyRect;
SDL_Color Mycolor;
SDL_PixelFormat Myformat;
SDL_Rect Mymonster;
SDL_bool Frame = SDL_FALSE;

// HANDLE hTread;									//Multithreading
// DWORD WINAPI MonThread(LPVOID lParam);			//Multithreading

int TimerNow;
int LastTimer;

int Perso[50][20];

int main(int argc,char **argv)
{
	// hTread = CreateThread(NULL,0,MonThread,NULL,0,NULL); if (hTread == NULL) {printf("Erreur lors de la création du thread\n"); return 1;}

	window = SDL_CreateWindow("Pemière fenêtre SDL 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0); if(window == NULL){SDL_Log("Erreur : initialisation SDL I1 > %s\n", SDL_GetError()); exit(EXIT_FAILURE);}
	rdr = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE); if(rdr == NULL){SDL_Log("Erreur rendu I2 > %s\n", SDL_GetError());}

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0){SDL_Log("Erreur : initialisation SDL I3 > %s\n", SDL_GetError()); exit(EXIT_FAILURE);}

	Mycolor.g = 54; Mycolor.r = 25; Mycolor.b =36; Mycolor.a = 66;
	Mymonster.h = 36; Mymonster.w = 77; Mymonster.x = 88; Mymonster.y = 55;

	SDL_SetRenderDrawColor(rdr,Mycolor.r,Mycolor.g,Mycolor.b,Mycolor.a);
	SDL_RenderClear(rdr);
	SDL_SetRenderDrawColor(rdr,0,245,89,Mycolor.a);
	SDL_RenderDrawLine(rdr,44,10,55,66);
	SDL_RenderPresent(rdr);
	LastTimer = SDL_GetTicks64();

/* -------------------Execution programme---------------------------------------------------------------------------------------------------------------------------- */
	while(ProgramEnCours)
	{
		SDL_PollEvent(&event);
		
		switch (event.type)
		{ 
		case SDL_QUIT :
			ProgramEnCours = SDL_FALSE;
			break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_DOWN :
					Amplitude --;
					break;

				case SDLK_UP :
					Amplitude ++;
					break;
					
				case SDLK_LEFT :
					Frequence --;
					break;
				
				case SDLK_RIGHT :
					Frequence ++;
					break;

				default:
					break;
			}
		default:
			break;
		}

		RefreshFrame(Mydelais,&TimerNow,&LastTimer,backScreen);			//Effacement de la frame precedente
		if(Frame)	//Affichage de la prochaine frame
		{
			// WaitForSingleObject(hTread,INFINITE);		//Multithreading
			// CloseHandle(hTread);							//Multithreading
			Degrader();
			DrawCosSin(Amplitude, Frequence,rdr,Height_Windows,Width_Windows,1);
			MyPersonnage(12,15);
			My_DrawCircle(rdr,250,300,200);


			SDL_RenderPresent(rdr);			//Affichage du rendu
			Frame = SDL_FALSE;
		}
	}



	free(surf);
	SDL_DestroyRenderer(rdr);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
/* ----------------------------------------------------------------------------------------------------------------------------------------------- */





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

void MyPersonnage(unsigned int PosX, unsigned int PosY)
{
	PosX % Width_Windows;
	PosY % Height_Windows;
	//Fonctions rectangle manuel
	// SDL_SetRenderDrawColor(rdr,255,245,89,Mycolor.a);
	// SDL_RenderDrawLine(rdr,PosX,PosY,PosX,(PosY + 10));
	// SDL_RenderDrawLine(rdr,PosX,PosY,(PosX+10),PosY);
	// SDL_RenderDrawLine(rdr,PosX,(PosY + 10),(PosX + 10),(PosY + 10));
	// SDL_RenderDrawLine(rdr,(PosX + 10),PosY,(PosX + 10),(PosY + 10));

	MyRect.h = 22; MyRect.w = 20; MyRect.x = PosX; MyRect.y = PosY;
	SDL_RenderDrawRect(rdr, &MyRect);
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




void My_DrawCircle(SDL_Renderer *rdr,unsigned int radius, unsigned int PosX, unsigned int PosY)
{	
	unsigned int Diam = radius * 2;
	unsigned int PosXa = PosX - radius;
	
	unsigned int y = 0;
	unsigned int Tbarre = 0;
	unsigned int lastPoint = 0;

	SDL_SetRenderDrawColor(rdr,255,255,255,0);

	for(int i = 0; i < Diam; i++)
	{
		y = (int)(radius*sin(1  - (3.14/(3.14 - i))));

		if(SDL_RenderDrawLine(rdr,(PosXa + i),lastPoint,i,y) != 0){SDL_Log("Erreur : initialisation SDL DC1> %s\n", SDL_GetError());exit(EXIT_FAILURE);}
		lastPoint = y;
	}
}





//Multithreading
// DWORD WINAPI MonThread(LPVOID lParam)
// {
// 	DrawCosSin(Amplitude, Frequence,rdr,Height_Windows,Width_Windows,1);
// 	return 0;
// }
//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
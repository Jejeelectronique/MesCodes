#ifndef __SDL_MySDL_h
#define __SDL_MySDL_h

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#define MAXSIZEBUFFER 255

typedef enum StateBtn{
    NoKey,
    Zkey,
    Skey,
    Qkey,
    Dkey
}StateBtn;

typedef struct PanelBouton
{
    SDL_Rect Rect_Bouton;
    SDL_Rect Rect_Texte;
    SDL_Color Bouton_Color;
    SDL_Color Texte_Color;
    SDL_Surface *Surface_Texte;
    SDL_Texture *Texture_Texte;
    TTF_Font *Font;
    char Texte[255];
}PanelBtn;

#pragma pack(push, 1)  // Désactive l’alignement de la mémoire
// Structure pour écrire l'en-tête d'un fichier WAV
typedef struct {
    char riff[4];               // "RIFF"
    uint32_t chunk_size;        // Taille du fichier - 8
    char wave[4];               // "WAVE"
    char fmt[4];                // "fmt "
    uint32_t subchunk1_size;    // Taille du sous-chunk (16 pour PCM)
    uint16_t audio_format;      // Format audio (1 pour PCM)
    uint16_t num_channels;      // Nombre de canaux
    uint32_t sample_rate;       // Fréquence d'échantillonnage
    uint32_t byte_rate;         // SampleRate * NumChannels * BitsPerSample/8
    uint16_t block_align;       // NumChannels * BitsPerSample/8
    uint16_t bits_per_sample;   // Bits par échantillon
    char data[4];               // "data"
    uint32_t subchunk2_size;    // Nombre d'octets de données audio
} WAVHeader;
#pragma pack(pop)  // Rétablit l’alignement par défaut

void SaveWAV(const char *filename, Uint8 *buffer, Uint32 length, SDL_AudioSpec *spec);



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
SDL_bool PanelButon(SDL_Renderer *render, PanelBtn Panel);



extern SDL_bool ProgInProgress;

#endif

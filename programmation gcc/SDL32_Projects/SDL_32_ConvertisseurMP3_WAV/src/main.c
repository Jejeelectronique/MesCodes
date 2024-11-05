#include "ConvertMP3_WAV.h"
#include <SDL.h>					//gcc src/main.c src/SDL_MySDL.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2
#include <stdio.h>					//gcc src/main.c src/SDL_MySDL.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
#include <stdlib.h>
#include <SDL_mixer.h>
#include <string.h>


int GoTo_section(char* section, FILE *streamFile);
int GoTo_line(char* Line_to_search, char* PATH_file_l,FILE *streamFile);
int Write_log(FILE* streamLog, char* arg);

int Min_to_Maj(char* buffsrc);
int replaceChar(char** buffer, char* endFileType);
int RemoveSubstring(char* HubString, char* DestString,char* SubString);

char Section_ini_g[MAX_SIZE_BUFFER] = {SECTION_PATH};
char Line_ini_g[MAX_SIZE_BUFFER] = {LINE_PATH};
char Path_file_save[MAX_SIZE_BUFFER];
char EndType[5] = {END_TYPE_FILE};

int main(int argc,char **argv)
{   
    char file_path[2500];
    // Vérifier si des arguments ont été passés
    if (argc < 2) {
        fprintf(stderr, "Aucun fichier spécifié.\n");
        return EXIT_FAILURE;
    }
    replaceChar(argv, "MP3");


    Uint8 *audio_buffer = NULL;
    Uint32 audio_length;
    SDL_AudioSpec wav_spec;
    Mix_Chunk *chunk = NULL;
    FILE *streamINI_l = NULL, *LogFile;
    char *line_l = NULL;

    wav_spec.freq = 44100;
    wav_spec.format = AUDIO_S16LSB;                         // Format WAV 16 bits
    wav_spec.channels = 2;                                  // Stéréo
    wav_spec.samples = 2048;

    if((LogFile = fopen(LOG_PATH , "w")) == NULL)
        ERRCHK("Erreur ouverture fichier log");

    if(Write_log(LogFile, argv[1]) != 0)
        ERRCHK("Erreur ecriture des logs");

    if((streamINI_l = fopen(INI_PATH , "r+")) == NULL)
        ERRCHK("Erreur ouverture fichier ini");

    if((GoTo_section(Section_ini_g, streamINI_l)) != 0)
        ERRCHK("Section introuvable");
    
    if(GoTo_line(Line_ini_g, Path_file_save, streamINI_l) != 0)
        ERRCHK("Ligne introuvable");

    if(SDL_Init(SDL_INIT_AUDIO) != 0)
        ERRCHK("Erreur init de l'audio");

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)	
        ERRCHK("Erreur chargement de l'audio : %s");

	if( (chunk = Mix_LoadWAV(argv[1])) == NULL)
        ERRCHK("Erreur chargement du chunk");

    audio_buffer = chunk->abuf;
    audio_length = chunk->alen;          

    // Sauvegarde des données audio en fichier WAV
    if(Sauvegarde_WAV(Path_file_save, audio_buffer, audio_length, &wav_spec) != 0)
        ERRCHK("Erreur sauvegarde fichier");



    fclose(streamINI_l);
    free(streamINI_l);
    streamINI_l = NULL;

    fclose(LogFile);
    free(LogFile);
    LogFile = NULL;    

    Mix_FreeChunk(chunk);
    free(chunk);
    chunk = NULL;

    Mix_CloseAudio();
    SDL_Quit();

    return EXIT_SUCCESS;
    return 0;


erreur :

    if(chunk != NULL)
    {
        Mix_FreeChunk(chunk);
        free(chunk);
        chunk = NULL;
    }
    
    if(streamINI_l != NULL)
    {
        fclose(streamINI_l);
        free(streamINI_l);
        streamINI_l = NULL;
    }

    if(LogFile != NULL)
    {
        fclose(LogFile);
        free(LogFile);
        LogFile = NULL;        
    }

    Mix_CloseAudio();
    SDL_Quit();
    exit(EXIT_FAILURE);
    return 0;
}




// 




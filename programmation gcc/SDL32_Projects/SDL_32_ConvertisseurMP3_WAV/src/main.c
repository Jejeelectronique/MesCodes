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


int GoTo_section(char* section, FILE *streamFile)
{
    char Line_L[255];

    for(int i = 0; i < 65500; i++)
    {
        fgets(Line_L, 255, streamFile);
        if(Min_to_Maj(Line_L) != 0)
            return -1;

        if((strcmp(section, Line_L)) == 0)
            return 0;

        if(feof(streamFile) != 0)
        {
            printf("fin du fichier atteint");
            return -1;
        }
    }
    printf("fihcier ini depassant le nombre de caractere max \n");
    return -1;
}




int GoTo_line(char* Line_to_search, char* PATH_file_l, FILE *streamFile)
{
    char Line_file_l[MAX_SIZE_BUFFER];

    size_t length_Line_file_l, length_Line_l;
    length_Line_l = strlen(Line_to_search);
    length_Line_file_l = strlen(Line_to_search);

    if(Min_to_Maj(Line_to_search) != 0)
        return -1;

    for(int i = 0; i < 65500; i++)
    {
        fgets(Line_file_l, 255, streamFile);
        if(Line_file_l == NULL)
        {
            printf("fichier vide\n");
            return -1;
        }

        if(Min_to_Maj(Line_to_search) != 0)
        {
            printf("Erreur maj to min\n");
            return -1;
        }

        if(strcmp(Line_to_search , Line_file_l) == 0)
            break;

        if(feof(streamFile) != 0)
            break;

        if(i == (65500 - 1))
        {
            printf("iteration max depasser\n");
            return -1;
        }
    }
  
    strncat(Line_to_search, CONST_EQUAL, length_Line_file_l);
    RemoveSubstring(Line_file_l, PATH_file_l, Line_to_search);

    /*Assure la terminaison .wav si celle-ci n'as pas étais rentrer dans le fichier ini*/
    length_Line_file_l = strlen(PATH_file_l);
    for(int i = 0; i < 4; i++)
    {
        if(PATH_file_l[length_Line_file_l - 4 + i] != EndType[i]) 
        {
            strncat(PATH_file_l, END_TYPE_FILE, length_Line_file_l);
            break;
        }
    }
    printf("path to save : %s\n", PATH_file_l);
    return 0;
}




int Min_to_Maj(char* buffsrc)
{   
    if(buffsrc == NULL)
    {
        printf("chaine vide");
        return -1;
    }

    for(int i = 0; buffsrc[i] != '\0'; i++)
    {
       if((buffsrc[i] <= 'z') && (buffsrc[i] >= 'a'))
            buffsrc[i] -= 32;

        if(i >= 255) 
        {
            printf("erreur conv maj to min");
            return -1;
        }
    }
    return 0;
}



int Maj_to_Min(char* buffsrc)
{   
    if(buffsrc == NULL)
    {
        printf("chaine vide");
        return -1;
    }

    for(int i = 0; buffsrc[i] != '\0'; i++)
    {
       if((buffsrc[i] <= 'Z') && (buffsrc[i] >= 'A'))
            buffsrc[i] += 32;

        if(i >= 255) 
        {
            printf("erreur conv maj to min");
            return -1;
        }
    }
    return 0;
}




int replaceChar(char** buffer, char* endFileType)
{
    int a, b = 0;
    for(int i = 0; i < 65500; i++)
    {
        if(buffer[1][i] == '\\')
            buffer[1][i] = '/';
        if(buffer[1][i] == '.')
        {
            a = i + 1;
            break;
        }
        if(buffer[1][i] == '\0')
        {
            printf("erreur lors du remplacement du caractere");
            return -1;
        }
    }
    for(int i = a ; i < (a + 4); i++)
    {
        buffer[1][i] = endFileType[b];
        b++;
    }
    return 0;
}




int RemoveSubstring(char* HubString, char* DestString, char* SubString)
{
    Min_to_Maj(SubString);
    Min_to_Maj(HubString);
    unsigned int index_i = 0;
    unsigned char found = 0;

    size_t SizeS_HubString_l = strlen(HubString);
    size_t Size_Substring_l = strlen(SubString);

    for(int i = 0; i < (SizeS_HubString_l - Size_Substring_l); i++)
    {
        for(int j = 0; j < Size_Substring_l; j++)
        {
            if(HubString[i + j] != SubString[j])
                break;

            if(j >= (Size_Substring_l -1))
            {
                index_i = i;
                found = 1;
            }
        }

        if(found != 0)
            break;
    }

    DestString[SizeS_HubString_l - Size_Substring_l] = '\0';
    for(int a = 0; a < (SizeS_HubString_l - Size_Substring_l); a++)
        DestString[a] = HubString[index_i + Size_Substring_l + a];
    
    SizeS_HubString_l = strlen(DestString);

    memcpy(HubString, DestString, SizeS_HubString_l);
    
    return 0;
}

int Write_log(FILE* streamLog, char* arg)
{
    if((fputs(arg, streamLog)))
        return -1;
    return 0;
}
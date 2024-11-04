#include "ConvertMP3_WAV.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>



int Sauvegarde_WAV(const char *filename, Uint8 *buffer, Uint32 length, SDL_AudioSpec *spec) 
{   
    FILE *file = NULL; 

    if((file = fopen(filename, "wb")) == NULL)                                          {fprintf(stderr, "Erreur lors de la création du fichier WAV : %s\n", SDL_GetError()); return -1;}
    WAVHeader header;
    // Remplir l'en-tête WAV
    memcpy(header.riff, "RIFF", 4);
    header.chunk_size = 36 + length;
    memcpy(header.wave, "WAVE", 4);
    memcpy(header.fmt, "fmt ", 4);
    header.subchunk1_size = 16;
    header.audio_format = 1;  // Format PCM
    header.num_channels = spec->channels;
    header.sample_rate = spec->freq;
    header.bits_per_sample = SDL_AUDIO_BITSIZE(spec->format);
    header.byte_rate = spec->freq * spec->channels * header.bits_per_sample / 8;
    header.block_align = spec->channels * header.bits_per_sample / 8;
    memcpy(header.data, "data", 4);
    header.subchunk2_size = length;
    // Écrire l'en-tête et les données audio
    fwrite(&header, sizeof(WAVHeader), 1, file);
    fwrite(buffer, length, 1, file);
    

    printf("Sauvegarde du fichier wav dans : \n [\"%s\"]\n", filename);
    fclose(file);
    free(file);
    file = NULL; 
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
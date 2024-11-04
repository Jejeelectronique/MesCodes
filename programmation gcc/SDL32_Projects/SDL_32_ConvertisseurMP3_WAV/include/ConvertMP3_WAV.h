#ifndef __CONVERTMP3_WAV__
#define __CONVERTMP3_WAV__

#define MAX_SIZE_BUFFER 255
#define SECTION_PATH "[CHEMIN]\n"
#define LINE_PATH "SAVE_PATH"
#define CONST_EQUAL " = "
#define END_TYPE_FILE ".WAV\0"
#define INI_PATH "bin/MP3_to_WAV_Convert.ini"
#define LOG_PATH "bin/MP3_to_WAV_Convert.log"

#include <SDL.h>					//gcc src/main.c src/SDL_MySDL.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2
#include <stdio.h>					//gcc src/main.c src/SDL_MySDL.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
#include <stdlib.h>
#include <SDL_mixer.h>
#include <string.h>

#define ERRCHK(MessErr) do{                                                 \
                            fprintf(stderr, "erreur : %s\n" , MessErr);     \
                            goto erreur;                                    \
                        }while(0);

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

// Préparer les données pour la conversion en WAV

int Sauvegarde_WAV(const char *filename, Uint8 *buffer, Uint32 length, SDL_AudioSpec *spec);
int Write_log(FILE* streamLog, char* arg);
int RemoveSubstring(char* HubString, char* DestString, char* SubString);
int replaceChar(char** buffer, char* endFileType);
int Maj_to_Min(char* buffsrc);
int Min_to_Maj(char* buffsrc);
int GoTo_section(char* section, FILE *streamFile);
int GoTo_line(char* Line_to_search, char* PATH_file_l, FILE *streamFile);

#endif
#ifndef Sauvegarde_h
#define Sauvegarde_h

#include "Arduino.h"
#include <EEPROM.h>

#define TaillePaquets 8

void SaveData(int DataToSave, byte NombresPaquets,byte MemAdr);
void ResetData(byte NombresPaquets, byte MemAdr);
int LectureData(byte NombresPaquets, byte MemAdr);

#endif
#include "Sauvegarde.h"

void SaveData(int DataToSave, byte NombresPaquets,byte MemAdr)						//Fonction de sauvegarde de data dépassant 8bits
{
	for (int i=0;i<NombresPaquets;i++)												//on éffectue l'opération pour le nombre de paquet (octet) ex: un entier de 16 bits contient 2 octets, il faut donc mettre 2 paquets
  	{
  		EEPROM.put((MemAdr + i), ((DataToSave >> (i*TaillePaquets)) & (0xFF)));		//on stocke dans la valeur à sauvegarder à l'adresse spécifié qu'on incrémentera jusqu'a compléter les paquets, et on éffectue une opération de décalage et de masquage de bits pour "découper" et stocker les bits
  	}
}

void ResetData(byte NombresPaquets, byte MemAdr)									//Fonction de réinitialisation des données stocker dans l'EEPROM				
{
	for (int i=0;i<NombresPaquets;i++)												//Pour chaque paquets on éffectue l'opération de reset
	{
		EEPROM.put((MemAdr + i), 0);												//on mets chaque index de la mémoire à zéro
	}
}

int LectureData(byte NombresPaquets, byte MemAdr)									//Fonction de lécture de données stocké dépassant 1 octets
{
	int DataRead = 0;																//La variable DataRead est initialiser à zéro pour éviter de pérturber l'opération de stockage
  	for (int i=0;i<NombresPaquets;i++)
  	{
  		DataRead |= (EEPROM.read((MemAdr + i)) << (TaillePaquets*i));				// on stocke les bits de l'octer stocker à l'adresse de la mémoire que l'on incrémente pour chaque paquets, avec une opération de décalage on va "recoller" les bits de l'octet découper lors de la sauvegarde, c'est l'opération inverse de la sauvegarde
  	}
  	return DataRead;																//On retourne la valeur stocker dans la variable DataRead que l'on pourra récuper à l'intérieur d'une de nos variables dans notre code principal
}


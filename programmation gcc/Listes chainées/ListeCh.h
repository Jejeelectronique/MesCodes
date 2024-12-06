#ifndef __LISTE__CH__H
#define __LISTE__CH__H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_LISTE_SIZE 50

typedef struct elementsList{
int valeur;
struct elementsList* next;
}elementsList;

elementsList* push_front_List(elementsList *elm, int value);
elementsList* push_back_List(elementsList *elm, int value);
elementsList* CleanList(elementsList *elm);
elementsList* initList(elementsList *elm);
elementsList* pop_front_List(elementsList *elm);
elementsList* pop_back_List(elementsList *elm);


void printList(elementsList *elm);

#endif
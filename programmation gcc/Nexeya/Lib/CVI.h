#ifndef __CVI__H__
#define __CVI__H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    false,
    true
}CtrlString;


typedef enum {
    ProgOFF,
    ProgRUN
}StateProg;


typedef enum {
    a = 97,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
}Key;


typedef struct MyEvent
{
    int (*event_occurs)(Key*);
    Key key; 
    StateProg stateProg;
}MyEvent;


extern MyEvent myEvent;

void  print_json(char Name[17]);
char *concat(char *Name, char *NameBis);
int NbDecimals(int temp);
int event_occurs(Key *key);
#endif
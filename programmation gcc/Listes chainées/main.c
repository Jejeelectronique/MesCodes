#include "ListeCh.h"


int main(int argc, int **argv)
{
    elementsList *Maliste;
    Maliste = NULL;
    Maliste = push_front_List(Maliste, 35);  
    Maliste = push_front_List(Maliste, 63);  
    Maliste = push_front_List(Maliste, 2);  
    Maliste = push_front_List(Maliste, 55);
    Maliste = push_front_List(Maliste, 36);  
    Maliste = push_front_List(Maliste, 99);  
    Maliste = push_front_List(Maliste, 78);  
    Maliste = push_front_List(Maliste, 82);
    printf("---------------------------------------------------\n");

    Maliste = push_back_List(Maliste, 3);
    Maliste = push_back_List(Maliste, 6);
    Maliste = push_back_List(Maliste, 24);
    Maliste = push_back_List(Maliste, 3);
    Maliste = push_back_List(Maliste, 98);
    Maliste = push_back_List(Maliste, 99);

    for(int i = 0; i < 9; i++)
    {
        Maliste = pop_back_List(Maliste);
        // Maliste = pop_front_List(Maliste);
    }

    printList(Maliste);

    // CleanList(Maliste);
return 0;
}
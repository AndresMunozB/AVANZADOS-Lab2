#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



int main()
{
    char elementos[20];
    memset(elementos,0,sizeof(elementos));
    elementos[0]='0';
    elementos[1]='5';
    elementos[2]='6';
    elementos[3]='1';
    elementos[4]='2';
    elementos[5]='a';



    char cadena[100];
    memset(cadena,0,sizeof(cadena));
    FILE* archivo = fopen("archivo.txt","w");
    backTracking(elementos,cadena, archivo ,0);

    return 0;
}

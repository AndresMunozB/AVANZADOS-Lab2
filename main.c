#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



int main()
{
    /*
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
    backTracking(elementos,cadena, archivo ,0);*/


    char caracteres[250];
	char nameFile[250];
	memset(caracteres,0,sizeof(caracteres));
	memset(nameFile,0,sizeof(nameFile));
	//printf("caracter: %s\n", caracteres);
	char option[250];
	do{
		printf("         MENU\n");
		printf("1) Generar palabras.\n");
		printf("2) Salir\n" );
		printf("\nIngrese una option: ");
		memset(option,0,sizeof(option));
		fflush(stdin);
		scanf("%s",option);
		if (!strcmp(option,"1")){
			memset(nameFile,0,255);
			//char stringBuffer[LARGOLINE];
			printf("\nIngrese el nombre de un archivo: ");
			scanf("%s", nameFile);

			if (existsFile(nameFile)){
				searchCharacters(caracteres,nameFile);
				printf("Generando combinaciones...\n");
				//aqui se llama al algortimo de backtracking
				generateCombinations(caracteres);
				printf("Combinaciones generadas.\n");
				printf("Las palabras se encuentran en el archivo 'salida.out'.\n\n");

			}
			else{
				printf("El archivo ingresado no existe\n\n");
			}
		}

		}while(strcmp(option,"2"));


    return 0;
}

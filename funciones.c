#include <stdio.h>
#include <string.h>
#include "funciones.h"

/*
 * Funcion existsFile
*/
int existsFile(char* filename) {
	FILE* f = NULL;
	f = fopen(filename,"r");
	if (f == NULL)
		return 0;
	else {
		fclose(f);
		return 1;
	}
	return 0;
}

/*
 * Funcion isIn
*/
int isIn(char string[],char caracter){
	int i=0;
	for (i=0;i<strlen(string);i++){
		if (string[i]==caracter){
			return 1;
		}
	}
	return 0;
}

/*
 * Funcion consecutive
*/
int consecutive(char* string){
	int i;
	for (i = 0; i < strlen(string)-2; ++i)
	{
		if (isLetter(string[i]) && isLetter(string[i+1]) && isLetter(string[i+2])){
			return 1;
		}
		if (isNumber(string[i]) && isNumber(string[i+1]) && isNumber(string[i+2])){
			return 1;
		}
	}
	return 0;
}

/*
 * Funcion isLetter
*/
int isLetter(char caracter){
	if (caracter>=97 && caracter<=122){
		return 1;
	}
	return 0;
}

/*
 * Funcion isNumber
*/
int isNumber(char c){
	if (c>= 48 && c<=57){
		return 1;
	}
	return 0;
}

/*
 * Funcion isVocal
*/
int isVocal(char c){
	if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
		return 1;
	}
	return 0;
}

/*
 * Funcion validWord
*/
int validWord(char* palabra){

    if(consecutive(palabra)){
        return 0;

    }

    if(isNumber(palabra[0]) && isNumber(palabra[strlen(palabra)-1])){
        return 0;
    }


    if (isVocal(palabra[0])){
        return 0;
    }


	return 1;
}

/*
 * Funcion searchCharacters
*/
void searchCharacters(char* caracteres, char* nombreFile){


    FILE* archivoEntrada;
	archivoEntrada = fopen(nombreFile,"r");
	char buffer;
	int contador=0;
	while (!feof(archivoEntrada)){

		fscanf(archivoEntrada,"%c\n",&buffer);

		if(!isIn(caracteres,buffer) && (isLetter(buffer) || isNumber(buffer)) ){
			caracteres[contador]=buffer;
			contador++;
		}
	}
	fclose(archivoEntrada);
}
void backTracking(char* elementos,char* cadena, FILE* archivo,int numero){
        //fprintf(archivo,"NO TERMINADO: %s\n", cadena);
        if(numero == 8 && validWord(cadena)){
            fprintf(archivo,"%s\n", cadena);

        }
        if(isVocal(cadena[0])){
            return;
        }
        if(numero>=3){
            if(consecutive(cadena)){
                return;
            }
        }
        if(numero<=8) {
            int i;
            for (i=0; i< strlen(elementos); i++ ) {
                 cadena[numero]=elementos[i];
                 cadena[numero+1] = '\0';
                 backTracking(elementos,cadena,archivo,numero+1 );
            }
        }
}
void generateCombinations(char* caracteres){
        FILE* archivoSalida= fopen("salida.out","w");
        char cadena[250];
        memset(cadena,0,sizeof(cadena));
        backTracking(caracteres,cadena,archivoSalida,0);
}







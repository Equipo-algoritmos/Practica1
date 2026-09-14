#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenArreglo(char *arreglo[]){
	int i, j, key, m = 50;
	char *aux;
	for (j = 1; j < m; j++){
        key = (int)arreglo[j][0];
        aux = arreglo[j];
        i = j - 1;
        while ((i > -1) && (arreglo[i][0] > key)){
            arreglo[i + 1] = arreglo[i];
            i = i - 1;
        }
        arreglo[i + 1] = aux;
	}
}

void printArr(char *cadenas[], char *msj){
	printf("%s", msj);
	for (int i = 0; i < 50; i++)
	{
	    printf("%18s, ", cadenas[i]);
		if((i+1)%5==0)
			printf("\n");
	}
}

void llenarArreglo(char *cadenas[]){
	char *investidura[50] = {
    "INVESTIDURA", "ALOMANCIA", "FERUQUIMIA", "HEMALURGIA", "ALIENTO",
    "DESPERTAR", "BIOCROMIA", "SELLOS", "SOMBRAS", "LUZTORMENTA",
    "LUZVACIO", "LUZVIDA", "CONEXION", "IDENTIDAD", "FORTUNA",
    "ALETHI", "SCADRIAL", "ESQUIRLA", "ASTILLA", "PERPENDICULARIDAD",
    "ATIUM", "LERASIUM", "AVIAR", "NICROSIL", "CROMO",
    "ALUMINIO", "ELECTRUM", "DURALUMINIO", "ACERO", "HIERRO",
    "ESTANO", "PELTRE", "COBRE", "BRONCE", "ZINC",
    "LATON", "CADMIO", "BENDALEO", "FABRIAL", "BRUMOSO",
    "ALOMANTE", "FERUQUIMISTA", "DESPERTADOR", "RADIANTE", "SPREN",
    "VINCULO", "CANTOR", "SANGRENOCTURNA", "OYENTE", "ROSHAR"
	};
    for (int i = 0; i < 50; i++)
    {
        cadenas[i] = investidura[i];
    }
}

void programa2(){
	char *cadenas[50];
	llenarArreglo(cadenas);
	printArr(cadenas, "Arrreglo desordenado:\n\n");
	ordenArreglo(cadenas);
	printArr(cadenas, "\nArreglo ordenado alfabeticamente:\n\n");
}

int main(int argc, char const *argv[])
{
	programa2();
	return 0;
}
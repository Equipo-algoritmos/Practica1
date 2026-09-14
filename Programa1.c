#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float calcularMediana(int arreglo[], int m){
	float mediana;
	int r = m/2;
	if ((m%2)==0) //el arreglo es par
	{
		mediana = ((float)arreglo[r]+(float)arreglo[r-1])/2.0;
	}
	else if((m%2)!=0){
		mediana = arreglo[r];
	}
	return mediana;
}

void ordenArreglo(int arreglo[], int m){
	int i, j, key;
	for (j = 1; j < m; j++){
        key = arreglo[j];
        i = j - 1;
        while ((i > -1) && (arreglo[i] > key)){
            arreglo[i + 1] = arreglo[i];
            i = i - 1;
        }
        arreglo[i + 1] = key;
	}
}

void printArr(int arreglo[], int m, char *msj){
	printf("%s", msj);
	for (int i = 0; i < m; ++i)
	{
		printf(" %3d |", arreglo[i]);
		if(((i+1)%10==0)&&i!=(m-1))
			printf("\n|");
	}
}

int generarRandom(){
	return rand() % 199 - 99;
}

void llenarArreglo(int arreglo[], int m){
	for (int i = 0; i < m; i++)
	{
		arreglo[i] = generarRandom();
	}
}


int pedirEntero(char msj[]){
	printf("%s", msj);
    int numero;
    while (1)
    {
        if (scanf("%d", &numero) == 1)
        {
            while (getchar()!='\n');
            return numero;
        }
        printf("\nEntrada invalida. Ingresa un numero entero: ");
        while (getchar() != '\n');
    }
}

void programa1(){
	srand(time(NULL));
	int m = pedirEntero("Cuantos valores desea ordenar?\n");
	int arreglo[m];
	llenarArreglo(arreglo, m);
	printArr(arreglo, m, "\nArreglo desordenado:\n|");
	ordenArreglo(arreglo, m);
	printArr(arreglo, m, "\n\nArreglo Ordenado:\n|");
	float mediana = calcularMediana(arreglo, m);
	printf("\n\nLa mediana en el arreglo de numero es: %.2f\n", mediana);
}

int main(int argc, char const *argv[])
{
	programa1();
	return 0;
}
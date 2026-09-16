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

void orden(int arreglo[], int m){
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

void llenarArreglo(int arreglo[], int m, char *select){
    if (select == "random"){
        for (int i = 0; i < m; i++){
            arreglo[i] = generarRandom();
        }
    }
    if (select == "cero"){
        for (int i = 0; i < m; i++){
            arreglo[i] = 0;
        }
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

void ordenPasos(int arreglo[], int m){
    int copia[m];
    llenarArreglo(copia, m, "cero");
    printf("\n\n%-64s%s\n", "Arreglo Ordenado", "Datos por Ordenar");
    for (int j = 0; j < m; j++){
        int key = arreglo[j];
        int i = j - 1;
        while (i >= 0 && copia[i] > key){
            copia[i + 1] = copia[i];
            i--;
        }
        copia[i + 1] = key;
        printArr(copia, j + 1, "|");
        for (int e = 0; e < 64 - (1 + 6 * (j + 1)); e++){
            printf(" ");
        }
        if (j + 1 < m){
            printArr(arreglo + j + 1, m - j - 1, "|");
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++){
        arreglo[i] = copia[i];
    }
}

void mostrarTiempo(double diferencia){
    int milisegundos = (double)(diferencia) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n\nTiempo de ordenamiento: %d ms", milisegundos);
}

double ordenArreglo(int arreglo[], int m){
    clock_t inicio = clock();
    if (m > 10){
        orden(arreglo, m);
    }
    else{
        ordenPasos(arreglo, m);
    }
    clock_t fin = clock();
    double diferencia = (double)(fin - inicio);
    return diferencia;
}



void programa1(){
	srand(time(NULL));
	int E = pedirEntero("Elige el tipo de arreglo a ordenar:\n1) Arreglo ordenado\t2) Arreglo invertido\t3) Arreglo aleatorio\n");
	switch (E){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
	}

	int m = pedirEntero("Cuantos valores desea ordenar?\n");
	int arreglo[m];
	llenarArreglo(arreglo, m, "random");
	printArr(arreglo, m, "\nArreglo desordenado:\n|");
	double tiempo = ordenArreglo(arreglo, m);
	printArr(arreglo, m, "\n\nArreglo Ordenado:\n|");
    mostrarTiempo(tiempo);
	float mediana = calcularMediana(arreglo, m);
	printf("\n\nLa mediana en el arreglo de numero es: %.2f\n", mediana);
}

int main(int argc, char const *argv[]){
	programa1();
	return 0;
}

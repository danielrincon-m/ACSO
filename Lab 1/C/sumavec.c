#include <stdio.h>
#include <stdlib.h>


int numeros[10000];
int size;
float suma;


void leer(void){
	int cant;
	int i;
	float number;
	
	printf("Escriba la cantidad de elementos en el vector: ");
	scanf("%d", &cant);
	size = cant;
	for(i = 0; i < cant; i++){
		printf("Escriba el numero #%d: ", i + 1);
		scanf("%f", &number);
		numeros[i] = number;
	}
		
	return;
}


void sumar(void){
	int i;
	
	for(i = 0; i < size; i++){
		suma += numeros[i];
	}
	
	return;
}


void escribir(void){
	printf("La suma de todos los elementos del vector es: %f", suma);
}


int main(void){
	float suma;
	
	leer();
	sumar();
	escribir();

	return EXIT_SUCCESS;
}


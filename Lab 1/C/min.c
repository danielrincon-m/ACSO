#include <stdio.h>
#include <stdlib.h>

int main(void){
	float min;
	float number;
	int cant;
	int i;

	printf("Escriba la cantidad de numeros: ");
	scanf("%d", &cant);
	for(i = 0; i < cant; i++){
		printf("Escriba el numero #%d: ", i + 1);
		scanf("%f", &number);
		if(i==0){
			min = number;
		}else{
			if(number < min){
				min = number;
			}
		}
	}
	printf("El minimo es: %f", min);
	return EXIT_SUCCESS;	
}

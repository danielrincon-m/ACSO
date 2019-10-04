#include <stdio.h>
#include <stdlib.h>

int main(void){
	float num1, num2;

	printf("Ingrese el primer real: ");
	scanf("%f", &num1);
	printf("Ingrese el segundo real: ");
	scanf("%f", &num2);
	if (num1 > num2) {
		printf("El máximo es: %f\n", num1);
	}else if(num2 > num1){
		printf("El máximo es: %f\n", num2);
	}else{
		printf("Ambos números son iuales\n");
	}

	return EXIT_SUCCESS;
}

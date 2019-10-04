#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int int1, int2, suma;

	printf("Digite el entero #1: ");
	scanf("%d", &int1);
	printf("Digite el entero #2: ");
	scanf("%d", &int2);
	suma=int1+int2;

	printf("La suma de los numeros es %d\n",suma);
	return EXIT_SUCCESS;
}

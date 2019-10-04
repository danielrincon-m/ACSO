#include <stdio.h>
#include <stdlib.h>


void suma(){
	float num1, num2, sum;
	
	printf("Escriba el primer numero que desea sumar: ");
	scanf("%f", &num1);
	printf("Escriba el segundo numero que desea sumar: ");
	scanf("%f", &num2);
	sum = num1 + num2;
	printf("La suma resultante es de: %g", sum);
	
	return;
}


void resta(){
	float num1, num2, resta;
	
	printf("Escriba el primer numero que desea restar: ");
	scanf("%f", &num1);
	printf("Escriba el segundo numero que desea restar: ");
	scanf("%f", &num2);
	resta = num1 - num2;
	printf("La resta resultante es de: %g", resta);
	
	return;
}


void mult(){
	float num1, num2, multip;
	
	printf("Escriba el primer numero que desea multiplicar: ");
	scanf("%f", &num1);
	printf("Escriba el segundo numero que desea multiplicar: ");
	scanf("%f", &num2);
	multip = num1 * num2;
	printf("La multiplicacion resultante es de: %g", multip);
	
	return;	
}


void divi(){
	float num1, num2, division;
	
	printf("Escriba el dividendo: ");
	scanf("%f", &num1);
	printf("Escriba el divisor: ");
	scanf("%f", &num2);
	division = num1 / num2;
	printf("La division resultante es de: %g", division);
	
	return;	
}


void menu(){
	char operacion;
	
	printf("\n\n-----MENU-----\n");
	printf("Que operacion desea realizar (+,-,*,/): ");
	scanf(" %c", &operacion);
	
	switch(operacion)
	{
		case '+':
			suma();
			break;
		case '-':
			resta();
			break;
		case '*':
			mult();
			break;
		case '/':
			divi();
			break;
		default:
			printf("No eligio una opcion correcta");
			break;
	}
}


int main(void){
	while(1){
		menu();
	}	
	return EXIT_SUCCESS;
}

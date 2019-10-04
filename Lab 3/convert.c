#include <stdio.h>
#include <stdbool.h>
#define SIZEE 6
#define SIZEB 30
//El numero de bits en un entero de d-digitos es floor(log2(10**d))+1
//#define SIZEE 1000
//#define SIZEB 3400


void getInput(bool *esNegativo, int *decEntero, int *decReal){
	bool esParteEntera = true;
	char actualChar;
	int actualIndex = 0;
	
	//Obtener la entrada tanto decimal como entera
	while((actualChar = getchar()) != '\n'){
		//Si se encuentra un signo negativo, tener en cuenta
		if (actualChar == '-'){
			*esNegativo = true;
		}else if (actualChar == '.'){
			//Cuando se encuentre un punto cambiar de array
			esParteEntera = false;
			actualIndex = 0;
		}else if (esParteEntera){
			//Obtener el valor del digito
			decEntero[actualIndex] = (int)actualChar - 48;
			actualIndex ++;
		}else{
			//Obtener el valor del decimal
			decReal[actualIndex] = (int)actualChar - 48;
			actualIndex ++;
		}
	}
	
	//Pasar decReal a la derecha
	int inputIndex = SIZEE - 1;
	int i;
	for(i = SIZEE - 1; i >= 0; i--){
		if(decReal[i] != -1){
			decReal[inputIndex] = decReal[i];
			decReal[i] = -1;
			inputIndex--;
		}
	}
}


int dividir(int *decEntero, int divisor){
	int resultado[SIZEE];
	int resultIndex = 0;
	int dividendo = decEntero[0];
	int currentIndex = 0;
	int i;
	
	for (i = 0; i < SIZEE; i++){
		resultado[i] = -1;
	}
	
	while(currentIndex < SIZEE){
		//printf("%d%c", dividendo, '\n');
		if(divisor > dividendo){
			currentIndex++;
			if (decEntero[currentIndex] != -1){
				dividendo = dividendo * 10 + decEntero[currentIndex];
			}else{
				break;
			}
		}
		//printf("%c%d%c", '\n', dividendo / divisor, '\n');
		resultado[resultIndex] = dividendo / divisor;
		dividendo = dividendo - (resultado[resultIndex] * divisor);
		resultIndex++;
	}
	
//	printf("%c", '\n');
//	for (i = 0; i < SIZEE; i++){
//		printf("%d ", decEntero[i]);
//	}
//	printf("%c", '\n');
//	for (i = 0; i < SIZEE; i++){
//		printf("%d ", resultado[i]);
//	}
//	printf("%c", '\n');
//	printf("%d", dividendo);
//	printf("%c", '\n');	
	
	for (i = 0; i < SIZEE; i++){
		if(resultado[i] != -1){
			decEntero[i] = resultado[i];
		}else{
			decEntero[i] = -1;
		}	
	}
	
	return dividendo;
}


void calcParteEntera(int* decEntero, int *binEntero){
	int indexBin = SIZEB - 1;
	int result;
	int i;
	
	while(decEntero[0] != -1){
		result = dividir(decEntero, 2);
		binEntero[indexBin] = result;
		indexBin--;
	}
	indexBin = 0;
	for (i = 0; i < SIZEB; i++){
		if (binEntero[i] != -1){
			binEntero[indexBin] = binEntero[i];
			binEntero[i] = -1;
			indexBin++;		
		}
	}
//	for (i = 0; i < SIZEB; i++){
//		printf("%d ", binEntero[i]);
//	}
}


int multiplicar(int *decReal, int multiplicador){
	int resultado[SIZEE];
	int posDecimal;
	int multiplicacion;
	int lleva = 0;
	int parteEntera = 0;
	int i;

	//Llenar resultado de -1
	for (i = 0; i < SIZEE; i++){
		resultado[i] = -1;
	}
	//Calcular posición decimal
	for (i = SIZEE - 1; i >= 0; i--){
		if (decReal[i] == -1){
			posDecimal = i;
			break;
		}
	}
	//Realizar la multiplicación
	for (i = SIZEE - 1; i >= 0; i--){
		if (decReal[i] == -1) break;
		multiplicacion = decReal[i] * multiplicador + lleva;
		lleva = 0;
		if (multiplicacion >= 10){
			if (decReal[i - 1] == -1) decReal[i - 1] = 0;
			lleva = multiplicacion / 10;
			multiplicacion = multiplicacion % 10;
		}
		resultado[i] = multiplicacion;
	}	
	//Escribir el resultado
	for (i = SIZEE - 1; i >= 0; i--){
		if(i <= posDecimal){
			decReal[i] = -1;
			if(resultado[i] != -1){
				parteEntera = parteEntera * 10 + resultado[i];
			}
		}else{
			decReal[i] = resultado[i];
		}
	}
	
//	printf("%c", '\n');
//	for (i = 0; i < SIZEE; i++){
//		printf("%d ", resultado[i]);
//	}
//	printf("%c", '\n');
//	for (i = 0; i < SIZEE; i++){
//		printf("%d ", decReal[i]);
//	}
//	printf("%c", '\n');
//	printf("%d", parteEntera);

	return parteEntera;
}


bool isEmpty(int *decReal){
	int i;
	bool empty = true;
	
	for(i = 0; i < SIZEE; i++){
		if (decReal[i] != 0 && decReal[i] != -1) empty = false;
	}
	return empty;
}


void calcParteDec(int *decReal, int *binReal){
	int binIndex = 0;
	int result;
	int i;
	
	while(!isEmpty(decReal)){
		result = multiplicar(decReal, 2);
		binReal[binIndex] = result;
		binIndex++;
	}
	
	printf("%c", '\n');
	for (i = 0; i < SIZEB; i++){
		printf("%d ", binReal[i]);
	}
}


int main(){
	bool esNegativo = false;
	int decEntero[SIZEE];
	int decReal[SIZEE];
	int binEntero[SIZEB];
	int binReal[SIZEB];
	int i;
	
	//Inicializar las listas en -1
	for (i = 0; i < SIZEE; i++){
		decEntero[i] = -1;
		decReal[i] = -1;
	}
	for (i = 0; i < SIZEB; i++){
		binEntero[i] = -1;
		binReal[i] = -1;
	}
	
	getInput(&esNegativo, decEntero, decReal);
	calcParteEntera(decEntero, binEntero);
	//multiplicar(decReal, 5);
	calcParteDec(decReal, binReal);

	return 0;
}


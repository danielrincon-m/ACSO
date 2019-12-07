#include <stdio.h>
#include <stdbool.h>
#define SIZE 5000


void getInput(bool *esNegativo, int *decEntero, int *decReal){
	bool esParteEntera = true;
	char actualChar;
	int actualIndex = 0;

    actualChar = getchar();
    while(actualChar < 48 || actualChar > 57){
		actualChar = getchar();
	}
	
	//Obtener la entrada tanto decimal como entera
	while(actualChar >= 48 && actualChar <= 57){

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
		actualChar = getchar();
	}
	
	//Pasar decReal a la derecha
	// int inputIndex = SIZE - 1;
	// int i;
	// for(i = SIZE - 1; i >= 0; i--){
	// 	if(decReal[i] != -1){
	// 		decReal[inputIndex] = decReal[i];
	// 		decReal[i] = -1;
	// 		inputIndex--;
	// 	}
	// }
}


int dividir(int *decEntero, int divisor){
	int resultado[SIZE];
	int resultIndex = 0;
	int dividendo = decEntero[0];
	int currentIndex = 0;
	int i;
	
	for (i = 0; i < SIZE; i++){
		resultado[i] = -1;
	}
	
	while(currentIndex < SIZE && resultIndex < SIZE){
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
//	for (i = 0; i < SIZE; i++){
//		printf("%d ", decEntero[i]);
//	}
//	printf("%c", '\n');
//	for (i = 0; i < SIZE; i++){
//		printf("%d ", resultado[i]);
//	}
//	printf("%c", '\n');
//	printf("%d", dividendo);
//	printf("%c", '\n');	
	
	for (i = 0; i < SIZE; i++){
		if(resultado[i] != -1){
			decEntero[i] = resultado[i];
		}else{
			decEntero[i] = -1;
		}	
	}
	
	return dividendo;
}


void calcParteEntera(int* decEntero, int *binEntero){
	int indexBin = SIZE - 1;
	int result;
	int i;
	
	while(decEntero[0] != -1 && indexBin >= 0){
		result = dividir(decEntero, 2);
		binEntero[indexBin] = result;
		indexBin--;
	}
	indexBin = 0;
	for (i = 0; i < SIZE; i++){
		if (binEntero[i] != -1){
			binEntero[indexBin] = binEntero[i];
			binEntero[i] = -1;
			indexBin++;		
		}
	}
}


int multiplicar(int *decReal, int multiplicador){
	int resultado[SIZE];
	int posDecimal;
	int multiplicacion;
	int lleva = 0;
	int parteEntera = 0;
	int i;

	//Llenar resultado de -1
	for (i = 0; i < SIZE; i++){
		resultado[i] = -1;
	}
	//Calcular posici�n decimal
	// for (i = SIZE - 1; i >= 0; i--){
	// 	if (decReal[i] == -1){
	// 		posDecimal = i;
	// 		break;
	// 	}
	// }

	//Realizar la multiplicaci�n
	for (i = SIZE - 1; i >= 0; i--){
		if (decReal[i] == -1) continue;

		multiplicacion = decReal[i] * multiplicador + lleva;
		lleva = 0;

		if (multiplicacion >= 10){
			// if (decReal[i - 1] == -1) decReal[i - 1] = 0;
			lleva = multiplicacion / 10;
			multiplicacion = multiplicacion % 10;
		}
		resultado[i] = multiplicacion;
	}	
	//Escribir el resultado
	for (i = SIZE - 1; i >= 0; i--){
		decReal[i] = resultado[i];
	}
	
//	printf("%c", '\n');
//	for (i = 0; i < SIZE; i++){
//		printf("%d ", resultado[i]);
//	}
//	printf("%c", '\n');
//	for (i = 0; i < SIZE; i++){
//		printf("%d ", decReal[i]);
//	}
//	printf("%c", '\n');
//	printf("%d", parteEntera);

	return lleva;
}


bool isEmpty(int *decReal){
	int i;
	
	for(i = 0; i < SIZE; i++){
		if (decReal[i] != 0 && decReal[i] != -1) return false;
	}
	return true;
}


void calcParteDec(int *decReal, int *binReal){
	int binIndex = 0;
	int result;
	int i;
	
	while(!isEmpty(decReal) && binIndex < SIZE){
		result = multiplicar(decReal, 2);
		binReal[binIndex] = result;
		binIndex++;
	}
}

void printAns(bool esNegativo, int *binEntero, int *binReal){
	int i;
    int charCount = 0;
    int maxChars = 1000;

    if (esNegativo){
		printf("%c", '-');
        charCount += 1;
	}

	for (i = 0; i < SIZE; i++){
		if (binEntero[i] == -1) break;
		printf("%d", binEntero[i]);
        charCount += 1;
        if (charCount >= maxChars){
            printf("%c", '\n');
            return;
        }
    }

	if (binReal[0] == -1 || charCount >= maxChars) {
		printf("%c", '\n');
		return;
	}

	printf("%c", '.');
    charCount += 1;

    for (i = 0; i < SIZE; i++){
		if (binReal[i] == -1) break;
		printf("%d", binReal[i]);
        charCount += 1;
        if (charCount >= maxChars){
            printf("%c", '\n');
            return;
        }
    }

	printf("%c", '\n');
}

int main(){
	bool esNegativo;
	int decEntero[SIZE];
	int decReal[SIZE]; 
	int binEntero[SIZE];
	int binReal[SIZE];
	int casos;
	int c, i;

	scanf("%d", &casos);

	for (c = 0; c < casos; c++){
		//Inicializar las listas en -1
		for (i = 0; i < SIZE; i++){
			decEntero[i] = -1;
			decReal[i] = -1;
			binEntero[i] = -1;
			binReal[i] = -1;
		}
		esNegativo = false;
		
		getInput(&esNegativo, decEntero, decReal);
		calcParteEntera(decEntero, binEntero);
		calcParteDec(decReal, binReal);

        // for (i = 0; i < SIZE; i++){
        //     printf("%d ", binEntero[i]);
        // }

        // printf("%c", '\n');
        // for (i = 0; i < SIZE; i++){
        //     printf("%d ", binReal[i]);
        // }
	    // printf("%c", '\n');     

		printAns(esNegativo, binEntero, binReal);
	}

	return 0;
}


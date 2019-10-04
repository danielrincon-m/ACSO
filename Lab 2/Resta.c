#include <stdio.h>
#define SIZE 1010


int num1[SIZE];
int num2[SIZE];
int solucion[SIZE];


void initialize(){
	int i;
	for(i = 0; i < SIZE; i++){
		num1[i] = 0;
		num2[i] = 0;
		solucion[i] = 0;
	}
}


void getInput(){
	char input[SIZE];
	int *nums[2] = {num1, num2};
	int character;
	int inputSize;
	int j;
	int i;
	
	for (j = 0; j < 2; j++){
		inputSize = 0;
		character = getchar();
		while(character != '\n'){
			input[inputSize] = character;
			inputSize += 1;
			character = getchar();
		}
		for (i = inputSize; i >= 0; i--){
			nums[j][SIZE - (inputSize - i)] = (int)input[i] - 48;
		}
	}
}


void operate(){
	int lastIndex = SIZE - 1;
	int i;
	
	for(i=lastIndex; i>=0; i--){
		if (num1[i] - num2[i] < 0){
			num1[i - 1] -= 1;
			num1[i] += 10;
		}
		solucion[i] = num1[i] - num2[i];
	}
}


void printOutput(){
	int firstIndex = 0;
	int i;
	
	if (solucion[SIZE - 1] == 0) {
		firstIndex = SIZE - 1;
	}
	for (i = 0; i < SIZE; i++){
		if(solucion[i] != 0){
			firstIndex = i;
			break;
		}
	}
	for (i = firstIndex; i < SIZE; i++){
		printf("%c",solucion[i] + 48);
	}
	printf("\n");
}


int main(){
	char trash;
	int cases;
	int i;
	
	scanf("%d%c", &cases, &trash);
	for (i = 0; i < cases; i++){
		initialize();
		getInput();
		operate();
		printOutput();
	}
	return 0;
}


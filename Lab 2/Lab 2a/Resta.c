#include <stdio.h>
#define SIZE 1010

int num1[SIZE];
int num2[SIZE];
int solucion[SIZE];

void initialize()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        num1[i] = 0;
        num2[i] = 0;
        solucion[i] = 0;
    }
}

void getInput()
{
    char input[SIZE];
    int character;
    int inputSize;
    int j;
    int i;

    for (i = 0; i < SIZE; i++)
    {
        input[i] = -1;
    }
    scanf("%s", input);
    for (i = 0; i < SIZE; i++)
    {
        if (input[i] == -1)
        {
            inputSize = i - 1;
            break;
        }
    }
    for (i = inputSize; i >= 0; i--)
    {
        num1[SIZE - (inputSize - i)] = (int)input[i] - 48;
    }
    //	for(i = 0; i < SIZE; i++){
    //		printf("%d", num1[i]);
    //	}

    for (i = 0; i < SIZE; i++)
    {
        input[i] = -1;
    }
    scanf("%s", input);
    for (i = 0; i < SIZE; i++)
    {
        if (input[i] == -1)
        {
            inputSize = i - 1;
            break;
        }
    }
    for (i = inputSize; i >= 0; i--)
    {
        num2[SIZE - (inputSize - i)] = (int)input[i] - 48;
    }
    //	for(i = 0; i < SIZE; i++){
    //		printf("%d", num2[i]);
    //	}
}

void operate()
{
    int lastIndex = SIZE - 1;
    int i;

    for (i = lastIndex; i >= 0; i--)
    {
        if (num1[i] - num2[i] < 0)
        {
            num1[i - 1] -= 1;
            num1[i] += 10;
        }
        solucion[i] = num1[i] - num2[i];
    }
}

void printOutput()
{
    int firstIndex = 0;
    int i;

    if (solucion[SIZE - 1] == 0)
    {
        firstIndex = SIZE - 1;
    }
    for (i = 0; i < SIZE; i++)
    {
        if (solucion[i] != 0)
        {
            firstIndex = i;
            break;
        }
    }
    for (i = firstIndex; i < SIZE; i++)
    {
        printf("%d", solucion[i]);
    }
    printf("\n");
}

int main()
{
    int cases;
    int i;

    scanf("%d", &cases);
    for (i = 0; i < cases; i++)
    {
        initialize();
        getInput();
        operate();
        printOutput();
    }
    return 0;
}
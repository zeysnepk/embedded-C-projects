#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main(){
	int num1, num2, numHex1, numHex2;
	char hexNum1[50], hexNum2[50];
	printf("Please enter two numbers:\n");
	scanf("%d %d", &num1, &num2);

	//int to hex string
	sprintf(hexNum1, "0x%x",num1);
	sprintf(hexNum2, "0x%x",num2);

	//hex string to int
	numHex1 = strtol(hexNum1, NULL, 0);
	numHex2 = strtol(hexNum2, NULL, 0);

	printf("%s and %s\n\n", hexNum1, hexNum2);
	printf("%d and %d\n\n", numHex1, numHex2);
	printf("%x and %x\n\n", numHex1, numHex2);

	printf("Addition: %d\n", nums_add(numHex1, numHex2));
	printf("Hex Addition: %x\n", nums_add(numHex1, numHex2));

	printf("-------------------------------------------\n");

	printf("Subtraction: %d\n", nums_sub(numHex1, numHex2));
	printf("Hex Subtraction: %x\n", nums_sub(numHex1, numHex2));

	printf("-------------------------------------------\n");

	printf("Multiplication: %ld\n", nums_mul(numHex1, numHex2));
	printf("Hex Multiplication:: %lx\n", nums_mul(numHex1, numHex2));

	printf("-------------------------------------------\n");

	printf("Division: %f\n", nums_div(numHex1, numHex2));
	printf("Hex Division:: %f\n", nums_div(numHex1, numHex2));
}

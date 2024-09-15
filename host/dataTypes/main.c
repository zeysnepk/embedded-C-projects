#include <stdio.h>

//function prototype
void sizeOfDataTypes(void);
int localOrGlobal();

int f__var = 3;

int main(){
	printf("Hello, World!\n");
	printf("Please enter a key: ");
	getchar();
	printf("Perfect choice!\r");
	printf("  Great");

	//function calling
	sizeOfDataTypes();


	int __var; //uninitialized warning
	__var = __var + 10;
	printf("\nValue of variable \"__var\" is %d", __var);

	f__var = localOrGlobal();
	printf("\n\"f__var\" value is %d", f__var);
}

//funtion definition
void sizeOfDataTypes(void){
	printf("\nThe size of signed char data type is %lu", sizeof(signed char));
	printf("\nThe size of unsigned char data type is %lu", sizeof(unsigned char));
	printf("\nThe size of short data type is %lu", sizeof(short));
	printf("\nThe size of unsigned short data type is %lu", sizeof(unsigned short));
	printf("\nThe size of int data type is %lu", sizeof(int));
	printf("\nThe size of unsigned int data type is %lu", sizeof(unsigned int));
	printf("\nThe size of long data type is %lu", sizeof(long));
	printf("\nThe size of unsigned long data type is %lu", sizeof(unsigned long));
	printf("\nThe size of long long data type is %lu", sizeof(long long));
	printf("\nThe size of unsigned long long data type is %lu", sizeof(unsigned long long));
}

int localOrGlobal(){
	int f__var = 5;
	{
		int f__var = 10; //local in local
	}
	return f__var;
}


#include <stdint.h>
#include <stdio.h>

struct Data{
	char data1;
	int data2;
	char data3;
	short data4;
};

void displayElements(struct Data *pData);

int main(void){
	struct Data data;
	data.data1 = 0x12;
	data.data2 = 0xFFEEEDFE;
	data.data3 = 0x18;
	data.data4 = 0xABDE;

	displayElements(&data);
}

void displayElements(struct Data *pData){
	printf("data1 = %x\n", pData -> data1);
	printf("data2 = %x\n", pData -> data2);
	printf("data3 = %x\n", pData -> data3);
	printf("data4 = %x\n", pData -> data4);
}

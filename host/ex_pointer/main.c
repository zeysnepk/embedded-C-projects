#include <stdio.h>

int main(){
	char var = 100;
	printf("The value of 'var' is %d\n", var);
	printf("The address of 'var' is %p\n", &var);

	char* p_var = &var;
	char val = *p_var;

	printf("The value of 'val from var' is %d\n", val);

	*p_var = 65;
	printf("The value of 'var' is %d\n", var);
	printf("The address of 'var' is %p\n", &var);



	//casting pointer
	long long int data = 0xffabec11123129ab;

	char* p_addr1;
	p_addr1 = (char*)&data;
	/* 'p_addr1' locate 8 bytes but read and write 1 byte for char */
	printf("The value at address %p is %x\n", p_addr1, *p_addr1);

	int* p_addr2;
	/* 'p_addr2' locate 8 bytes but read and write 4 bytes for int */
	p_addr2 = (int*)&data;
	printf("The value at address %p is %x\n", p_addr2, *p_addr2);

	short* p_addr3;
	/* 'p_addr3' locate 8 bytes but read and write 2 bytes for short */
	p_addr3 = (short*)&data;
	printf("The value at address %p is %x\n", p_addr3, *p_addr3);

	long long* p_addr4;
	/* 'p_addr4' locate 8 bytes also read and write 8 bytes for long long */
	p_addr4 = (long long*)&data;
	printf("The value at address %p is %llx\n", p_addr4, *p_addr4);



	//pointer arithmetic
	p_addr1 = p_addr1 + 1; /*fetch next 1 byte*/
	printf("The value at address %p is %x\n", p_addr1, *p_addr1);

	p_addr2 = p_addr2 + 1; /*fetch next 4 bytes*/
	printf("The value at address %p is %x\n", p_addr2, *p_addr2);

	p_addr3 = p_addr3 + 1; /*fetch next 4 bytes*/
	printf("The value at address %p is %x\n", p_addr3, *p_addr3);



}

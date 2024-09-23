#include <stdio.h>

int main(){
	char alpha = 'A';
	printf("Address of variable 'A' is %p\n", &alpha);

	//unsigned long int adress_of_alpha = &alpha; it throws error because of data type mismatch
	unsigned long long int address_alpha = (unsigned long long int)&alpha;
	printf("%llx\n", address_alpha);
	printf("%llo\n", address_alpha);

	char *address_of_alpha = &alpha;
	printf("%p\n", address_of_alpha);
}





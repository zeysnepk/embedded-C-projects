#include <stdio.h>

int main(){
	/* long long int adress_of_value = 0x00076AB123FF; is not valid pointer definition and initiation
	the program does not recognize it as a pointer, but it as a long long integer*/

	/*Read operation on address1 variable yields 1 byte of data */
	char* address_of_value1 = (char*) 0x00076AB123FF;

	/* Read operation on address1 variable yields 4 bytes of data */
	int* address_of_value2 = (int*) 0x00007FFF8E3C3824;

	/* Read operation on address1 variable yields 8 bytes of data */
	long long int* address_of_value3 = (long long int*) 0x00007FFF8E3C3824;

	/*1 byte data is read from 'address_of_value1' and stored in 'data' variable*/
	char data = *address_of_value1;
}

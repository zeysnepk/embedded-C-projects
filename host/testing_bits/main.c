#include <stdio.h>
#include <stdint.h>

//finding the number if is even or odd with and bit operation
int main(){
	int32_t num;
	printf("Please enter a number: ");
	scanf("%d", &num);
	if(num & 1){
		printf("The number %d is odd", num);
	}
	else{
		printf("The number %d is even", num);
	}
}

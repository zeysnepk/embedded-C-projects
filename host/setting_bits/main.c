#include <stdio.h>
#include <stdint.h>

//setting the 4th and 7th positions to 1 with |(OR)
int main(){
	int32_t num;
	printf("Enter a number: ");
	scanf("%d", &num);
	num |= 10010000;
	printf("The new value is %d", num);
}

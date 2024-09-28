#include <stdio.h>
#include <stdint.h>

//clearing the 4th, 5th and 6th positions with &(AND)
int main(){
	int32_t num;
	printf("Enter a number: ");
	scanf("%d", &num);
	//method 1:
	num &= 10001111;

	//method 2:
	num &= ~(111 /* 7 */ << 4);

	printf("The cleared value is %d", num);
}

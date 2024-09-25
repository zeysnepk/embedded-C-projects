#include <stdio.h>

int main(){
	float num1, num2, num3;
	float avr;

	printf("Enter the first number: ");
	/* When the console do not wait to get input from user and print last line directly,
	fflush is used to flush the contents of output buffer to stdout. */
	fflush(stdout);
	scanf("%f", &num1);
	printf("Enter the second number: ");
	fflush(stdout);
	scanf("%f", &num2);
	printf("Enter the third number: ");
	fflush(stdout);
	scanf("%f", &num3);

	avr = (num1 + num2 + num3) / 3;
	printf("The average of three numbers is %f", avr);

	/* When the IDE console does not show the last output -its because input buffer's content(\n)-
	and exits immesiately, getchar() used for prevent this. But using just one getchar() is not enough
	because it takes '\n' and we can not enter any keyword so to solve it,
	 we can use one more getchar -but its not preffered- or while loop with getchar().
	  */
	while(getchar() != '\n');

	// Wait for the user to press Enter
	getchar();
}

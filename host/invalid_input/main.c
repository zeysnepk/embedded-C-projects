#include <stdio.h>
#include <stdint.h>

int main(){
	float n1, n2;
	int32_t int_n1, int_n2;
	int res;
	char ch;
	do{
		printf("Please enter first number(integer): ");
		res = scanf("%f", &n1);
		if(res){
			int_n1 = n1;
			if(int_n1 != n1)
				printf("Warning, comparing only integer part\n");
			break;
		}
		printf("Please enter second number(integer): ");
		res = scanf("%f", &n2);
		if(res){
			int_n2 = n2;
			if(int_n2 != n2)
				printf("Warning, comparing only integer part\n");
			break;
		}
		if(res == 0){
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("Invalid input try again\n");
		}
	}while(1);
}

#include <stdio.h>

void callFunction();

int main(){
	int count;
	printf("Please enter count: ");
	scanf("%d", &count);

	for(int i=0; i<count; i++){
		callFunction();
	}
}

void callFunction(){
	//this count variable is accessible only from callFunction
	//will not die even if the execution control goes out of funtion
	static int count=0;
	count++;
	printf("This function executed %d time(s)\n", count);
}


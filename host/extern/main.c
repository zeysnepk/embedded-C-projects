#include <stdio.h>

void call_the_file(void);

int main_private_data; //if it defined with static it can't be accessed by other files in project

int main(){
	main_private_data = 22;
	printf("data is %d\n", main_private_data);

	call_the_file();
	printf("data is %d\n", main_private_data);

}

//to call this function throws an error cause its static and cant be called
static void change_system_speed(int system_speed){
	printf("System speed changed to %d\n", system_speed);

}

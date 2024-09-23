#include <stdio.h>

extern int main_private_data;

void change_system_speed(int system_speed);

void call_the_file(void){
	main_private_data = 33;

	int set_speed;
	printf("Enter the system speed: ");
	scanf("%d", &set_speed);

	//gives an error because change_system_speed is a static variable
	change_system_speed(set_speed);
}

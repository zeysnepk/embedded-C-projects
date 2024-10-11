#include <stdint.h>


int main(void)
{
	uint32_t *clock_ctrl_reg = (uint32_t*) 0x40023830;
	uint32_t *port_mode_reg = (uint32_t*) 0x40020000;
	uint32_t *port_out_reg = (uint32_t*) 0x40020014;

	//enabling the clock for GPIOA peripheral in the AHB1ENR
	*clock_ctrl_reg |= 1;

	//configuring the mode of the IO pin as output
	//clear the 10th and 11th bit positions
	*port_mode_reg &= ~(3 << 10);
	//make 10th bit position as 1
	*port_mode_reg |= (1 << 10);



    /* Loop forever */
	while(1){
		//LED ON
		*port_out_reg |= (1 << 5);
		//executes for 100k times
		for(uint32_t i=0; i<100000; i++);

		//LED OFF
		*port_out_reg &= ~(1 << 5);
		for(uint32_t i=0; i<100000; i++);
	}
}

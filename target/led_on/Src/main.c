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

	//setting 5th bit of the output data register to make I/O pin-5 as HIGH
	*port_out_reg |= (1 << 5);

    /* Loop forever */
	for(;;);
}

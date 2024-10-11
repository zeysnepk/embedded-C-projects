#include <stdint.h>


int main(void)
{
	uint32_t volatile *clock_ctrl_reg = (uint32_t*) 0x40023830;

	uint32_t volatile *pa5_mode_reg = (uint32_t*) 0x40020000;
	uint32_t volatile *pa5_out_reg = (uint32_t*) 0x40020014;


	uint32_t volatile *pa0_mode_reg = (uint32_t*) 0x40020000;
	uint32_t volatile *pa0_input_reg = (uint32_t*) 0x40020010;

	*clock_ctrl_reg |= 1;

	*pa5_mode_reg &= ~(3 << 10);
	*pa5_mode_reg |= (1 << 10);


	*pa0_mode_reg &= ~(3 << 0);

	while(1){
		uint8_t pin_state = (uint8_t)(*pa0_input_reg & 0x1);
		if (pin_state) {
		    *pa5_out_reg |= (1 << 5);
		} else {
		    *pa5_out_reg &= ~(1 << 5);
		}

	}
}

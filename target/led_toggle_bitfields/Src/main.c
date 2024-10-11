#include <stdint.h>
#include "main.h"

int main(void)
{
    RCC_AHB1ENR_t *const volatile pClckReg = (RCC_AHB1ENR_t*) 0x40023830;
    GPIOx_MODER_t *const volatile pPortAMode = (GPIOx_MODER_t*) 0x40020000;
    GPIOx_OTYPER *const volatile pPortAOut = (GPIOx_OTYPER*) 0x40020014;

    pClckReg -> gpioa_en = 1;
    pPortAMode -> pin3 = 1;

	while(1){
		pPortAOut -> pin3 = 1;
		for(uint32_t i=0; i<300000; i++);
		pPortAOut -> pin3 = 0;
		for(uint32_t i=0; i<300000; i++);
	}
}

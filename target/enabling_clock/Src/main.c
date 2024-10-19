#include <stdint.h>


#define RCC_BASE_ADDR		( 0x40023800UL )
#define RCC_OFFSET			( 0x44UL )

#define RCC_APB2_ADDR		( RCC_BASE_ADDR + RCC_OFFSET )



#define ADC1_BASE_ADDR		( 0x40012000UL )
#define ADC_CR1_OFFSET 		( 0x04UL )

#define ADC_CR1_ADDR 		( ADC1_BASE_ADDR + ADC_CR1_OFFSET )



int main(void)
{
	uint32_t *pRccAbp2Addr  = 	(uint32_t*)RCC_APB2_ADDR;
	uint32_t *pAdcCr1Addr   = 	(uint32_t*)ADC_CR1_ADDR;


	//RCC APB2 de ADC1 clock aktif etme
	*pRccAbp2Addr  |=  ( 1 << 8 );

	//ADC control register 1 için scan modunu aktif etme
	*pAdcCr1Addr   |=  ( 1 << 8 );

	for(;;);
}

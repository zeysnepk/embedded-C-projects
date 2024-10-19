#include <stdint.h>


#define RCC_BASE_ADDR		( 0x40023800UL )


#define RCC_CFRG_OFFSET		( 0x08UL )
#define RCC_CFRG_REG_ADDR	( RCC_BASE_ADDR + RCC_CFRG_OFFSET )


#define RCC_AHB1_OFFSET 	( 0x30UL )
#define RCC_AHB1_REG_ADDR 	( RCC_BASE_ADDR + RCC_AHB1_OFFSET )

//MCO1 --> PA8

#define GPIOA_BASE_ADDR  	( 0x40020000UL )

#define GPIO_AFRH_OFFSET 	( 0x24UL )
#define GPIOA_AFRH_ADDR 	( GPIOA_BASE_ADDR + GPIO_AFRH_OFFSET )


int main(void)
{
    uint32_t *pRccCfrgRegAddr = (uint32_t*)RCC_CFRG_REG_ADDR;

    //RCC_CFRG MCO1 bit yerini(22, 21 bitleri) HSI için 00 yapma
    *pRccCfrgRegAddr &= ~( 3 << 21 );

    //HSI clock(16MHz) 2 ye bölme --> 8MHz / MCO1 PRE 26, 25, 24 --> 100
    *pRccCfrgRegAddr &= ~( 3 << 24 );
    *pRccCfrgRegAddr |= ( 1 << 26 );

    //MCO1 için PA8 pinini aktif etme
    uint32_t *pRccAhb1RegAddr = (uint32_t*)RCC_AHB1_REG_ADDR;
    *pRccAhb1RegAddr |= ( 1 << 0 );

    //PA8 pinini "alternate function mode" ayarlama --> 10
    uint32_t *pGpioaModeRegAddr = (uint32_t*)GPIOA_BASE_ADDR;
    *pGpioaModeRegAddr &= ~( 3 << 16 );
    *pGpioaModeRegAddr |= ( 1 << 17 );

    //PA8 pini için "alternate function high register" modunu 0 ayarlama
    uint32_t *pGpioaAfrhAddr = (uint32_t*)GPIOA_AFRH_ADDR;
    *pGpioaAfrhAddr &= ~( 0xf << 0 );


	for(;;);
}

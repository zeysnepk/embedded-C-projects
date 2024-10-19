#include <stdint.h>


#define RCC_BASE_ADDR		( 0x40023800UL )


#define RCC_CFGR_OFFSET		( 0x08UL )
#define RCC_CFGR_REG_ADDR	( RCC_BASE_ADDR + RCC_CFGR_OFFSET )


#define RCC_CR_OFFSET 		( 0x00UL )
#define RCC_CR_REG_ADDR	 	(RCC_BASE_ADDR + RCC_CR_OFFSET )


#define RCC_AHB1_OFFSET 	( 0x30UL )
#define RCC_AHB1_REG_ADDR 	( RCC_BASE_ADDR + RCC_AHB1_OFFSET )

//MCO1 --> PA8

#define GPIOA_BASE_ADDR  	( 0x40020000UL )

#define GPIO_AFRH_OFFSET 	( 0x24UL )
#define GPIOA_AFRH_ADDR 	( GPIOA_BASE_ADDR + GPIO_AFRH_OFFSET )


int main(void)
{
	/****** HSE için ayarlar ********/
	uint32_t *pRccCrRegAddr = ( uint32_t* )RCC_CR_REG_ADDR;

	//HSEON aktif etme
	*pRccCrRegAddr |= ( 1 << 16 );

	//HSE clock kontrol (HSERDY bitini bekleme)
	while( !( *pRccCrRegAddr & ( 1 << 17 ) ) );

	/****** HSE control configuration register ayarları *******/
    uint32_t *pRccCfgrRegAddr = ( uint32_t* )RCC_CFGR_REG_ADDR;

    //HSE'yi sistem saati olarak seçme (SW bitleri, 0 ve 1. bit)
    *pRccCfgrRegAddr |= ( 1 << 0 );

    //RCC_CFGR MCO1 bit yerini(22, 21 bitleri) HSE için 10 yapma
    *pRccCfgrRegAddr &= ~( 1 << 21 );
    *pRccCfgrRegAddr |= ( 1 << 22 );

    //HSE clock(8MHz) 4 e bölme --> 2MHz / MCO1 PRE 26, 25, 24 --> 110
    *pRccCfgrRegAddr &= ~( 7 << 24 );
    *pRccCfgrRegAddr |= ( 6 << 24 );

    //MCO1 için PA8 pinini aktif etme
    uint32_t *pRccAhb1RegAddr = ( uint32_t* )RCC_AHB1_REG_ADDR;
    *pRccAhb1RegAddr |= ( 1 << 0 );

    //PA8 pinini "alternate function mode" ayarlama --> 10
    uint32_t *pGpioaModeRegAddr = ( uint32_t* )GPIOA_BASE_ADDR;
    *pGpioaModeRegAddr &= ~( 3 << 16 );
    *pGpioaModeRegAddr |= ( 2 << 16 );

    //PA8 pini için "alternate function high register" modunu 0 ayarlama
    uint32_t *pGpioaAfrhAddr = ( uint32_t* )GPIOA_AFRH_ADDR;
    *pGpioaAfrhAddr &= ~( 0xf << 0 );


	for(;;);
}

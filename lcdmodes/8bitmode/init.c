#include "init.h"
void init ()
{

// enable the external cloclk
RCC->cr |= RCC_HSEON_LSB_MASK;
// wait the bit 16 to hse ready bit to stable 
while(!(RCC->cr & RCC_HSERD_LSB_MASK));
/* set flash lateny to 2 wait states for 72Mhz*/
FLASH->acr= (FLASH->acr &(~FLASH_ACR_LATENCY_MASK)) | ( FLASH_ACR_LATENCY_2WS << FLASH_ACR_LATENCY_LSB);

//pll(phase lock loop)
// hse divider for pll entry 
RCC->cfgr &= ~RCC_CFGR_PLLXTPRE_MASK;
RCC->cfgr|= RCC_CFGR_PLL_SRC_MASK;

/*set pll multipiler to 9 to grt Max frequency*/
RCC->cfgr=(RCC->cfgr & (~RCC_CFGR_PLLMUL_MASK))| (RCC_CFGR_PLLMUL_VAL_MUL9 << RCC_CFGR_PLLMUL_LSB );

/*TURN ON PLL*/
RCC->cr |= RCC_CR_PLLON_MASK;
while(!(RCC->cr & RCC_CR_PLL_RDY_MASK));

/* set APB1 PRECALER DIVISOR TO 2 T GET THE MAXIMUN 32Mhz clock*/
RCC->cfgr = (RCC->cfgr &(~RCC_CFGR_PPRE1_MASK))|
           (RCC_CFGR_PPRE1_VAL_DIV2 << RCC_CFGR_PPRE1_LSB);
/*swtch SYSCLK tp PLL*/
RCC->cfgr= (RCC->cfgr & (~RCC_CFGR_SW_MASK))| 
            ( RCC_CFGR_SW_VAL_PLL << RCC_CFGR_SW_LSB);


    while(((RCC->cfgr & RCC_CFGR_SWS_MASK)>> RCC_CFGR_SWS_LSB) != RCC_CFGR_SW_VAL_PLL);        

}
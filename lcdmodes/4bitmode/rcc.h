#ifndef STM32F103_RCC_H
#define STM32F103_RCC_H


typedef struct 
{
  volatile unsigned int cr;
  volatile unsigned int cfgr;
  volatile unsigned int cir;
  volatile unsigned int apb2rstr;
  volatile unsigned int apb1rstr;
  volatile unsigned int ahbenr;
  volatile unsigned int apb2enr;
  volatile unsigned int apb1enr;
  volatile unsigned int bdcr;
}rcc_t;

#define RCC ((rcc_t *)0x40021000U)

#define RCC_HSION_LSB 0
#define RCC_HSION_LSB_MASK (1 << RCC_HSION_LSB)
#define RCC_HSIRDY_LSB 1
#define RCC_HSIRDY_LSB_MASK ( 1 << RCC_HSIRDY_LSB )

//--------------------
#define RCC_HSEON_LSB 16
#define RCC_HSEON_LSB_MASK (1 << RCC_HSEON_LSB )
//-------
#define RCC_HSERD_LSB 17
#define RCC_HSERD_LSB_MASK (1 << RCC_HSERD_LSB)
//-------------------
#define RCC_CR_PLLON 24
#define RCC_CR_PLLON_MASK (1 << RCC_CR_PLLON)
// pll ready flag
#define RCC_CR_PLL_RDY 25
#define RCC_CR_PLL_RDY_MASK (1 << RCC_CR_PLL_RDY)



// bit defination of cfgr register 
#define RCC_CFGR_PLLMUL_LSB 18
#define RCC_CFGR_PLLMUL_MSB 21
#define RCC_CFGR_PLLMUL_MASK (0xf << RCC_CFGR_PLLMUL_LSB)
#define RCC_CFGR_PLLMUL_VAL_MUL2 0x0
#define RCC_CFGR_PLLMUL_VAL_MUL3 0x1 
#define RCC_CFGR_PLLMUL_VAL_MUL4 0x2 
#define RCC_CFGR_PLLMUL_VAL_MUL5 0x3 
#define RCC_CFGR_PLLMUL_VAL_MUL6 0x4 
#define RCC_CFGR_PLLMUL_VAL_MUL7 0x5
#define RCC_CFGR_PLLMUL_VAL_MUL8 0x6
#define RCC_CFGR_PLLMUL_VAL_MUL9 0x7
#define RCC_CFGR_PLLMUL_VAL_MUL10 0x8 

#define RCC_CFGR_PLLXTPRE 17
#define RCC_CFGR_PLLXTPRE_MASK (1 << RCC_CFGR_PLLXTPRE)

#define RCC_CFGR_PLL_SRC 16
#define RCC_CFGR_PLL_SRC_MASK (1 << RCC_CFGR_PLL_SRC)
/*APB LOW-speed prescaler (APB1,PCLK1)*/

#define RCC_CFGR_PPRE1_LSB 8
#define RCC_CFGR_PPRE1_MSB 10
#define RCC_CFGR_PPRE1_MASK (0x7 << RCC_CFGR_PPRE1_LSB)
#define RCC_CFGR_PPRE1_VAL_DIV1  0x0  
#define RCC_CFGR_PPRE1_VAL_DIV2  0x4 
#define RCC_CFGR_PPRE1_VAL_DIV4  0x5
#define RCC_CFGR_PPRE1_VAL_DIV8  0x6
#define RCC_CFGR_PPRE1_VAL_DIV16 0x7
/*System clock switch*/
#define RCC_CFGR_SW_LSB 0
#define RCC_CFGR_SW_MSB 1
#define RCC_CFGR_SW_MASK (0x3 << RCC_CFGR_SW_LSB) 
#define RCC_CFGR_SW_VAL_HSI 0x0 
#define RCC_CFGR_SW_VAL_HSE 0x1 
#define RCC_CFGR_SW_VAL_PLL 0x2 
#define RCC_CFGR_SWS_LSB 2
#define RCC_CFGR_SWS_MSB 3
#define RCC_CFGR_SWS_MASK (0x3 << RCC_CFGR_SWS_LSB)


//bit of apb2enr
#define RCC_APREB2ENR_AFIO_EN 0
#define RCC_APREB2ENR_AFIO_EN_MASK (1 << RCC_APREB2ENR_AFIO_EN)

#define RCC_APREB2ENR_RESERVE 1

#define RCC_APREB2ENR_IOPA_EN 2 
#define RCC_APREB2ENR_IOPA_EN_MASK (1 << RCC_APREB2ENR_IOPA_EN)
#define RCC_APREB2ENR_IOPB_EN 3
#define RCC_APREB2ENR_IOPB_EN_MASK (1 << RCC_APREB2ENR_IOPB_EN)
#define RCC_APREB2ENR_IOPC_EN 4
#define RCC_APREB2ENR_IOPC_EN_MASK (1 << RCC_APREB2ENR_IOPC_EN)
#define RCC_APREB2ENR_ADC1_EN 9
#define RCC_APREB2ENR_ADC1_EN_MASK (1 << RCC_APREB2ENR_ADC1_EN)
#define RCC_APREB2ENR_ADC2_EN 10
#define RCC_APREB2ENR_ADC2_EN_MASK (1 << RCC_APREB2ENR_ADC2_EN) 
#define RCC_APB2ENR_TIM1_EN 11
#define RCC_APB2ENR_TIM1_EN_MASK (1 << RCC_APB2ENR_TIM1_EN)
#define RCC_AP2ENR_SPI_EN 12
#define RCC_AP2ENR_SPI_EN_MASK (1 << RCC_AP2ENR_SPI_EN) 
#define RCC_APB2ENR_TIM8_EN 13
#define RCC_APB2ENR_TIM8_EN_MASK   (1 << RCC_APB2ENR_TIM1_EN)
#define RCC_AP2ENR_USART1_EN 14
#define RCC_AP2ENR_USART1_EN_MASK (1 << RCC_AP2ENR_USART1_EN) 
#define RCC_AP2ENR_ADC3_EN 15
#define RCC_AP2ENR_ADC3_EN_MASK (1 << RCC_AP2ENR_ADC3_EN)
// bit 18-16 resered 
#define RCC_AP2ENR_TIM9_EN 19
#define RCC_AP2ENR_TIM9_EN_MASK (1 << RCC_AP2ENR_TIM9_EN) 
#define RCC_AP2ENR_TIM10_EN 20
#define RCC_AP2ENR_TIM10_EN_MASK (1 << RCC_AP2ENR_TIM10_EN) 
#define RCC_APB2ENR_TIM11_EN 21
#define RCC_APB2ENR_TIM11_EN_MASK (1 << RCC_APB2ENR_TIM11_EN)

typedef enum
{
  gpioa,
  gpiob,
  gpioc,
}enable;

void periperal_clock_enable(enable rcc);

#endif
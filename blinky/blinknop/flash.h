#ifndef STM32F103_FLASH_H
#define STM32F103_FLASH_H

typedef struct 
{
  volatile unsigned int acr;
  volatile unsigned int keyr;
  volatile unsigned int optkeyr;
  volatile unsigned int sr;
  volatile unsigned int cr;
  volatile unsigned int ar;
  volatile unsigned int reserved ;
  volatile unsigned int obr;
  volatile unsigned int wrpr;
}flash_t;

#define FLASH ((flash_t *)0x40022000)

#define FLASH_ACR_LATENCY_LSB 0
#define FLASH_ACR_LATENY_MSB 2 
#define FLASH_ACR_LATENCY_MASK (7 << FLASH_ACR_LATENCY_LSB)
#define FLASH_ACR_LATENCY_0WS 0x0 
#define FLASH_ACR_LATENCY_1WS 0x1 
#define FLASH_ACR_LATENCY_2WS 0x2
#endif
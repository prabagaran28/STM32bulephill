
#ifndef STM32F103_GPIO_H
#define STM32F103_GPIO_H


typedef struct {
    volatile unsigned int crl;    // GPIO configuration low register 00
    volatile unsigned int crh;    // GPIO configuration high register 04
    volatile unsigned int idr;    // GPIO input data register  08
    volatile unsigned int odr;    // GPIO output data register  0c
    volatile unsigned int bsrr;   // GPIO bit set/reset register 10
    volatile unsigned int brr;    // GPIO bit reset register  14
    volatile unsigned int lckr;   // GPIO lock register 18
} gpio_t;

#define GPIOA ((gpio_t *)0x40010800U)
#define GPIOB ((gpio_t *)0x40010C00U)
#define GPIOC ((gpio_t *)0x40011000U)

#define GPIO_PIN_0 ((uint16_t)0x0001)
#define GPIO_PIN_1 ((uint16_t)0x0002)
#define GPIO_PIN_2 ((uint16_t)0x0004)
#define GPIO_PIN_3 ((uint16_t)0x0008)
#define GPIO_PIN_4 ((uint16_t)0x0010)
#define GPIO_PIN_5 ((uint16_t)0x0020)
#define GPIO_PIN_6 ((uint16_t)0x0040)
#define GPIO_PIN_7 ((uint16_t)0x0080) 
#define GPIO_PIN_8 ((uint16_t)0x0100) 
#define GPIO_PIN_9 ((uint16_t)0x0200) 
#define GPIO_PIN_10 ((uint16_t)0x0400)
#define GPIO_PIN_11 ((uint16_t)0x0800)
#define GPIO_PIN_12 ((uint16_t)0x1000)
#define GPIO_PIN_13 ((uint16_t)0x2000)
#define GPIO_PIN_14 ((uint16_t)0x4000)
#define GPIO_PIN_15 ((uint16_t)0x8000)

typedef enum
{
    RESET,
    SET
}gpio_state;
typedef enum 
{
 ANALOG_MODE =0,
 FLOATING_INPUT =1,
 INPUT_PULL = 2,
 OUTPUT_PUSH_PULL= 0,
OUTPUT_OPEN_DRAIN = 1,
OUTPUT_ALTER_PUSH_PULL =2,
OUTPUT_ALTER_OPEN_DRAIN=3
}gpio_mode;


typedef enum
{
INPIUT_MODE =0,
OUTPUT_MAX_10HMZ=1,
OUTPIUT_MAX_2MHZ = 2,
OUTPUT_MAX_50MHX = 3
}mode;
void gpio_config(gpio_t* port, int num,mode Mode,gpio_mode output);   
void write_pin(gpio_t* gpiox ,unsigned short int gpio_pin,gpio_state pinstate);
int read_pin(gpio_t * port,unsigned short int pin);
void gpio_setpin(gpio_t* port,unsigned short int pin);
void gpio_resetpin(gpio_t* port ,unsigned short int pin);
#endif
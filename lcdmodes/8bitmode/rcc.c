#include "rcc.h"

void periperal_clock_enable(enable rcc)
{
    switch(rcc)
    {
        case gpioa:
        RCC->apb2enr |=RCC_APREB2ENR_IOPA_EN_MASK;
        break;
        case gpiob:
        RCC->apb2enr |=RCC_APREB2ENR_IOPB_EN_MASK;
        break;
        case gpioc:
        RCC->apb2enr|=RCC_APREB2ENR_IOPC_EN_MASK;
        break;   

    }
}
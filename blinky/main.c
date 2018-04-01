#include "stm32f4xx.h"


void delay() {
    for(unsigned int c = 0; c < 100; c++) {
        for(volatile unsigned int i = 0; i < 10000; i++);
    }
}

//Flash orange LED at about 1hz
int main(void)
{

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER &= ~GPIO_MODER_MODER7;
    GPIOA->MODER |= 0b01 << 14;
    GPIOA->MODER &= ~GPIO_MODER_MODER6;
    GPIOA->MODER |= 0b01 << 12;

    GPIOA->ODR |= 1 <<7;

    for(;;) {

        GPIOA->ODR |= 1<<6;
        GPIOA->ODR &= ~(1<<7);

        delay();

        GPIOA->ODR &= ~(1<<6);
        GPIOA->ODR |= 1<<7;

        delay();


    }
}

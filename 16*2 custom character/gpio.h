
#ifndef STM32F103_GPIO_H
#define STM32F103_GPIO_H
#include<stdio.h>

typedef struct {
    volatile unsigned int crl;    // GPIO configuration low register
    volatile unsigned int crh;    // GPIO configuration high register
    volatile unsigned int idr;    // GPIO input data register
    volatile unsigned int odr;    // GPIO output data register
    volatile unsigned int bsrr;   // GPIO bit set/reset register
    volatile unsigned int brr;    // GPIO bit reset register
    volatile unsigned int lckr;   // GPIO lock register
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
void set_led(gpio_t* gpiox ,uint16_t gpio_pin,gpio_state pinstate);


#endif
#ifndef SYSTICK_H
#define SYSTICK_H


typedef struct 
{
    volatile unsigned int ctrl;
    volatile unsigned int load;
    volatile unsigned int val;
    volatile unsigned int calib;
}systick_type;

#define SYSTICK ((systick_type *)0xE000E010)
void systickInit(void);
void delay_ms(void);
void Delayus(void);
void delay_micro(unsigned int t);
void delay_milli(unsigned int l);
/* bit for ctrl*/



#endif
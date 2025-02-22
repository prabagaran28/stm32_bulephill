#ifndef UART_H
#define UART_H

typedef struct {

volatile unsigned int sr;
volatile unsigned int dr;
volatile unsigned int brr;
volatile unsigned int cr1;
volatile unsigned int cr2;
volatile unsigned int cr3;
volatile unsigned int gtpr;
}uartdef_t;

#define UART1 ((uartdef_t *)0x40013800)
#define UART2  ((uartdef_t *)0x40004400) 
#define UART3  ((uartdef_t *)8x40004800)
#define UART4  ((uartdef_t *)0x40004C00)
#define UART5   ((uartdef_t *)0x40005000)



#endif
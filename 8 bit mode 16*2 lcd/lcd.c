#include "lcd.h"
#include "gpio.h"
#include "systick.h"
//rs  pa8
//e    pa10
//r/w   paf 9

void set_cursor(unsigned int row ,unsigned int col)
{
    if(row==0)
    {
        send_command(0x80+col);
    }
    if(row==1)
    {
        send_command(0xc0+col);
    }

}



void send_data(unsigned char data)
{
   
    // rs=1 
    //rw=0 
    //comand
    //en=1
    //delay()
    //en=0
   
    GPIOA->odr |= (EANBLE_RS << 8); 
    GPIOA->odr &=~(ENABLE_RW << 9);
     delay_micro(10);
    GPIOA->odr |= (ENABLE_EN << 10); 
    delay_micro(5);
GPIOA->odr &=0xff00;
GPIOA->odr |= data;
delay_micro(5);
GPIOA->odr &= ~(ENABLE_EN << 10);

}

void send_command(unsigned char cmd) 
{
    // rs=0 
    //rw=0 
    //comand
    //en=1
    //delay()
    //en=0
    
    GPIOA->odr &= ~(EANBLE_RS << 8); 
    GPIOA->odr &=~(ENABLE_RW << 9);
     delay_micro(10);
    GPIOA->odr |= (ENABLE_EN << 10); 
    delay_micro(5);
GPIOA->odr &=0xff00;
GPIOA->odr |= cmd;
delay_micro(5);
GPIOA->odr &= ~(ENABLE_EN << 10);
}

void lcd_init()
{
   
   delay_milli(20);
   send_command(0x38); //8bitmode /2 lines
   delay_milli(5);
   send_command(0x0c); //display on
   delay_milli(5); 
   send_command(0x01); //clear display
   delay_milli(5);
   send_command(0x02);// get back to inital addreas
   delay_milli(5);

    
}


void send_string(char* ptr)
{
    while(*ptr)
    {
        send_data(*ptr);
        ptr++;
    }
}
/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */

void UART1_Init(void)
{
    SIM_SCGC4 |= 0x0800; // 使能UART1的时钟
    SIM_SCGC5 |= 0x0800; // 使能PORTC的时钟
    PORTC_PCR3 = 0x0300; // 配置端口PTC3为UART1 RXD复用端口
    PORTC_PCR4 = 0x0300; // 配置端口PTC4为UART1 TXD复用端口
    UART1_BDH = 0x00;
    UART1_BDL = 0x44; // 波特率9600
    UART1_C2 = 0x0C;  // 打开发送和接收器
}
void UART1_PutChar(unsigned char data)
{
    while (!(UART1_S1 & UART_S1_TDRE_MASK))
        ;
    UART1_D = data;
}

int main(void)
{
    unsigned char ascii_char;
    ascii_char = 0;
    UART1_Init();
    while (ascii_char < 128)
    {
        if (ascii_char % 16 == 0)
        {
            UART1_PutChar('\n');
            UART1_PutChar('\r');
        }
        UART1_PutChar(ascii_char++);
    }
    for (;;)
    {
    }
}
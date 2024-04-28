// Task 5

#include "derivative.h" /* include peripheral declarations */

void delay()
{
    int i, j;
    for (i = 0; i < 3000; i++)
    {
        for (j = 0; j < 200; j++)
        {
            asm("nop");
        }
    }
};

void main(void)
{
    unsigned char bMode;
    SIM_SCGC5 |= ((1 << 11) | (1 << 9));
    // PORTA和PORTC时钟
    //  指定用作GPIO
    PORTC_PCR9 = 0x0100;
    PORTC_PCR12 = 0x0100;
    PORTC_PCR13 = 0x0100;
    PORTA_PCR1 = 0x102;
    // 按键UP对应引脚PTA1
    GPIOC_PDDR |= ((1 << 9) | (1 << 12) | (1 << 13));
    GPIOC_PDOR |= (1 << 9);
    GPIOA_PDDR &= ~0x0002;
    bMode = 0;
    for (;;)
    {
        delay();
        if ((GPIOA_PDIR & 0x0002) == 0) // 想想看
        {
            bMode = ~bMode;
            if (bMode) // 根据变量，改变模式
            {
                GPIOC_PDOR &= ~(1 << 12);
                GPIOC_PDOR &= ~(1 << 13);
            }
            else
            {
                GPIOC_PDOR &= ~(1 << 12);
                GPIOC_PDOR |= (1 << 13);
            }
        }
        GPIOC_PDOR = ~GPIOC_PDOR;
        GPIOC_PDOR |= (1 << 9);
    }
}

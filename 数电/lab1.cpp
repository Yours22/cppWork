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
}

int main(void)
{

    int bMode = 1;

    SIM_SCGC5 |= ((1 << 11) | (1 << 9));
    // PORTA和PORTC时钟

    // 指定用作GPIO
    PORTC_PCR9 = 0x0100;
    PORTC_PCR12 = 0x0100;
    PORTC_PCR13 = 0x0100;

    PORTA_PCR1 = 0x102;

    GPIOC_PDDR |= ((1 << 9) | (1 << 12) | (1 << 13));
    GPIOC_PDOR |= (1 << 9);
    GPIOA_PDDR &= ~0x0002;

    for (;;)
    {
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

    return 0;
}

/**
Task2

// 启用模块时钟PORTC
     SIM_SCGC5 = SIM_SCGC5 | (1<<11);
     // 指定用作GPIO
     PORTC_PCR9 = 0x0100;
     PORTC_PCR12 = 0x0100;
     PORTC_PCR13 = 0x0100;

     GPIOC_PDDR |= ((1<<9) | (1<<12) | (1<<13));

     GPIOC_PDOR &= (1<<12);//12位低电平
     GPIOC_PDOR |= (1<<13);//13位高电平

     GPIOC_PDOR |= (1<<9); //9位高电平

     for(;;){
     delay();
     GPIOC_PDOR = ~ GPIOC_PDOR;//全部反转
     GPIOC_PDOR |= (1<<9); //把9调回来
     }

 Task3

     SIM_SCGC5 |= ((1 << 11) | (1 << 9));
    // PORTA和PORTC时钟
    // 指定用作GPIO
    PORTC_PCR9 = 0x0100;
    PORTC_PCR12 = 0x0100;
    PORTC_PCR13 = 0x0100;
    PORTA_PCR1 = 0x102;
    // 按键UP对应引脚PTA1，用作IO，上拉
    PORTA_PCR12 = 0x102;
    // 按键LEFT对应引脚PTA12，用作IO，上拉
    GPIOC_PDDR |= ((1 << 9) | (1 << 12) | (1 << 13));
    GPIOC_PDOR |= (1 << 9);
    GPIOA_PDDR &= ~0x1002; //输入模式
    GPIOC_PDOR &= (~((1 << 12) | (1 << 13)));
    // 两个小灯全灭
    for (;;)
    {
        // 按键按下之后为0（低电平）
        if ((GPIOA_PDIR & 0x1000) == 0)
            GPIOC_PDOR &= ~(1 << 12);
        else
            GPIOC_PDOR |= (1 << 12);
        if ((GPIOA_PDIR & 0x0002) == 0)
            GPIOC_PDOR &= ~(1 << 13);
        else
            GPIOC_PDOR |= (1 << 13);
    }



 **/

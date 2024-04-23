/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

// Task2 用按钮改变闪烁频率

#include "derivative.h" /* include peripheral declarations */

int bMode;
int times = 0;
int set = 1;

void PORTA_IRQHandler()
{
    if ((GPIOA_PDIR & 0X0002) == 0)
    {
        bMode = ~bMode;
        if (bMode)
        {
            // 模式A
            set = 1;
        }
        else
        {
            set = 2;
            // 模式B
        }
    }
}

void SysTick_Handler(void)
{
    unsigned int i;
    times += 1;
    if (times == set)
    {
        // 其余操作
        GPIOC_PDOR = ~GPIOC_PDOR;
        times = 0;
    }
    i = SYST_CSR;
}

int main(void)
{
    SIM_SCGC5 |= ((1 << 11) | (1 << 9));
    // PORTA和PORTC时钟

    // 指定用作GPIO
    PORTC_PCR9 = 0x0100;
    PORTC_PCR12 = 0x0100;
    PORTC_PCR13 = 0x0100;

    GPIOC_PDDR |= ((1 << 9) | (1 << 12) | (1 << 13));
    GPIOC_PDOR |= (1 << 9);

    GPIOA_PDDR &= ~0x0002;
    // 按键UP对应引脚PTA1

    asm("CPSIE i");          // 确认开启全局中断
    NVIC_ISER |= 0x40000000; // 开PORTA中断
    PORTA_PCR1 = 0x0A0102;

    // 假定按键对应PTA1，下降沿触发中断
    SYST_RVR = 0x9FFD07; // 0.5s @ 20.97MHz
    SYST_CVR = 0x00;     // Clear Value
    SYST_CSR = 0x07;     // Enable Clock

    for (;;)
    {
    }

    return 0;
}

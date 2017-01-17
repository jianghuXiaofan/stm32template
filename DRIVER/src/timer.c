#include "timer.h"

__IO uint32_t TimingDelay; 

void SysTick_Init(void)
{
	//����Systick����ֵ��ϵͳʱ��72MHz�� 72*(1/720000000) = 1us
	if(SysTick_Config(72))
	{
		while(1);
	}
	/**
	����д��
	while(Systick_Config(72000) == 1 );
	*/
}


void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}


//�δ��жϴ���
void SysTick_Handler(void)
{
	TimingDelay_Decrement();
}


//��ʱus
void delay_us(__IO uint32_t nTime)
{
	TimingDelay = nTime;//ʱ�ӵδ�
	while( TimingDelay != 0 );
}


//��ʱms
void delay_ms(__IO uint32_t nTime)
{
	delay_us(nTime * 1000);	//��ʱ1ms
}


#include<p18f4520.h>
#pragma config OSC=HS
#pragma config DEBUG=OFF
#pragma config LVP=OFF
#pragma config WDT=OFF

/*
void my_isr();

int c=0,e=0;
#pragma code high_vector=0x0008
void high_vector()
{
_asm
GOTO my_isr
_endasm
}
#pragma code
#pragma interrupt my_isr
void my_isr()
{

while(INTCONbits.INT0IF)
{
	int di,circum,rev,dist;
	c=c+1;	
while(c==24)
	{	
		e=e+1;
//		circum=2.08*3.14;
//		rev=74.74/circum;       //T.NO of rev for 2m
while(e==2) // when 2 meter distance covered
	{	
		CCP1CON=0b00011100;
		T2CON=0b00000010;
		PR2=0x9B;
		CCPR1L=0X45;
		T2CONbits.TMR2ON=1;
	}
c=0;
	}
INTCONbits.INT0IF=0;
}
} 
*/

void main()
{
int k,l;
ADCON1=0x0F;
TRISCbits.TRISC1=0;
TRISCbits.TRISC2=0;
RCONbits.IPEN=0;
INTCONbits.GIE=1;
INTCONbits.PEIE=1;
INTCONbits.INT0IE=1;
INTCONbits.INT0IF=0;
CCP1CON=0b00011100;
CCP2CON=0b00111100;
T2CON=0b00000010;

//for(k=0;k<1200;k++)
//{for(l=0;l<50;l++){}}
PR2=0x9B;
CCPR1L=0x8B;
CCPR2L=0x26;
T2CONbits.TMR2ON=1;
while(1)
{
	while(PIR1bits.TMR2IF)
	{
	PR2=0x9B;
	CCPR1L=0x8B;
    CCPR2L=0x26;
	T2CONbits.TMR2ON=1;
	PIR1bits.TMR2IF=0;
	}
}
}
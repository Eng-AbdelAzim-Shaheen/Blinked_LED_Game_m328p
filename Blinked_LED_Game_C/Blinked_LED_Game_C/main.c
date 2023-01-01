/*
 * Blinked_LED_Game_C.c
 *
 * Created: 12/29/2022 10:14:55 AM
 * Author : Eng AbdelAzim Shaheen
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int x=0;

void Game ()
{
	int Seg[]={0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0010000};
	
	if (x==9 )
	{
		_delay_ms(1000);
		x=0;
	//	i=0;
	}
	// i++;
	
	_delay_ms(500);
	if ((PIND & (1<<0)) && (PIND & (1<<1)) && (PIND & (1<<2)) && (PIND & (1<<3)) )
	{
	}
	else if ((PIND & (1<<0)) &&  PORTD==(PORTD|(1<<4)))
	{
		x++;
	}
	else if ((PIND & (1<<1)) &&  PORTD==(PORTD|(1<<5)))
	{
		x++;
	}
	else if ((PIND & (1<<2)) &&  PORTD==(PORTD|(1<<6)))
	{
		x++;
	}
	else if ((PIND & (1<<3)) &&  PORTD==(PORTD|(1<<7)))
	{
		x++;
	}
	PORTB = Seg[x];
	_delay_ms(500);
}

int main(void)
{  //PB3 PB2 PB1 PB0 B3 B2 B1 B0 PORTD
	DDRB=0xFF;
	DDRD=0xF0;
	
    while (1) 
    {		
		PORTD |= (1<<4);
		Game();
		PORTD &= ~(1<<4);
		PORTD |= (1<<5);
		Game();
		PORTD &= ~(1<<5);
		PORTD |= (1<<6);
		Game();
		PORTD &= ~(1<<6);
		PORTD |= (1<<7);
		Game();
		PORTD &= ~(1<<7);
    }
}


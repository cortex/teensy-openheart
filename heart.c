#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))

void reset(){
	PORTB = 0;
	PORTD = 0;
	DDRD = 0;
	DDRB = 0;
};


int lookup[] = {
	4,5,3,5,1,3,4,3,1,4,6,2,6,5,4,2,1,2,3,2,5,6,1,6,4,1,5,2,
	};

void on(int plus, int minus, int bright){

	if (plus > 0 && plus <= 4)
		PORTB |= 1 << (plus - 1);
	else if (plus == 5)
		PORTB |= 1 << 7;
	else 
		PORTD = 1;

	if (minus > 0 && minus <= 4)
		DDRB |= 1 << (minus - 1);
	else if( minus == 5)
		DDRB |= 1<<7;
	else DDRD |= 1;

	if (bright == 1){
		if (plus > 0 && plus <= 4)
			DDRB |= 1 << (plus - 1);
		else if (plus == 5)
			DDRB |= 1 << 7;
		else 
			DDRD = 1;
	}
	_delay_ms(0.1);

	reset();
}

void set(int n){
	if (n<sizeof(lookup))
		on(lookup[n], lookup[n+1], 1);
}

/*
   07 04    15 16
05 24 08 25 21 22 10
06 02 01 03 19 26 27
   00 13 18 12 20
      09 17 23
         14 
*/

int main(void)
{
	int i = 0;
	int j = 0;
while(1){
i=0;
	while(i<50){
		i++;
		set(7);
		set(4);
		set(25);
		set(15);
		set(16);
		set(10);
		set(11);
		set(20);
		set(23);
		set(14);
		set(9);
		set(0);
		set(6);
		set(5);
		set(11);
		set(1);
		set(2);
		set(3);
		set(8);
		set(9);
		set(12);
		set(13);
		set(17);
		set(18);
		set(19);
		set(21);
		set(22);
		set(24);
		set(26);
		
		for (j=0; j<i; j++)
			_delay_ms(.1);
	}
	

}
	while(1){
	i=0;
	while (i<200) {
		i++;
	}

	i=0;
	while (i<200) {
		on(4, 1,0);
		on(1, 6,0);
		on(5, 2,0);
		on(6, 5,0);
		on(5, 4,0);
		on(3, 5,0);
		on(3, 5,0);
		on(1, 4,0);
		on(5, 1,0);
		on(6, 1,0);
		on(2, 3,0);
		i++;
	}
	i=0;

	while (i<400) {
		on(3, 2,1);
		on(5, 3,1);
		on(2, 5,1);

		i++;
	}
		i=0;
	while (i<200) {
		on(4, 1, 0);
		on(1, 6, 0);
		on(5, 2, 0);
		on(6, 5, 0);
		on(5, 4, 0);
		on(3, 5, 0);
		on(3, 5, 0);
		on(1, 4, 0);
		on(5, 1, 0);
		on(6, 1, 0);
		on(2, 3, 0);
		i++;
	}
}

}



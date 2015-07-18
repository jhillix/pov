/* Purpose: Persistence of Vision toy for Jina :-)
 * Programmer: J. Hillis
 * Date: 03/18/2014
 */

 #include <avr/io.h>
 #include <util/delay.h>

	/* We are using PDIP ATtiny84. This might change to the SOIC.
	 * Nevertheless, we will be using DDRA, PORTA, and PINA to control
	 * the LED's.
	 */

 int main(void)
 {
	 /* Set pins to output. For the sake of consistency we are going to
	  * use binary; this also could be written as "DDRA = 0xff;" (HEX) or
	  * "DDRA = 255;" (DEC).
	  */
	 DDRA = 0b11111111;

	 while (1) {
		/* Show the pattern. Can you see it? 
		 * 
		 * 0b00000111		
		 * 0b00000001
		 * 0b11111111
		 * 0b10000001
		 * 0b11111111
		 * 0b10000001
		 * 0b11111111
		 * 0b01000000
		 * 0b00100000
		 * 0b00001000
		 * 0b00000001
		 * 0b11111111
		 * 0b00111111
		 * 0b01001000
		 * 0b10001000
		 * 0b01001000
		 * 0b00111111;
		 * 
		 * Note the delays between
		 * each "PORTA". YOU NEED THOSE!!! I wasted a day or two thinking
		 * something was wrong with the circuit X-O The problem was w/o
		 * the delays the LEDs was transitioning from ON to OFF so fast
		 * that the LEDs appeared dim 8-|
		 */

		PORTA = 0b00000111;
		_delay_ms(1);
		PORTA = 0b00000001;
		_delay_ms(1);
		PORTA = 0b11111111;
		_delay_ms(1);
		PORTA = 0b10000001;
		_delay_ms(1);
		PORTA = 0b11111111;
		_delay_ms(1);
		PORTA = 0b10000001;
		_delay_ms(1);
		PORTA = 0b11111111;
		_delay_ms(1);
		PORTA = 0b01000000;
		_delay_ms(1);
		PORTA = 0b00100000;
		_delay_ms(1);
		PORTA = 0b00001000;
		_delay_ms(1);
		PORTA = 0b00000001;
		_delay_ms(1);
		PORTA = 0b11111111;
		_delay_ms(1);
		PORTA = 0b00111111;
		_delay_ms(1);
		PORTA = 0b01001000;
		_delay_ms(1);
		PORTA = 0b10001000;
		_delay_ms(1);
		PORTA = 0b01001000;
		_delay_ms(1);
		PORTA = 0b00111111;
		_delay_ms(1);
		

		/* Set all the pins lo and delay for a few ms to give our eyes
		 * a chance to catch up before doing it again ;-) This could
		 * be written as "PORTA = 0x00;" or "PORTB = 0;".
		 */
		PORTA = 0b00000000;
		_delay_ms(10);
	 }
 }

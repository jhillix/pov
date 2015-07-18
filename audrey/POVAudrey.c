/* Purpose: Persistence of Vision toy (Green) for Audrey :-)
 * Programmer: J. Hillis
 * Date: 03/31/2014
 */

 #include <avr/io.h>
 #include <util/delay.h>
 
 /* Constants */
 #define PIXELS 68

/* We are using PDIP ATtiny84. This might change to the SOIC.
 * Nevertheless, we will be using DDRA, PORTA, and PINA to control
 * the LED's.
 */

const unsigned char audreyLED [] = {
0x80, 0xF8, 0x2E, 0x23, 0x2E, 0xF8, 0x80, 0x00, 0x7F, 0xC0, 0x80, 0x80, 0xC0, 0x7F, 0x00, 0x00,
0xFF, 0x81, 0x81, 0x81, 0x42, 0x3C, 0x00, 0x00, 0xFF, 0x11, 0x11, 0x31, 0xEE, 0x80, 0x00, 0xFF,
0x89, 0x89, 0x89, 0x89, 0x00, 0x01, 0x02, 0x04, 0xF8, 0x04, 0x02, 0x01, 0x00, 0x00, 0x70, 0x38,
0x08, 0xF0, 0x30, 0x3A, 0x3F, 0xFF, 0x06, 0x00, 0x00, 0x0E, 0x1F, 0x3F, 0x7F, 0xFE, 0xFE, 0x7F,
0x3F, 0x1F, 0x0E, 
};

 int main(void)
 {
	 /* Set pins to output. For the sake of consistency we are going to
	  * use binary; this also could be written as "DDRA = 0xff;" (HEX) or
	  * "DDRA = 255;" (DEC).
	  */
	 DDRA = 0b11111111;

	 while (1) {
		/* Show the pattern. Refer to audreyLED.xcf.
		 * 
		 * Note the delay after "PORTA". YOU NEED THAT!!! I wasted a day
		 * or two thinking something was wrong with the circuit X-O 
		 * The problem was w/o the delay the LEDs was transitioning from
		 * ON to OFF so fast that the LEDs appeared dim 8-|
		 * 
		 * Loop trough the array and assign each element to PORTA. The
		 * image I made the array from is 8x68, that is to say 8 px high
		 * and 68 px wide. Why 8? We have 8 LEDs :P The width is 
		 * arbitrary. I made it 68 pixels to make room to add patterns 
		 * and then I used the crop tool (GIMP) to size the image. 
		 * Easy peasy ;-)
		 */

		for (int i = 0; i < PIXELS; i++) {
			PORTA = audreyLED[i];
			_delay_us(400);
		}

		/* Set all the pins lo and delay for a few ms to give our eyes
		 * a chance to catch up before doing it again ;-) This could
		 * be written as "PORTA = 0x00;" or "PORTB = 0;".
		 */
		PORTA = 0b00000000;
		_delay_ms(10);
	 }
 }

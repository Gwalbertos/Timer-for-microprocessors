#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 1000000UL

volatile long licznik = 0;

ISR(TIMER0_COMPA_vect)
{
  licznik ++;
}

int main(void)
{

  

  TCCR0A = (1 << WGM01);
  TCCR0B = (1 << CS02) | (1 << CS00);

  OCR0A = 199;
  TIMSK |= (1 << OCIE0A);

  sei();



  DDRB |= (1 << PB4);
  PORTB &= ~(1 << PB4); 
  int dioda = 0;
  while(1)
  {
    if (licznik >= 1476575 && dioda == 0)
    {
      PORTB ^= (1 << PB4); 
      dioda = 1;
    }

    if (licznik >= 1476700 && dioda == 1)
      {
        PORTB ^= (1 << PB4); 
        licznik = 0;
      }

    
  }

}

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <compat/ina90.h>
#include <util/delay.h>

#include "acher_main.h"
#include "acher_config.c"

int main(void){
config();

while(1) {
  SMCR|=(1<<SE);
  _SLEEP();
  SMCR&=~(1<<SE);
}
}

ISR(USART_RX_vect) {
if(show_lim<CHAR_NUM){ char_ram[show_lim++]=UDR0; }
if(char_ram[show_lim-1]==BORRAR){ show_lim=0; }
if(show_lim==0x00){ timer_int(0); }else{ timer_int(1); }
}	

ISR(TIMER0_COMPA_vect) {
uint8_t x;

line_write(0);

if (l==LINES-1) { l=0; }
else { l++;}

line_shadow=_BV(l);

for(x=0;x<COLUMNS;x++){ shiftr_write(line_shadow&leds[x]); }

line_write(line_shadow);
}

ISR(TIMER1_COMPA_vect) {
uint8_t i;

for(i=0;i<COLUMNS;i++){ leds[i]=leds[i+1]; }

if (show_col==CHAR_WIDTH){
  leds[COLUMNS-1]=0;
  show_col=0;
  show_char++;
  if(show_char==show_lim){ show_char=0; }
} else {
  leds[COLUMNS-1]=pgm_read_byte(&CHAR_ROM[(char_ram[show_char]*CHAR_WIDTH)+show_col++]);
}
}

void shiftr_write(uint8_t byte){
SHIFT&=~_BV(SHIFT_CLK);

if(byte!=0){ SHIFT&=~_BV(SHIFT_DATA); }
else { SHIFT|=_BV(SHIFT_DATA); }
		
cli();
_delay_us(1);
SHIFT|=_BV(SHIFT_CLK);
_delay_us(1);
sei();
}

void line_write(uint8_t byte){
PORTC=~byte;
PORTD=~((byte>>4)&(_BV(2)|_BV(3)));
}

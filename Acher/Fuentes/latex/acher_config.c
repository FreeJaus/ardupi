void config(void){

conf_ports();
conf_variables();
conf_timers();
conf_serial();

SMCR&=~((1<<SM2)|(1<<SM1)|(1<<SM0));
PRR&=~((1<<PRADC)|(1<<PRTIM2)|(1<<PRTWI));

sei();
}

void conf_ports(void){
DDRB|=_BV(SHIFT_DATA)|_BV(SHIFT_CLK);
PORTB=0x00;
DDRC=0xFF;
PORTC=0xFF;
DDRD|=_BV(2)|_BV(3);
PORTD=0xFF;
}

void conf_variables(void){
unsigned char n;

show_col=show_char=show_lim=line_shadow=0;
for(n=0;n<COLUMNS;n++){
  leds[n]=0;
  shiftr_write(1);
}
for(n=0;n<CHAR_NUM;n++){ char_ram[n]=0; }
l=LINES-1;
}

void conf_timers(void){
TCNT0=0;
TCNT1=0;
OCR0A=LINE_LIMIT;
OCR1A=COLUMN_LIMIT;

TCCR0A|=1<<WGM01;
TCCR0B|=1<<CS02;
TCCR0B|=1<<CS00;

TCCR1B|=1<<WGM12;
TCCR1B|=1<<CS12;
TCCR1B|=1<<CS10;

TIFR0=0;
TIFR1=0;

timer_int(1);
}

void conf_serial(void){
UBRR0H=(UBR_VAL>>8);
UBRR0L=UBR_VAL;

UCSR0A&=~((1<<U2X0)|(1<<RXC0)|(1<<TXC0));
UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00); 
UCSR0C&=~((1<<UMSEL01)|(1<<UMSEL00)|(1<<UPM01)|(1<<UPM00)|(1<<USBS0));
UCSR0B|=(1<<RXEN0)|(1<<RXCIE0);
UCSR0B&=~((1<<UCSZ02)|(1<<TXCIE0));
}

void timer_int(uint8_t byte){
if(byte==0x00){
  TIMSK0&=~(1<<OCF0A);
  TIMSK1&=~(1<<OCF1A);
} else {
  TIMSK0|=1<<OCF0A;
  TIMSK1|=1<<OCF1A;
}
}

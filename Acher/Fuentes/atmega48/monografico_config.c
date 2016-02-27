/*####################################################################
#                                                                    #
# Copyright 2010                                                     #
# Unai Martinez Corral <umartinez012@ikasle.ehu.es>                  #
#                                                                    #
# This file is part of Acher.                                        #
#                                                                    #
# Acher is free software: you can redistribute it and/or modify      #
# it under the terms of the GNU General Public License as published  #
# by the Free Software Foundation, either version 3 of the License,  #
# or (at your option) any later version.                             #
#                                                                    #
# Acher is distributed in the hope that it will be useful, but       #
# WITHOUT ANY WARRANTY; without even the implied warranty of         #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  #
# General Public License for more details.                           #
#                                                                    #
# You should have received a copy of the GNU General Public License  #
# along with Acher. If not, see <http://www.gnu.org/licenses/>.      #
#                                                                    #
####################################################################*/

void config(void){

conf_ports();
conf_variables();
conf_timers();
conf_serial();

SMCR&=~((1<<SM2)|(1<<SM1)|(1<<SM0)); //Configuramos modo de bajo consumo
PRR&=~((1<<PRADC)|(1<<PRTIM2)|(1<<PRTWI)); //Desactivamos ADC, Timer2 y TWI durante el bajo consumo

sei(); //Habilitamos las interrupciones
}

void conf_ports(void){ //Configuración e inicilización de los puertos
DDRB|=_BV(SHIFT_DATA)|_BV(SHIFT_CLK); // Bits shift_data y shift_clk del puerto B como salida
PORTB=0x00;
DDRC=0xFF; // Todo el puerto C como salida
PORTC=0xFF;
DDRD|=_BV(2)|_BV(3); // Bits 2 y 3 del puerto D como salida
PORTD=0xFF;
}

void conf_variables(void){ //Inicialización de variables
unsigned char n;

show_col=show_char=show_lim=line_shadow=0;
for(n=0;n<COLUMNS;n++){ // Cargamos de unos el shiftr para que no se muestre nada al inicio
	leds[n]=0;
	shiftr_write(1);
}
for(n=0;n<CHAR_NUM;n++){ char_ram[n]=0; } // Borramos la ram de caracteres
l=LINES-1;

}

void conf_timers(void){ //Configuración de los timers
//Inicializamos el valor del timer y el limite
TCNT0=0;
TCNT1=0;
OCR0A=LINE_LIMIT;
OCR1A=COLUMN_LIMIT;

//Seleccionamos el modo de trabajo CTC y los valores de los prescalers
TCCR0A|=1<<WGM01;
TCCR0B|=1<<CS02;
TCCR0B|=1<<CS00;

TCCR1B|=1<<WGM12;
TCCR1B|=1<<CS12;
TCCR1B|=1<<CS10;

//Limpiamos todos los flags (compA, compB, OV)
TIFR0=0;
TIFR1=0;

//Activamos la interrupción por comparación A
//Desactivamos las interrupciones: por comparación B y Timer Overflow
timer_int(1);
}

void conf_serial(void){
//Definimos el baud rate
UBRR0H=(UBR_VAL>>8);
UBRR0L=UBR_VAL;

//Modo asincrono normal, 1 bit start, 8 bits data, no paridad, 1 bit stop
//Limpiamos los flags de recepcion y transmision
//Habilitamos la recepcion y la interrupcion asociada, deshabilitamos la transmision

UCSR0A&=~((1<<U2X0)|(1<<RXC0)|(1<<TXC0));
UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00); 
UCSR0C&=~((1<<UMSEL01)|(1<<UMSEL00)|(1<<UPM01)|(1<<UPM00)|(1<<USBS0));
UCSR0B|=(1<<RXEN0)|(1<<RXCIE0);
UCSR0B&=~((1<<UCSZ02)|(1<<TXCIE0));
}

void timer_int(uint8_t byte){
if(byte==0x00){ // Desactiva las interrupciones de los timers 0 y 1
	TIMSK0&=~(1<<OCF0A);
	TIMSK1&=~(1<<OCF1A);
}else{ // Activa las interrupciones de los timers 0 y 1
	TIMSK0|=1<<OCF0A;
	TIMSK1|=1<<OCF1A;
}
}

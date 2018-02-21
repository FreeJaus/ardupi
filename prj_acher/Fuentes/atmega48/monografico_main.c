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

#include <avr/io.h> // Para que el compilador cargue los nombres de los registros
#include <avr/interrupt.h> // Para utilizar las interrupciones
#include <avr/pgmspace.h> // Para definir variables en espacios de memoria que no sean la RAM
#include <compat/ina90.h> // Para utilizar la función _SLEEP()
#include <util/delay.h> // Para generar delays mediante la función _delay_[u/m](t)

#include "monografico_main.h" // Declaración de funciones y variables
#include "monografico_config.c" // Rutina de configuración/inicialización

//-----------------------------------------------------------------------------------//

int main(void){
config(); // Lamamos a la rutina de configuración/inicialización

while(1) {
	SMCR|=(1<<SE); // Nos vamos a dormir
	_SLEEP();
	SMCR&=~(1<<SE);
}
}

ISR(USART_RX_vect) {
if(show_lim<CHAR_NUM){ // Si queda sitio libre en la ram de caracteres...
	char_ram[show_lim++]=UDR0; // Guardamos el dato recibido en la posición a la que apunta el límite y, después, lo incrementamos
}
if(char_ram[show_lim-1]==BORRAR){ show_lim=0;} // Si hemos recibido la orden de borrar, reiniciamos el puntero
if(show_lim==0x00){ timer_int(0); }else{ timer_int(1); } // Si no hay datos en la ram de caracteres, desactivamos los timers
}	

ISR(TIMER0_COMPA_vect) { //line_interrupt
uint8_t x;

line_write(0); // Desactivamos todas las líneas

if (l==LINES-1) { l=0; } // Si el ´puntero de línea se nos sale de rango, lo reinciamos
else { l++;} // Si segimos en rango, lo incrementamos

line_shadow=_BV(l); // Activamos en el shadow la línea a la que apunta l

for(x=0;x<COLUMNS;x++) { // Cargamos en el shiftr los bits correspondientes a la línea l de cada columna de leds[]
shiftr_write(line_shadow&leds[x]);
}

line_write(line_shadow); // Activamos la línea a la que apunta l, mediante el shadow
}

ISR(TIMER1_COMPA_vect) { //column_interrupt
uint8_t i;
	//for(i=columns-1;i>0;i--){ leds[i]=leds[i-1]; }
	for(i=0;i<COLUMNS;i++){ leds[i]=leds[i+1]; } // Desplazamos todas las columnas

	if (show_col==CHAR_WIDTH){ // Si nos hemos pasado del ancho del caracter
		leds[COLUMNS-1]=0; // Escribirmos una columna en blanco
		show_col=0; // Reiniciamos el puntero de la columna del caracter
		show_char++; // Incrementamos el puntero de caracter
		if(show_char==show_lim){ show_char=0; } // Si el puntero de caracter se sale de rango, lo reiniciamos
	} else { // Si no nos hemos pasado del ancho, escribirmos la siguiente columna del caracter, después incrementamos el puntero
		leds[COLUMNS-1]=pgm_read_byte(&CHAR_ROM[(char_ram[show_char]*CHAR_WIDTH)+show_col++]);
	}
}

void shiftr_write(uint8_t byte){
SHIFT&=~_BV(SHIFT_CLK); // Señal clk a 0

if(byte!=0){ SHIFT&=~_BV(SHIFT_DATA); } // Si hemos recibido un 0, cargamos un 0 en data
else { SHIFT|=_BV(SHIFT_DATA); } // Si hemos recibido !=0, cargamos un 1 en data
		
cli(); // Desactivamos las interrupciones
_delay_us(1); // Esperamos 1us

SHIFT|=_BV(SHIFT_CLK); // Señal clk a 1

_delay_us(1); // Esperamos 1us
sei(); // Activamos las interrupciones
// Los retardos los introducimos para cumplir las especificaciones del shiftr(74164)
}

void line_write(uint8_t byte){ // Escribirmos el byte recibido en las patillas asociadas a las líneas
PORTC=~byte;
PORTD=~((byte>>4)&(_BV(2)|_BV(3)));
}

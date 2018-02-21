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

/* Parametrizacion */

#define LINES 5			//Número de líneas de la matriz
#define COLUMNS 8		//Número de columnas de la matriz
#define CHAR_NUM 40		//Número máximo de caracteres a mostrar
#define CHAR_WIDTH 5		//Anchura de los caracteres, en pixeles

#define BORRAR 0x7E		//Código de borrado (puerto serie)

#define SHIFT PORTB		//Puerto al que están conectados los registros de desplazamiento
#define SHIFT_DATA 1		//Pin del puerto al que está conectada la salida de datos
#define SHIFT_CLK 2		//Pin del puerto al que está conectada la señal de reloj
  
#define LINE_LIMIT 25;		//Limite timer lines
#define COLUMN_LIMIT 2700;	//Limite timer columns

#define FREC 11059200		//Frecuencia del reloj en Hz
#define BAUDRATE 19200
#define UBR_VAL ((FREC/(BAUDRATE*16UL))-1)

/* Funciones */

void config(void);
void conf_ports(void);
void conf_variables(void);
void conf_timers(void);
void conf_serial(void);

void shiftr_write(uint8_t byte);
void line_write(uint8_t byte);
void timer_int(uint8_t byte);

/* Variables */

uint8_t show_col,show_char,show_lim;
unsigned char char_ram[CHAR_NUM];
uint8_t leds[COLUMNS];
uint8_t line_shadow,l;

/* Tabla de caracteres bit a bit */

const uint8_t CHAR_ROM[] PROGMEM= {
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
  0,0,0,0,0,
62	,	65	,	89	,	81	,	14	,
124	,	18	,	17	,	18	,	124	,
127	,	73	,	73	,	73	,	54	,
62	,	65	,	65	,	65	,	34	,
127	,	65	,	65	,	65	,	62	,
127	,	73	,	73	,	73	,	65	,
127	,	9	,	9	,	9	,	1	,
62	,	65	,	73	,	41	,	122	,
127	,	8	,	8	,	8	,	127	,
0	,	65	,	127	,	65	,	0	,
32	,	64	,	64	,	64	,	63	,
127	,	8	,	8	,	20	,	99	,
127	,	64	,	64	,	64	,	64	,
127	,	2	,	12	,	2	,	127	,
127	,	2	,	4	,	8	,	127	,
62	,	65	,	65	,	65	,	62	,
127	,	9	,	9	,	9	,	6	,
62	,	65	,	81	,	33	,	94	,
127	,	9	,	9	,	9	,	118	,
38	,	73	,	73	,	73	,	50	,
1	,	1	,	127	,	1	,	1	,
63	,	64	,	64	,	64	,	63	,
31	,	32	,	64	,	32	,	31	,
127	,	32	,	24	,	32	,	127	,
99	,	20	,	8	,	20	,	99	,
7	,	8	,	112	,	8	,	7	,
97	,	81	,	73	,	69	,	67	,
0	,	0	,	0	,	127	,	65	,
3	,	4	,	8	,	16	,	96	,
65	,	127	,	0	,	0	,	0	,
0	,	2	,	1	,	2	,	0	,
64	,	64	,	64	,	64	,	64	,
0	,	1	,	3	,	0	,	0	,
32	,	84	,	84	,	84	,	120	,
127	,	72	,	68	,	68	,	56	,
56	,	68	,	68	,	68	,	0	,
56	,	68	,	68	,	36	,	127	,
56	,	84	,	84	,	84	,	72	,
0	,	4	,	126	,	5	,	0	,
14	,	81	,	81	,	73	,	63	,
127	,	24	,	4	,	4	,	120	,
0	,	0	,	125	,	0	,	0	,
0	,	64	,	61	,	0	,	0	,
127	,	16	,	40	,	68	,	0	,
0	,	0	,	127	,	0	,	0	,
120	,	4	,	8	,	4	,	120	,
124	,	4	,	4	,	4	,	120	,
56	,	68	,	68	,	68	,	56	,
126	,	10	,	18	,	18	,	28	,
28	,	18	,	18	,	10	,	126	,
124	,	8	,	4	,	4	,	0	,
72	,	84	,	84	,	84	,	36	,
4	,	62	,	68	,	68	,	0	,
60	,	64	,	64	,	64	,	124	,
28	,	32	,	64	,	32	,	28	,
60	,	64	,	56	,	64	,	60	,
68	,	40	,	16	,	40	,	68	,
12	,	80	,	80	,	80	,	60	,
68	,	100	,	84	,	76	,	68	,
0	,	0	,	8	,	54	,	65	,
0	,	0	,	127	,	0	,	0	,
65	,	54	,	8	,	0	,	0	,
8	,	4	,	8	,	4	,	0	};


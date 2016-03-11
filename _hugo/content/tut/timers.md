---
title: "Timers"
keywords: timer

publishdate: 2016-01-01
date: 2016-01-01

coord:
 - nick: Joseba SdM
   ehu: joseba.sainzdemurieta
   github: sebotas007
---

Los temporizadores, también llamados timers o timers/counters, son unos periféricos de los que disponen la práctica totalidad de microcontroladores que se emplean para implementar diversas funciones relacionadas con el tiempo o con el contaje. En realidad, estos periféricos son contadores. Cuando lo que están contando es una frecuencia fija derivada del cristal oscilador del microcontrolador, se denominan timers y, cuando lo que están contando es un evento (flanco de subida o flanco de bajada) en una patilla del microcontrolador, se denominan contadores. Si bien el funcionamiento es análogo, en este tutorial nos centraremos en las aplicaciones como temporizador/timer. Dependiendo del microcontrolador tendremos más o menos timers y, dependiendo del tamaño del registro en el que almacenan el contaje, hablaremos de timers de `8 bits` o de `16 bits`.

Si bien las explicaciones que siguen a continuación pueden adaptarse a diferentes modelos de placas de desarrollo de Arduino, el código y los registros indicados harán referencia a las placas [Mega ADK](http://arduino.cc/en/Main/ArduinoBoardADK) y [Mega 2560](http://arduino.cc/en/Main/ArduinoBoardMega2560). Estas dos placas comparten el microprocesador de `8 bits` [ATmega2560](http://www.atmel.com/dyn/resources/prod_documents/doc2549.PDF) el cual cuenta con dos timers de `8 bits` (el `Timer 0` y el `Timer 2`) y cuatro temporizadores de `16 bits` (los timers `1`, `3`, `4` y `5`).

Como hemos dicho, son muchas las ocasiones en las que necesitaremos implementar funciones relacionadas con el tiempo, por lo que Arduino ha desarrollado varias funciones software para las necesidades más usuales:

- para realizar retardos y contaje de tiempo: [`millis()`](http://arduino.cc/en/Reference/Millis), [`micros()`](http://arduino.cc/en/Reference/Micros), [`delay()`](http://arduino.cc/en/Reference/Delay) y [`delayMicroseconds()`](http://arduino.cc/en/Reference/DelayMicroseconds).

- para generar señales PWM: [`analogWrite()`](http://arduino.cc/en/Reference/AnalogWrite)

Todas estas funciones de Arduino relacionadas con el tiempo hacen uso de alguno de los temporizadores del microcontrolador **ATmega2560** comprendidos entre el `Timer 0` y el `Timer 2`. Si bien son muy cómodas y fáciles de utilizar, en ocasiones pueden no darnos la versatilidad y funcionalidad que deseamos por lo que tendremos que manejar directamente los timers del microcontrolador. Para poder seguir usando estas funciones, en este tutorial se realizarán las explicaciones para el `Timer 3`, dejando libres así los timers `0`, `1` y `2`.

Por, último, antes de empezar, algunas nociones sobre una de las aplicaciones más usadas y que requerirá de la configuración directa de los timers: la modulación de anchura de pulsos o PWM.

# La Modulación de Anchura de Pulsos - Pulse Width Modulation (PWM)

La **modulación de anchura de pulsos**, en inglés **Pulse Width Modulation (PWM)**, es una técnica que consiste en modificar la anchura de un pulso y que es ampliamente utilizada en convertidores de potencia, control de motores, cargadores de baterías, y un largo etcétera.
Para un periodo determinado, se denomina Duty Cycle al tiempo que el pulso se mantiene activo. De esta forma, el Duty Cycle determinará el valor medio del voltaje entregado a la carga.

La frecuencia de la PWM la determinaremos en función de la carga que estemos alimentando. Así por ejemplo, si la señal PWM la vamos a utilizar para regular la potencia de un elemento calefactor, podría ser una fracción de hercio, para iluminación puede oscilar entre 50 y 150Hz, para el control de algunos servomotores comerciales (típicos para pequeños autómatas y robots como los servomotores Futaba) tendrá que ser de 50Hz y para el control de carga de baterías y control de drivers de motores puede llegar a los 16KHz.

Cuando la señal PWM se emplea para controlar transistores de potencia, habrá que determinar la frecuencia buscando un compromiso entre un funcionamiento fino del dispositivo, el ruido que pueda producir si nos movemos en frecuencias audibles y las perdidas por conmutación de los interruptores de potencia (que aumentarán proporcionalmente al número de veces que tengan que conmutar por segundo).

Una vez determinada la frecuencia de la PWM apropiada para nuestra aplicación, el control de la potencia que queremos entregar lo lograremos controlando el ancho del pulso, el Duty Cycle, el cual podrá venir expresado en términos absolutos (segundos, milisegundos,..) o en porcentaje del Duty Cycle.

Dada la utilidad y frecuente uso de la técnica PWM, la plataforma [Arduino](http://www.arduino.cc/es/) ha provisto una sencilla forma de generar este tipo de señales en sus diferentes placas de desarrollo.

## PWM empleando la función analogWrite()

Empleando la función `analogWrite(pin, dutyCycle)` podemos generar fácilmente una señal PWM en el pin indicado modulando el `dutyCycle` con un valor comprendido entre `0` y `255`.

- *Sintaxis*
  - `analogWrite(pin, valor)`
- *Parámetros*
  - `pin`: número del pin en el que  queremos generar la PWM.
  - `valor`: duty cycle entre `0` (siempre apagada) y `255` (siempre encendida).
- *Devuelve*
  - Nada

Dependiendo de la placa empleado, tendremos más o menos pines sobre los que actuar con esta función. En el caso de las placas **Mega**, disponemos de los pines comprendidos entre el `2` y el `13`, así como el `44` y `46` (en la [Arduino Uno](http://arduino.cc/en/Main/ArduinoBoardUno) sólo disponemos de los pines `3`, `5`, `6`, `9`, `10` y `11`).

Si bien esta es la forma más sencilla de generar una PWM, el problema es que no tenemos ningún control sobre la frecuencia de esta señal siendo, en el caso de la **Mega**, de `490Hz`.

Un poco más adelante, en este mismo tutorial, veremos como generar señales PWM con mucho mayor control y versatilidad configurando directamente los timers del micro.

Pero antes, vamos a ver algunos conceptos de la arquitectura hardware del microcontrolador que nos serán necesarios para poder manejar los timers.

# Configurando directamente los temporizadores del microcontrolador.

Como he comentado anteriormente, a grandes rasgos, un Timer/Counter es un periférico interno del microcontrolador que se emplea para contar eventos relacionados con el tiempo (Timer) o eventos externos que aparecen en una de las patillas del micro (Counter).

Este contaje se realiza sobre un registro de `8 bits` o sobre un registro de `16 bits` y puede ser consultado, reseteado, comparado, etc. En el caso del **ATmega2560**, la cuenta se lleva sobre los registros llamados `TCNTn` (siendo `n` el número del timer).

En caso de configurarlo como contador, la patilla sobre la que se aplican los eventos que provocarán el contaje, no será una patilla cualquiera sino la patilla asociada a la entrada del temporizador correspondiente. A modo de ejemplo, en el caso del `Timer 3` del **ATmega2560**, la patilla de entrada asociada es la patilla número `8`, etiquetada como `T3`.

En caso de configurarlo como temporizador, los eventos que provocarán el contaje serán fracciones de la frecuencia de oscilación del cristal oscilador principal del micro aunque, en algunos casos, puede disponerse de un cristal auxiliar para independizar las frecuencias del micro y del temporizador.

En lo sucesivo, cuando haga referencia a la frecuencia de oscilación lo haré a la del cristal oscilador de la placa **Mega**, que es de `16MHz`.

Bien, conocida la frecuencia de oscilación de nuestro microcontrolador, lo siguiente será determinar que pines del microcontrolador están relacionados con el funcionamiento del `Timer 3`. En nuestro caso son los pines `OC3A`, `OC3B`, `OC3C`, `T3` e `ICP3` siendo los tres primeros las salidas del timer y los que tenemos accesibles en la placa **ArduinoMega**.

| | Nº de pin en el ATmega2560 | Nº de pin en la placa ArduinoMega |
|---|---|---|
| OC3A | 5 | DigitalPin5 (PWM) |
| OC3B | 6 | DigitalPin2 (PWM) |
| OC3C | 7 | DigitalPin3 (PWM) |

A continuación pasaríamos a analizar cuales son los registros internos del microcontrolador que nos permiten configurar y trabajar con el `Timer 3`.

Estos registros son los siguientes:

| REGISTRO | Nº DE BITS | |
|---|---|---|
| TCNT3  | 16 | Timer/Counter |
| OCR3A  | 16 | Output Compare Register A |
| OCR3B  | 16 | Output Compare Register B |
| OCR3C  | 16 | Output Compare Register C |
| ICR3   | 16 | Input Capture Register |
| TCCR3A | 8  | Timer/Counter Register Control A |
| TCCR3B | 8  | Timer/Counter Register Control B |
| TCCR3C | 8  | Timer/Counter Register Control C |
| TIFR3  | 8  | Timer Interrupt Flag Register |
| TIMSK3 | 8  | Timer Interrupt Mask Register |

A continuación explicaré cual es la función de cada uno de ellos.

**TCNT3**: Es un registro de `16 bits` que almacena el valor del contaje de tiempo. Este valor estará comprendido entre `0` y `2^16=65536`.

Vamos a ocuparnos en primer lugar de los registros de control y de las diferentes posibilidades que nos ofrecen en función de los valores que escribamos en sus bits.

## Registros de configuración `TCCR3A`, `TCCR3B` y `TCCR3C`

Según los valores que escribamos en los bits de estos bits, podremos determinar la frecuencia a la que funciona el timer, su modo de funcionamiento y el comportamiento de los pines de salida asociados al mismo.

| | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|---|---|---|---|---|---|---|---|---|
|**TCCR3A**| COM3A1 | COM3A0 | COM3B1 | COM3B0 | COM3C1 | COM3C0 | WGM31 | |WGM30 |
|**TCCR3B**| ICNC3 |  ICES3 | - | WGM33  | WGM32 | CS32 | CS31 | CS30 |
|**TCCR3C**| FOC3A | FOC3B | FOC3C | - | - | - | - | - |

### Selección de la frecuencia de funcionamiento del Timer (Clock Select)

La determinación de si el `Timer/Counter 3` funciona como contador (contaje de eventos externos en la patilla `T3`) o como temporizador sincronizado con la frecuencia de oscilación o con una fracción de ella, se realiza a través de los bits `CS32`, `CS31` y `CS30` del registro `TCCR3B`:

| CS32 | CS31 | CS30 | |
|---|---|---|---|
| 0 | 0 | 0 | Timer/Counter 3 detenido |
| 0 | 0 | 1 | Timer Fclock=Fosc/1 (Sin prescaler) |
| 0 | 1 | 0 | Timer Fclock=Fosc/8 (Prescaler=8) |
| 0 | 1 | 1 | Timer Fclock=Fosc/64 (Prescaler=64) |
| 1 | 0 | 0 | Timer Fclock=Fosc/256 (Prescaler=256) |
| 1 | 0 | 1 | Timer Fclock=Fosc/1024 (Prescaler=1024) |
| 1 | 1 | 0 | Contador de flancos de bajada en el pin T3 |
| 1 | 1 | 1 | Contador de flancos de subida en el pin T3 |

Centrándonos en el funcionamiento en modo temporizador, el prescaler permite decrementar la velocidad de contaje del timer permitiéndonos obtener un mayor rango de tiempos.

Veremos ejemplos de estos tiempos para cada uno de los modos de funcionamiento del Timer/Counter.

### Modos de funcionamiento del Timer/Counter

Los diferentes modos de funcionamiento del `Timer/Counter 3` se determinan a través de los bits `WGM33`, `WGM32`, `WGM31` y `WGM30` de los registros `TCCR3A` y `TCCR3B`.

| WGM33 | WGM32 | WGM31 | WGM30 | MODO | TOP | UPDATE | TOV3 |
|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | Normal Mode | 0xFFFF | Inmediato | MAX |
| 0 | 0 | 0 | 1 | PWM, Phase Correct 8 | 0x00FF | TOP | BOTTOM |
| 0 | 0 | 1 | 0 | PWM, Phase Correct 9 | 0x01FF | TOP | BOTTOM |
| 0 | 0 | 1 | 1 | PWM, Phase Correct 10 | 0x03FF | TOP | BOTTOM |
| 0 | 1 | 0 | 0 | CTC | OCR3A | Inmediato | MAX | 
| 0 | 1 | 0 | 1 | Fast PWM, 8 bit | 0x00FF | BOTTOM | TOP |
| 0 | 1 | 1 | 0 | Fast PWM, 9 bit | 0x01FF | BOTTOM | TOP |
| 0 | 1 | 1 | 1 | Fast PWM, 10 bit | 0x03FF | BOTTOM | TOP |
| 1 | 0 | 0 | 0 | PWM Phase & Freq. Correct | ICR3A | BOTTOM | BOTTOM |
| 1 | 0 | 0 | 1 | PWM Phase & Freq. Correct | OCR3A | BOTTOM | BOTTOM |
| 1 | 0 | 1 | 0 | PWM Phase Correct | ICR3 | TOP | BOTTOM |
| 1 | 0 | 1 | 1 | PWM Phase Correct | OCR3A | TOP | BOTTOM |
| 1 | 1 | 0 | 0 | CTC | ICR3 | Inmediato | MAX |
| 1 | 1 | 0 | 1 | (Reserved) | - | - | - |
| 1 | 1 | 1 | 0 | Fast PWM | ICR3 | BOTTOM | TOP | 
| 1 | 1 | 1 | 1 | Fast PWM | OCR3A | BOTTOM | TOP | 

### Comportamiento de los pines de salida `OC3A`, `OC3B` y `OC3C` asociados al `Timer 3`:

Mediante los bits `COM3A1`, `COM3A0`, `COM3B1`, `COM3C1` y `COM3C0` determinaremos el comportamiento de los pines de salida del microcontrolador asociados al `Timer 3`.

Este timer dispone de tres canales de salida (`A`, `B` y `C`) en las patillas `5`, `6` y `7` (conectadas a las patillas `5`, `2` y `3` respectivamente en la placa **Mega** de *Arduino*). El comportamiento de estas patillas dependerá del modo de funcionamiento seleccionado y del valor que establezcamos en los bits de configuración de acuerdo a las siguientes tablas.

MODO NO PWM

| COM3X1 | COM3X0 | |
|---|---|---|
| 0 | 0 | Salidas OC3A/OC3B/OC3C desconectadas |
| 0 | 1 | Las salidas OC3A/OC3B/OC3C basculan cuando se alcanza la comparación |
| 1 | 0 | Las salidas OC3A/OC3B/OC3C se ponen a `0` cuando se alcanza la comparación |
| 1 | 1 | Las salidas OC3A/OC3B/OC3C se ponen a `1` cuando se alcanza la comparación |

MODO FAST PWM

| COM3X1 | COM3X0 | |
|---|---|---|	
| 0 | 0 | Salidas OC3A/OC3B/OC3C desconectadas |
| 0 | 1 | La salidas OC3A bascula cuando se alcanza la comparación. OC3B y OC3C desconectadas |
| 1 | 0 | Las salidas OC3A/OC3B/OC3C se ponen a `0` cuando se alcanza la comparación y se ponen a `1` al alcanzar el límite inferior BOTTOM |
| 1 | 1 | Las salidas OC3A/OC3B/OC3C se ponen a `1` cuando se alcanza la comparación y se ponen a `0` al alcanzar el límite inferior BOTTOM |

MODO PWM CON CORRECCIÓN DE FASE Y FRECUENCIA

| COM3X1 | COM3X0 | |
|---|---|---|
| 0 | 0 | Salidas OC3A/OC3B/OC3C desconectadas |
| 0 | 1 | La salidas OC3A bascula cuando se alcanza la comparación. OC3B y OC3C desconectadas |
| 1 | 0 | Las salidas OC3A/OC3B/OC3C se ponen a `0` cuando se alcanza la comparación ASCENDENTE y se ponen a `1` al alcanzar la comparación descendente |
| 1 | 1 | Las salidas OC3A/OC3B/OC3C se ponen a `1` cuando se alcanza la comparación ASCENDENTE y se ponen a `0` al alcanzar la comparación descendente |

Si bien ahora mismo puede parecer un poco complicado, vamos a ver cada uno de los modos de funcionamiento para comprender su funcionamiento.

#### Normal Mode:

En este modo de funcionamiento, el registro de `16 bits` `TCNT3` se va incrementando a una velocidad determinada por el prescaler.

Cuando alcanza su valor máximo (`0xFFFF`), el registro se vuelve a poner a `0x000` automáticamente. A esto se le denomina desbordamiento u overflow.

La pregunta es ahora, ¿que ocurre cuando se desborda el timer? ¿cómo sabremos que se ha desbordado?. Dependiendo de como hayamos configurado los bits `COM3A1`, `COM3A0`, `COM3B1`, `COM3C1` y `COM3C0`, este desbordamiento se reflejará en los pines de salida correspondientes (`OC3A`, `OC3B` y `OC3C`) o no de acuerdo a lo indicado en la tabla anterior.

Aunque hayamos decidido que este desbordamiento no se refleje en el pin de salida correspondiente, siempre se señalizará en el bit de `Timer Overflow` `TOV3` del registro `TIFR3` (será necesario ponerlo a cero por software). En caso de tener habilitada la interrupción asociada a este timer mediante el bit `Timer 3 Overflow Interrupt` del registro `TIMSK3`, se activaría la interrupción y se produciría el salto del programa al vector `TIMER3 OVF`.

Y por último, ¿que tiempo tardará el timer en desobordarse?. Bien, este tiempo dependerá de la frecuencia del oscilador al que tengamos conectado nuestro microcontrolador (en nuestro caso `16MHz`), del prescaler o fracción de esta frecuencia a la cual hayamos configurado el timer y del valor desde el que el timer inicia su cuenta (valor que cargamos en el registro `TCNT3`).

    T=Tosc·PS·(65536-TCNT3)

Así, los tiempos máximos de desbordamiento los conseguiremos cuando la cuenta comienza en cero, siendo éstos para los diferentes prescalers:

    PS=1    -> T=65536·62,5ns·1=4,096ms
    PS=8    -> T=65536·62,5ns·8=32,768ms
    PS=64   -> T=65536·62,5ns·64=262,144ms
    PS=256  -> T=65536·62,5ns·256=1,048s
    PS=1024 -> T=65536·62,5ns·1024=4,194s

# Ejemplos
	
Vamos a ver algunos ejemplos relacionados con este modo de funcionamiento:

## Ejemplo 1. Ejecución de un programa controlada por tiempo.

Una de las aplicaciones más interesantes de los timers es la gestión de una interrupción controlada por tiempo de forma que consigamos que una serie de tareas se ejecuten periódicamente teniendo controlado el tiempo de este periodo.

En este ejemplo vamos a realizar un programa que realice una lectura del canal analógico `0` cada `100ms` y envía esta lectura por el monitor serie.

Para ello vamos a configurar el `Timer 3` de forma que se desborde cada 100ms. Este desbordamiento provocará la activación de la interrupción de overflow de este Timer. En este momento, el programa detendrá su ejecución cíclica normal y saltará al vector de interrupción correspondiente, en el cual escribiremos las acciones a realizar de forma periódica.

Para empezar, si miramos los tiempos que podemos conseguir con el microcontrolador **ATmega2560** conectado a un cristal de `16MHz`, observamos que necesitaremos un prescaler de `64`, el cual nos permitiría contajes de hasta `262ms`.

A continuación, calculamos desde que valor deberá iniciar el contaje el `Timer 3` para que su desbordamiento se produzca a los `100ms`:

    T = 100ms = 62,5ns · 64 · (65536 - TCNT3) ---> TCNT3 = 40536

Este será el valor de precarga o preset del `Timer 3`. Cada vez que se desborde, volveremos a cargarle este valor de inicio de contaje para que el siguiente desbordamiento vuelva a producirse a los `100ms`.

El programa quedaría de la siguiente forma:
 
```
/*--------------------------------------------------------------------------------
  Este programa realiza una lectura del canal analógico 0
  cada 100ms y envía esta lectura al terminal serie.
  Cada vez que realiza la lectura y el envió, bascula el
  estado del pin 13 conectado a la placa de Arduino MegaADK
*/

int cont=0;             //Variable que almacena el nº de lecturas

void setup() {
  pinMode(13, OUTPUT);  //EL pin conectado al LED en modo salida
  Serial.begin(9600);   //Monitor serie a 9600 baudios
  TCCR3A = B00000000;   //Modo Normal con salidas desactivadas
  TCCR3B = B00000011;   //Prescaler PS=64
  TCNT3=40536;          //Valor de inicio del Timer 3 para 100ms
  TIMSK3=(1<<TOIE3);    //Interrupción de overflow del Timer 3
  sei();                //Habilitación de las interrupciones
}

void loop(){
   //Aquí iría el cuerpo del programa principal
   //el cual se ejecutaría cíclicamente
}

/*-----------------------------------------------------------
  Rutina de OVERFLOW del TIMER 3
*/

ISR(TIMER3_OVF_vect){
    TCNT3=40536;                        //Recarga del Timer 3
    //bitClear(TIFR3,0);
    Serial.println(cont);               //Envía el nº de lectura
    Serial.println(analogRead(0));      //Envía la lectura del canal 0
    cont=cont++;
    digitalWrite(13, !digitalRead(13)); //Bascula el estado del pin 13
}
```

Esta utilización de los temporizadores es muy frecuente y tremendamente útil ya que, cuando deseemos realizar alguna aplicación en la que tengamos que realizar muestreos de determinados sensores (p. ej. medidas de corriente, de tensión, de temperatura,...), el mantener el periodo de muestreo constante será fundamental para poder realizar después los cálculos necesarios con los valores muestreados.

---
categories: [ nb-rc ]

title: Sesiones
keywords:

publishdate: 2016-01-01
date: 2015-11-20
---
 
# SESIÓN 1

- Montar todas las piezas del chasis y la carrocería.
- Analizar qué piezas faltan en comparación con los otros vehículos (comerciales).
- Analizar qué motores hacen falta y qué características (tamaño, potencia...) debe tener cada uno.

# SESIÓN 2

- Montar los motores y los componentes electrónicos fuera del chasis y comprobar el funcionamiento.
  - https://123d.circuits.io/circuits/1568139-gazteleku-urduliz-coches-teledirigidos-control-de-motores
- Montarlo todo en el chasis y comprobar el funcionamiento con el joystick cableado.

*NOTA: como el variador alimenta al Arduino, al encenderlo todo al mismo tiempo el servomotor se mueve ligeramente. Hay que analizar si esto supone un problema al estar montado y engranado a la dirección. Si es así, se deberá encender el variador con el servo desconectado, y esperar a que arranque Arduino antes de conextarlo.*

- Analizar las señales que se leen del joystick (analógicas)
- Analizar las señales que se envían desde el Arduino al servomotor y al variador (digitales, 20ms de periodo, 1-2ms de pulso).
- Analizar la señal que se envía desde el variador al motor de corriente continua (digital, PWM).
- Conocer un circuito con componentes discretos (resistencias, potenciómetros, condensadores y 556) que permite controlar ambos motores.
- Entender las diferencias entre un circuito con componentes discretos y el uso de un microcontrolador, sus ventajas e inconvenientes.
- Entender la programación utilizada en el Arduino:

```
#include <Servo.h>

Servo drive, steer;

void setup() {
  drive.attach(4);
  steer.attach(5);
  
}

void loop() {
  steer.write( map(analogRead(A0), 0, 1023, 60, 120) );
  drive.write( map(analogRead(A1), 0, 1023, 60, 120) );
  delay(15);
}
```

- Añadir un pulsador y modificar la programación para poder configurar el rango del servomotor de forma análoga al variador para la tracción. Incluir también la posibilidad de realizar un ajuste fino para identificar los límites físicos del chasis (que serán previsiblemente menores que el ángulo de giro del servomotor):
  - https://123d.circuits.io/circuits/1588306-gazteleku-urduliz-coches-teledirigidos-ajuste-de-senales-de-control

```
#include <Servo.h>
#include <EEPROM.h>

Servo dr, st;
int conf, k, k_lim, dr_conf[2], st_conf[6]; //={0,1023} ={0,511,1023,60,90,120};;
bool k_tg = false;

const int set_btn = 7;
const int dr_an = 1, st_an = 0;

void setup() {
  dr.attach(4);
  st.attach(5);
  pinMode(set_btn, INPUT_PULLUP);

  conf=0;
  k=0;
  k_lim=199;
  EEPROM.get(0,dr_conf);
  EEPROM.get(sizeof(dr_conf),st_conf);

  Serial.begin(9600); //!
}

void loop() {
  serialsend(); //!
  
  bool btn=button();
  if (conf) {
    if ((conf-5)>0) {
      int dif = analogRead(st_an)-st_conf[1];
      if (abs(dif)>50) { st.write(st.read()+sgn(dif)); }
    }
    if (btn) {configuration();}
  }
  else { if (btn) {conf=1; k_lim=66;} else { update_servos(); } }
  delay(15);
}

bool button(void) {
  if (digitalRead(set_btn)==k_tg) { if (k++>k_lim) { k_tg=!k_tg; return k_tg; } }
  else { k=0; }
  return false;
}

void update_servos(void) {
  int st_read=analogRead(st_an);
  if (st_read>st_conf[1]) {
    st.write( map( st_read, st_conf[1], st_conf[2], st_conf[4], st_conf[5]) );
  } else {
    st.write( map( st_read, st_conf[0], st_conf[1], st_conf[3], st_conf[4]) );     
  }
  dr.write( map(analogRead(dr_an), dr_conf[0], dr_conf[1], 0, 180) );
}

void configuration(void) {
  switch (conf) {
    case 1: dr_conf[0]=analogRead(dr_an); conf=2; break; //drive signal reverse
    case 2: dr_conf[1]=analogRead(dr_an); conf=3; break; //drive signal forward
    case 3: st_conf[1]=analogRead(st_an); conf=4; break; //steer signal center
    case 4: st_conf[0]=analogRead(st_an); conf=5; break; //steer signal left
    case 5: st_conf[2]=analogRead(st_an); conf=6; break; //steer signal right
    case 6: st_conf[4]=st.read(); conf=7; break; //steer angle center
    case 7: st_conf[3]=st.read(); conf=8; break; //steer angle left
    case 8: st_conf[5]=st.read(); conf=9; break; //steer angle right
    case 9:
      if (abs(dr_conf[1]-analogRead(dr_an))<10) {
        EEPROM.put(0,dr_conf);
        EEPROM.put(sizeof(dr_conf),st_conf);
      }
      conf=0; k_lim=199;
      break;
  }
}

char sgn(int val) {
 if (val < 0) return -1;
 if (val==0) return 0;
 return 1;
}

void serialsend(void) {
  Serial.print("btn: ");
  Serial.print(digitalRead(set_btn));
  Serial.print(" conf: ");
  Serial.print(conf);
  Serial.print(" k: ");
  Serial.print(k);
  Serial.print(" ||| dr (");
  Serial.print(dr.read());
  Serial.print(") [");
  Serial.print(dr_conf[0]);
  Serial.print(", ");
  Serial.print(dr_conf[1]);
  Serial.print("]");
  Serial.print(" st (");
  Serial.print(st.read());
  Serial.print(") [");
  Serial.print(st_conf[0]);
  Serial.print(", ");
  Serial.print(st_conf[1]);
  Serial.print(", ");
  Serial.print(st_conf[2]);
  Serial.print(", ");
  Serial.print(st_conf[3]);
  Serial.print(", ");
  Serial.print(st_conf[4]);
  Serial.print(", ");
  Serial.print(st_conf[5]);
  Serial.print("]");
  Serial.println();
}
```

# SESIÓN 3

- Comunicar dos Arduinos entre sí con dos módulos RF 300-450MHz.
- Conectar un potenciómetro a un Arduino, y transmitir el valor leído al otro.
- Analizar las modificaciones necesarias para transmitir dos señales (tracción y dirección) de un Arduino a otro.
- Montar el Arduino receptor en el coche y utilizar el otro para transmitir las órdenes. Comprobar el alcance.
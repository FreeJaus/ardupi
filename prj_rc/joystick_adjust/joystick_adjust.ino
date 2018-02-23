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
  k_lim=20;
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
  else { if (btn) {conf=1; k_lim=10;} else { update_servos(); } }
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
      conf=0; k_lim=20;
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

#include <PID_tanque.h>
#include <TimerOne.h>
#include <avr/power.h>
#include <avr/sleep.h>

#define S_SIN 0
#define S_TRI 1
#define S_SQR 2

byte MODE;
bool Sdir = 0, show = 0, SL=0;
double Fmin, Fmax, Fmid;
double Sact, Sam, Smax;
double ST, FD, OUT;
int Omax, Omin;
PID myPID(&FD, &OUT, &ST,2,0.005,.75, DIRECT, &Omin, &Omax);

void setup()
{
  Serial.begin(38400);
  TCCR2B = TCCR2B & B11111000 | B00000001;

  MODE = S_SIN;
  Omin = -120;
  Omax = 120;
  Fmin = 50;
  Fmax = 540;
  Smax = Fmax-Fmin;
  Fmid = (Fmax+Fmin)/2;
  Sact = Fmid;
  Sam = 8;

  Timer1.initialize(10000);
}

void loop() {
if (show==true) {
 Serial.print(ST);
 Serial.print(" ");
 Serial.print(FD);
 Serial.print(" ");
 Serial.println((OUT/2)+127);
 show=false;
}
sleepNow();
char inBuf[12];
String cmd = "",data = "";

while (Serial.available() > 0) {
 int ch = Serial.read();
 delay(1);
 if (ch == -1) { }
 else {
  if (ch == '\n') {
   cmd.toLowerCase();
   data.toCharArray(inBuf, data.length() + 1 );
   Serial.print("cmd> ");
   Serial.print(cmd);
   Serial.print(" ");
   Serial.println(atof(inBuf));
   switch (cmd[0]) {
     case 'r':
      while(abs(ST-FD)>50) {update_Setpoint();}
      FD = analogRead(0);
      myPID.Run(ON);
      Timer1.attachInterrupt( timer1Isr );
      break;
     case 's':
      myPID.Run(OFF);
      Timer1.detachInterrupt();
      analogWrite(3,127);
      delay(1);
      analogWrite(3,127);
      break;
     case 'm':
      MODE=atoi(inBuf);
      break;
     case 'p':
      myPID.Run(OFF);
      myPID.SetTunings(atof(inBuf),myPID.GetKi(),myPID.GetKd(),DIRECT);
      myPID.Run(ON);
      break;
     case 'i':
      myPID.Run(OFF);
      myPID.SetTunings(myPID.GetKp(),atof(inBuf),myPID.GetKd(),DIRECT);
      myPID.Run(ON);
      break;
     case 'd':
      myPID.Run(OFF);
      myPID.SetTunings(myPID.GetKp(),myPID.GetKi(),atof(inBuf),DIRECT);
      myPID.Run(ON);
      break;
   }
   cmd="";
   data ="";
  }
  else {
   if (isDigit(ch) || ch=='.') {data += (char) ch;}
   else { if (isAlpha(ch)) {cmd += (char) ch;} }
  }
 }
}
}

void sleepNow() {
 set_sleep_mode(SLEEP_MODE_IDLE);
 sleep_enable();
 power_adc_disable();
 power_spi_disable();
 power_twi_disable();
 sleep_mode(); // Put the device to sleep:
 sleep_disable(); // Upon waking up, sketch continues from this point.
 power_all_enable();
}

void timer1Isr() {
 SL=!SL;
 if (Sdir==1 || SL==0) {update_Setpoint();}
 FD = analogRead(1);
 myPID.Compute();
 analogWrite(3,(OUT/2)+127);
 show=true;
}

void update_Setpoint() {
  switch (MODE) {
  case S_SIN:
   double S2act;
   if (Sdir==0) {S2act=(Sact-Fmin)/Smax;}
   else {S2act=1+(Sact-Fmin)/Smax;}
   ST = Fmid+Smax*sin(PI*S2act)/2; break;
  case S_TRI: ST = Sact; break;
  case S_SQR: if (Sdir==0) { ST = Fmax; }
              else { ST = Fmin; } break; 
  }

  if (Sdir==0) { Sact = Sact + 40; } else { Sact = Sact - 3; }
  if ((Sact<Fmin+Sam && Sdir==1) || (Sact>=Fmax-40 && Sdir==0)) { Sdir=!Sdir; }
}


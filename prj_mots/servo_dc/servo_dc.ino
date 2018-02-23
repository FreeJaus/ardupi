#include <Servo.h>

int motor_p = 3;
int motor_n = 6;
int steer = 5;

Servo myservo;
int pos = 0;
bool dir = 0;

void setup() {
  pinMode(motor_p,OUTPUT);
  pinMode(motor_n,OUTPUT);
  myservo.attach(steer);
}

void loop() {
  //analogWrite(motor_p, map(analogRead(A0), 0, 1023, 0, 255) );

  for (pos = 0; pos <= 180; pos+=1 ) {
    myservo.write( dir ? 180-pos : pos );
    delay(15); // waits 15ms for the servo to reach the position
  }
  ~dir;
}

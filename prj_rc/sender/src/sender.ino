#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10
 
byte addr[5] ={'c','a','n','a','l'};
RF24 radio(CE_PIN, CSN_PIN);
float data[3];

void setup() {
  radio.begin();
  radio.openWritingPipe(addr);

  Serial.begin(9600);
}
 
void loop() { 
 data[0]=analogRead(0)* (5.0 / 1023.0);;
 data[1]=millis();
 data[2]=3.14;
 Serial.println(sizeof(data));
 bool ok = radio.write(&data, sizeof(data));
 Serial.println(ok);
 if( radio.write(data, sizeof(data)) ) {
   Serial.print(data[0]); 
   Serial.print(" , "); 
   Serial.print(data[1]); 
   Serial.print(" , "); 
   Serial.println(data[2]); 
  } else {
   Serial.println("Not sent");
  }
  delay(1000);
}


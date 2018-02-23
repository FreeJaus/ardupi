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
  radio.openReadingPipe(1, addr);
  radio.startListening();

  Serial.begin(9600); 
}
 
void loop() {
 //uint8_t numero_canal;
 //if ( radio.available(&numero_canal) )
 if ( radio.available() ) {
   radio.read(data,sizeof(data));
     
   Serial.print("Dato0= " );
   Serial.print(data[0]);
   Serial.print(" V, ");
   Serial.print("Dato1= " );
   Serial.print(data[1]);
   Serial.print(" ms, ");
   Serial.print("Dato2= " );
   Serial.println(data[2]);
 } else {
   Serial.println("No data available");
 }
 delay(1000);
}


#include <SPI.h>
 
// LED pin for Arduino:
#define LED_DDR  DDRB
#define LED_PORT PORTB
#define LED_PIN  _BV(PORTB5)
 
static const uint8_t magic[] = {'A','d','a'};
#define MAGICSIZE  sizeof(magic)
#define HEADERSIZE (MAGICSIZE + 3)
 
#define MODE_HEADER 0
#define MODE_HOLD   1
#define MODE_DATA   2
 
static const unsigned long serialTimeout = 15000; // 15 seconds
 
void setup()
{
  uint8_t
    buffer[256],
    indexIn       = 0,
    indexOut      = 0,
    mode          = MODE_HEADER,
    hi, lo, chk, i, spiFlag;
  int16_t
    bytesBuffered = 0,
    hold          = 0,
    c;
  int32_t
    bytesRemaining;
  unsigned long
    startTime,
    lastByteTime,
    lastAckTime,
    t;
 
  LED_DDR  |=  LED_PIN; // Enable output for LED
  LED_PORT &= ~LED_PIN; // LED off
 
  Serial.begin(115200); // Teensy/32u4 disregards baud rate; is OK!
 
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV16); // 1 MHz max, else flicker
 
  uint8_t testcolor[] = { 0, 0, 0, 255, 0, 0 };
  for(char n=3; n>=0; n--) {
    for(c=0; c<25000; c++) {
      for(i=0; i<3; i++) {
        for(SPDR = testcolor[n + i]; !(SPSR & _BV(SPIF)); );
      }
    }
    delay(1); // One millisecond pause = latch
  }
 
  Serial.print("Ada\n"); // Send ACK string to host
 
  startTime    = micros();
  lastByteTime = lastAckTime = millis();
 
  // loop() is avoided as even that small bit of function overhead
  // has a measurable impact on this code's overall throughput.
 
  for(;;) {
 
    // Implementation is a simple finite-state machine.
    // Regardless of mode, check for serial input each time:
    t = millis();
    if((bytesBuffered < 256) && ((c = Serial.read()) >= 0)) {
      buffer[indexIn++] = c;
      bytesBuffered++;
      lastByteTime = lastAckTime = t; // Reset timeout counters
    } else {
      // No data received.  If this persists, send an ACK packet
      // to host once every second to alert it to our presence.
      if((t - lastAckTime) > 1000) {
        Serial.print("Ada\n"); // Send ACK string to host
        lastAckTime = t; // Reset counter
      }
      // If no data received for an extended time, turn off all LEDs.
      if((t - lastByteTime) > serialTimeout) {
        for(c=0; c<32767; c++) {
          for(SPDR=0; !(SPSR & _BV(SPIF)); );
        }
        delay(1); // One millisecond pause = latch
        lastByteTime = t; // Reset counter
      }
    }
 
    switch(mode) {
 
     case MODE_HEADER:
 
      // In header-seeking mode.  Is there enough data to check?
      if(bytesBuffered >= HEADERSIZE) {
        // Indeed.  Check for a 'magic word' match.
        for(i=0; (i<MAGICSIZE) && (buffer[indexOut++] == magic[i++]););
        if(i == MAGICSIZE) {
          // Magic word matches.  Now how about the checksum?
          hi  = buffer[indexOut++];
          lo  = buffer[indexOut++];
          chk = buffer[indexOut++];
          if(chk == (hi ^ lo ^ 0x55)) {
            // Checksum looks valid.  Get 16-bit LED count, add 1
            // (# LEDs is always > 0) and multiply by 3 for R,G,B.
            bytesRemaining = 3L * (256L * (long)hi + (long)lo + 1L);
            bytesBuffered -= 3;
            spiFlag        = 0;         // No data out yet
            mode           = MODE_HOLD; // Proceed to latch wait mode
          } else {
            // Checksum didn't match; search resumes after magic word.
            indexOut  -= 3; // Rewind
          }
        } // else no header match.  Resume at first mismatched byte.
        bytesBuffered -= i;
      }
      break;
 
     case MODE_HOLD:
 
      // Ostensibly "waiting for the latch from the prior frame
      // to complete" mode, but may also revert to this mode when
      // underrun prevention necessitates a delay.
 
      if((micros() - startTime) < hold) break; // Still holding; keep buffering
 
      // Latch/delay complete.  Advance to data-issuing mode...
      LED_PORT &= ~LED_PIN;  // LED off
      mode      = MODE_DATA; // ...and fall through (no break):
 
     case MODE_DATA:
 
      while(spiFlag && !(SPSR & _BV(SPIF))); // Wait for prior byte
      if(bytesRemaining > 0) {
        if(bytesBuffered > 0) {
          SPDR = buffer[indexOut++];   // Issue next byte
          bytesBuffered--;
          bytesRemaining--;
          spiFlag = 1;
        }
        // If serial buffer is threatening to underrun, start
        // introducing progressively longer pauses to allow more
        // data to arrive (up to a point).
        if((bytesBuffered < 32) && (bytesRemaining > bytesBuffered)) {
          startTime = micros();
          hold      = 100 + (32 - bytesBuffered) * 10;
          mode      = MODE_HOLD;
    }
      } else {
        // End of data -- issue latch:
        startTime  = micros();
        hold       = 1000;        // Latch duration = 1000 uS
        LED_PORT  |= LED_PIN;     // LED on
        mode       = MODE_HEADER; // Begin next header search
      }
    } // end switch
  } // end for(;;)
}
 
void loop()
{
  // Not used.  See note in setup() function.
}

---
title: "Radio Control (RC)"
---

- [ATtiny816](http://www.microchip.com/wwwproducts/en/ATTINY816) ([datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/40001913A.pdf)): 8KB Flash, 512B SRAM and 128 bytes of EEPROM
- [ATtiny1616](http://www.microchip.com/wwwproducts/en/ATTINY1616) ([datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/40001893B.pdf)): 16 KB Flash, 2 KB SRAM and 128 bytes of EEPROM

# Pin count

- USB: 2 (power) + 2 (D+ and D-)
- NRF24L01: 2 (power) + 5 (4 SPI + CE) [ + IRQ ]
- Joystick: 2 (power) + 2 (analog) + 1
- Servo: 2 (power) + 1 (PWM)
- Encoder: 2 (power) + 2 (A and B)
- btn/switch matrix:
  - 4>x>0: x
  - x>4: ceil(sqrt(x)*2)

## Nunchuk

14/SOIC150mil (ATTINY814 or ATTINY1614)

- NRF24L01 + Joystick + 3x btn: 5-6 + 3 + 3 = 11-12
- ++ 2x btn + encoder: + 2 + 2 = 15-16
- ++ USB: + 2 = 17-18

## RC receiver & ESC commander, and PC receiver

20/SOIC300mil or 20/VQFN3x3 (ATTINY816 or ATTINY1616)

- NRF24L01 + 2x servo: 5-6 + 2 = 7-8
- NRF24L01 + USB: 5-6 + 2 = 7-8

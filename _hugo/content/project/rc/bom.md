---
title: "Radio Control (RC)"
---

- [ATtiny816](http://www.microchip.com/wwwproducts/en/ATTINY816) ([datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/40001913A.pdf)): 8KB Flash, 512B SRAM and 128 bytes of EEPROM
- [ATtiny1616](http://www.microchip.com/wwwproducts/en/ATTINY1616) ([datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/40001893B.pdf)): 16 KB Flash, 2 KB SRAM and 128 bytes of EEPROM

- 20-pin
  - VQFN 3x3
  - SOIC300

- NRF24L01: 2 (power) + 5 (4 SPI + CE) [ + IRQ ]
- Joystick: 2 (power) + 2 (analog) + 1
- btn/switch matrix:
  - 4>x>0: x
  - x>4: ceil(sqrt(x)*2)

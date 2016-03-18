---
categories: [ nb-rc ]

title: Tareas realizadas
keywords:

publishdate: 2016-01-01
date: 2015-11-20
---

- Se han adquirido las piezas necesarias para construir un coche en una tienda especializada en vehículos RC. Se ha escogido un coche por ser el vehículo más fácil de manejar, y debido a las limitaciones para utilizar vehículos voladores en zonas urbanas.
  - Chasis, carrocería y engranajes
  - Motor de corriente continua
  - Servomotor
  - Batería
  - Variador/inversor y BEC. Es válido tanto para motores de corriente continua como para motores brushless (hasta 300A), y provee alimentación (6V y 3A) a través de una fuente conmutada.
  - Cargador de baterías
- Se han adquirido conectores, cables y componentes electrónicos en una tienda de electrónica.
  - Conectores batería-variador
  - Conectores motor-variador
  - Conectores BEC-controlador y servo-controlador
  - Circuito integrado 556 (dos temporizadores 555)
- Tras cortar los cables a medida y soldar todas las conexiones, se ha programado una placa Arduino Leonardo para utilizar un Joystick (dos potenciómetros) para controlar tanto el motor de corriente continua a través del variador (tracción) como el servomotor (dirección).
- Se ha cargado la batería por completo, se ha realizado el montaje de los componentes electrónicos, y se ha configurado el variador para ajustarlo al rango del joystick. A continuación se ha comprobado que los motores responden correctamente a las órdenes del joystick. En el caso de la tracción, cambia de velocidad tanto en un sentido como en otro. La dirección se mueve en el rango esperado.
- Se han desmontado dos coches de los que se disponía previamente para analizar las similitudes y diferencias. El tipo de componentes y su conexión es la misma, pero se observa una diferencia notable en la electrónica, ya que la potencia, el control y el receptor RF están integrados en una sola placa. Asimismo, prácticamente no se utilizan conectores, ya que todas las conexiones están soldadas directamente a la placa. La única conexión es la de la batería, que es de tipo cartucho.
- Se ha reprogramado la placa Arduino para permitir el ajuste de los rangos de las señales a unos dispositivos (potenciómetros, joysticks) dados, y así aprovechar la resolución al máximo. Se utiliza la EEPROM para guardar los datos, aunque se desconecte el dispositivo. Se utiliza el puerto serie para permitir una configuración más precisa por medio de un ordenador, aunque se puede realizar sólo con el pulsador, como en el caso del variador. *NOTA: no se debe conectar la placa al ordenador al mismo tiempo que está conectada al variador, ya que éste último tiene una fuente conmutada y hay riesgo severo de quemarlo*.
- Se han diseñado dos circuitos para su simulación en 123d.circuits.io, uno para conocer los montajes básicos para controlar motores, y otro para comprobar la programación que permite el ajuste a los rangos de unos componentes dados.
  - https://123d.circuits.io/users/452443
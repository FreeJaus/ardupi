---
menu:
  notebook:
    name: "Vehículos RC"
    identifier: "nb-rc"
    pre: "automobile"
    weight: -180

title: Taller de vehículos de radio control
---

# [[FreeJaus](https://github.com/FreeJaus)] Formación

---

- **Título de la actividad**: Vehículos RC
- **Tipo**: Taller
- **GEAs**: [ArduPi](https://github.com/FreeJaus/ardupi)
- **Dinamización**: u.mc, m.mc, z.gb 
 
---

- **Lugar**: Gazteleku Urduliz
- **Formato**: Taller (120')
- **Sesiones**:
  1. 201Xxxx00: Montaje del chasis y la dirección con las piezas del kit. Desmontaje del vehículo averiado.
  2. 2016Feb28: Montaje de los componentes eléctricos/electrónicos.
   
---

- **Objetivos**:
  - Generales:
     - 
  - Primera sesión:
     - 
  - Segunda sesión:
     - 

---	 

Existen muchos tipos de vehículos de radio control: coches, camiones, helicópteros/cuadricópteros/octacópteros, botes/barcos, aviones, tanques, de construcción (excavadoras, grúas, carretillas, etc.), submarinos... tantos como la imaginación y el tiempo libre de los entusiastas pueden alcanzar. Aunque la mayoría son modelos o juguetes, existen también maquetas que reproducen fielmente cada detalle a escala. Asimismo, existen modelos tan pequeños como una caja de cerillas, y tan grandes como para transportar a una persona. Consecuentemente, las prestaciones, el coste y las utilidades que se les pueden dar son muy diferentes. Pero, independientemente del tipo y tamaño, el diseño de un vehículo de radio control se puede dividir en cuatro bloques:

- Chasis/carrocería/fuselaje: estructura principal del vehículo que condiciona el tipo, el tamaño y la funcionalidad. En su diseño o elección se deben tener en cuenta los materiales y el entorno donde se va a utilizar. Debe tener espacio suficiente y adecuado para alojar el resto de componentes requeridos para el funcionamiento. Se debe estudiar el tipo de movimiento y la potencia necesaria en cada mecanismo accionado por un motor.
- Motores: las máquinas utilizadas para propulsión pueden dividirse *grosso modo* entre las que funcionan con combustibles (gasolina, propano, Jet-A1...) y los modelos eléctricos. En lo que respecta a otros accionamientos (como la dirección en un automóvil o los alerones/elevadores de un avión), todos son eléctricos. En cada caso, deben tenerse en cuenta los requisitos de la carrocería/fuselaje para escoger la solución más adecuada en lo que respecta a potencia/consumo.
- Electrónica: la función principal de la unidad electrónica es transformar las órdenes recibidas del mando, en señales adecuadas para controlar cada uno de los accionamientos. Por ello, un aspecto principal es la transformación de la potencia recibida de una batería o alternador. Los requisitos de computación dependerán del número de accionamientos, de la complejidad de los mismos, y de los sensores que se incluyan en el vehículo.
- Comunicación: la diferencia más significativa con respecto a los modelos reales es que no pueden ser manejados desde el interior (por razones evidentes). Por lo tanto, se requiere de un sistema de comunicación entre el usuario y el vehículo. Éste puede ser una pareja de cables trenzados, aunque limita el movimiento al alcance del mismo. La solución más extendida, y la que da nombre a estos vehículos, es el uso de emisores y receptores de ondas de radio (radiofrecuencia o RF). El número de cánales (señales que pueden transmitirse simultáneamente) dependerá del número de accionamientos y otros controles incluidos. 

De la exposición anterior se puede concluir que estos *jueguetes* para niños y mayores aúnan todos los aspectos tecnológicos y de ingeniería sobre los que se sustenta nuestra sociedad. Por un lado, permiten conocer y aplicar los fundamentos de la mecánica (estructuras, amortiguadores y engranjes), la dinámica de fluídos, los materiales, la electricidad (máquinas y potencia), la electrónica (analógica y digital) y las comunicaciones (por cable y RF). La variedad de motores y sensores que pueden integrarse en un vehículo radio control, permiten adquirir conocimientos para entender la composición de prácticamente cualquier máquina de consumo o de uso industrial (o un modelo simplificado, al menos).  Por otro, dan pie a tratar cuestiones de actualidad por su impacto social, como lo son el (ab)uso de combustibles y las energías renovables, la seguridad en las comunicaciones, o los límites de la *inteligencia artificial*. 

Los vehículos RC son un producto de masas, especialmente con el auge que están teniendo los *drones* estos últimos años. Sin embargo, un aspecto más interesante como elemento didáctico es que existe una amplía tradición de fabricación casera (*Do It Yourself -DIY-*), que en los más entusiastas supone la fabricación prácticamente íntegra de las piezas que componen los modelos. Como resultado, existe un mercado muy amplio de piezas, respuestos y accesorios. Tanto es así, que algunos productos son resultado de desarrollos realizados por la comunidad. Asimismo, en la red hay muchísima información sobre cada aspecto, sea mecánico, electrónico o de comunicaciones; desde qué baterías escoger hasta cómo cablear la bobina de un motor para modificar su comportamiento. Más relevante aún es que, algunos productos comerciales que están teniendo su auge estos últimos años basan su funcionamiento en componentes comercializados inicialmente para vehículos RC. Este es el caso, por ejemplo, de las bicicletas o los monopatines motorizados. En el extremo, el mismo diseño de motores es el utilizado en los coches eléctricos.

# Orientación del taller

Debido a que el taller está enfocado a un público de entre 12 y 18 años, y se realizará en tiempo de ocio, las valoraciones anteriores toman mayor relevancia. El elemento conductor del taller es un juguete que se puede adquirir ya montado, y que se puede utilizar en lugares cerrados, pero está pensado para espacios abiertos. A partir del mismo, en función del interés de los asistentes, se puede profundizar paulatinamente en algunos o cualquiera de los bloques indicados. Por lo tanto, la complejidad de los contenidos dependerá de hasta dónde quiera avanzar cada asistente. No es necesario abordarlos todos al mismo tiempo, ni de forma lineal, lo que permite que la curiosidad sea la guía. También posibilita que varias personas colaboren en un mismo vehículo, ya sea en la misma tarea o centradas en aspectos diferentes. Es especialmente indicado para personas con interés en cursar estudios técnicos, pues permite identificar con cierta claridad el reflejo de las especialidades clásicas. Sin embargo, debido a la posibilidad de conectarlo a dispositivos móviles o incluso cámaras, sus utilidades creativas pueden atraer la atención de otros perfiles. En cualquier caso, su uso como juguete puede ser atractivo para cualquiera.

El auge del movimiento maker, ejemplificado en Arduino, ha dado un vuelco a la red hacia el contenido open source, y hacia el software y hardware libres. Esto ha tenido como resultado la disponibilidad de una amplísima variedad de productos de bajo coste y/o tecnológicamente novedosos. Los *drones*, las impresoras 3D, los micro-ordenadores... son algunos de éstos. Todos ellos se caracterizan por disponer de documentación y fuentes completas y detalladas de forma abierta en la red. Sin embargo, un efecto paralelo es la saturación de información, y la disposición de múltiples fuentes muy parecidas pero no iguales. Este aspecto, junto con el objetivo de abrir los contenidos a la voluntad de los asistentes, es el reto más exigente para la organización del taller. Para afrontarlo, la dinámica que se plantea es exponer a los asistentes a una sesión un listado de contenidos con varias referencias, e invitarles a plantear a los organizadores cuáles son los aspectos de su interés. Puesto que existen simuladores online y gratuitos que permiten diseñar y verificar los sistemas, entre una sesión y otra los asistentes pueden avanzar a partir de las referencias facilitadas -e, idealmente, complementarlas-. Para la sesión siguiente los organizadores implementarán y documentarán las soluciones requeridas, de forma que se pueda realizar alguna actividad práctica, independientemente del tiempo que los asistentes hayan podido dedicar.
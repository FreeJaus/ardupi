---
categories: [ nb-tfg ]
view: prop

linktitle: "Mini DeskBot"
title: "Mini DeskBot"
keywords: 

publishdate: 2016-01-01
date: 2016-01-01

por:
 - name: "1138-4EB"
   email: "-"
   tel: "-"
   group: "Alumnado [Electrónica]"
 - name: "sebotas007"
   email:
   tel:
   group: "PDI [ISA]"
   
fechas:
 det: true
 init: "2016/03"
 end: "2016/05"
 
areas: [ "Electrónica analógica" , "Electrónica digital" , "Programación microcontroladores" , "Arduino" , "Control de motores paso a paso" , "Regulación automática" , "Diseño electrónico" , "Diseño CAD" , "Diseño CAM" , "Programación en C" , "Programación en GCODE" , Inscape , Fritzing , CNC]

---

# Descripción

De un lector/grabador de CD/DVD se puede obtener lo siguiente ([Dissection of a DVD writer](http://www.die4laser.com/dvd-rec/DissectionofaDVDwriter.htm)):

- Motor de corriente continua (para extraer e introducir la bandeja)
- Motor brushless (para girar el disco)
- Motor paso a paso (para mover el cabezal óptico)
- Dos ejes que soportan el cabezal óptico, y un husillo unido al motor paso a paso.
- Uno o varios diodos láser (IR o rojos)
- Conectores y circuitos integrados (drivers)

Con dos juegos de ejes, husillos, y motores paso a paso, se puede construir una pequeña máquina CNC de dos grados de libertad. La superficie de trabajo de aproximadamente 40x40mm permite gravar la superficie de varios materiales mediante uno o varios diodos láser. Con la potencia suficiente, podrían cortarse piezas no muy gruesas.

Para construir la máquina los pasos a realizar son los siguientes:

- Desmontar dos unidades ópticas de 5 1/4'', de las que al menos una debe ser grabadora. Conservar:
  - La caja externa metálica (base y tapa) de una de las unidades.
  - La pieza de metal que sostiene los dos ejes, el motor paso a paso, el husillo y el carro.
  - El motor de continua, el brushless y los respectivos drivers se pueden guardar para otros proyectos, aunque no son necesarios en este.
  - Diodo láser:
    - Se puede desmontar por completo uno de los carros y conservar prácticamente intacto el grabador. Más adelante se indica cómo modificarlo.
	- Se pueden desmontar ambos carros por completo y guardar por separado los diodos láser y las lentes.
- Con la ayuda de una herramienta rotatoria y discos de corte, eliminar los salientes del o los carros (una vez retiradas todas las piezas electrónicas y las lentes). El objetivo es reducir la altura mismos, para aprovechar mejor el eje Z.
- Con la herramienta rotatoria, cortar la protuberancia en la base de la caja metálica.
- Medir las dimensiones de los dos juegos y calcular la disposición óptima para aprovechar la superificie de trabajo.
- Diseñar un cabezal para soportar un rotulador.
- Diseñar las patas y cualquiera otra pieza auxiliar que se utilice en el montaje. Si fuera necesario, imprimirlas en 3D.
- Marcar sobre la caja externa:
  - Los ocho orificios para sujetar las dos piezas.
  - Los cuatro orificios para sujetar las patas.
  - Si fuera necesario, marcar una ventana en la parte superior, y otra por cada motor que se coloque contra la base.
- Cortar las ventanas y taladrar los orificios.
- Atornillar los separadores y montar las piezas y patas.
- Diseñar el circuito de potencia (dos motores y láser) y montarlo en una protoboard.
- Comprobar el funcionamiento con un Arduino como controlador y un rotulador como cabezal.
- Diseñar y fabricar el PCB de potencia con componentes SMD. Considerar la introducción de un attiny/atmega48 en la placa (separando masas de potencia y señal), o diseñar un soporte para utilizar una placa ya montaja (Nano, Pro Micro...).
- Verificar que el funcionamiento sigue siendo correcto.
- Diseñar un cabezal para soportar un diodo láser:
  - Adquirir el soporte con lente incluida y reutilizar uno de los diodos rojos extraidos de las unidades ópticas.
  - Utilizar el carro prácticamente intacto, y diseñar un separador para ajustar el enfoque.
  - Diseñar y fabricar un soporte con las lentes extraidas de las unidades ópticas.
     - [Instructables - Home Made Collimator](http://www.instructables.com/id/Home-Made-Collimator/?ALLSTEPS)

---

# Justificación

- Ejemplo mínimo para la introducción en el mundo del CNC.
- Bajísimo coste
- Componentes fácilmente accesibles
- Se puede alimentar con un cargador de móvil
- Desde una estructura reutilizando la caja externa de metal, hasta un diseño hecho a medida con una impresora 3D o en madera.
- Hay multiples diseños disponibles en la red con variaciones interesantes:
  - [funofdiy.blogspot.com - A Raspberry Pi controlled mini CNC Laser engraver]( http://funofdiy.blogspot.com.es/2013/10/a-raspberry-pi-controlled-mini-laser.html)
  - [hackaday.com - Fail of the week: Laser cutter that makes jagged edges]( https://hackaday.com/2013/09/12/fail-of-the-week-laser-cutter-that-makes-jagged-edges/)
  - [instructables.com - MicroSlice: a tiny Arduino laser cutter]( http://www.instructables.com/id/MicroSlice-A-tiny-Arduino-laser-cutter/)

# Otros datos de interés:

- Puede realizar de forma individual o grupal, ya que permite trabajar las siguientes áreas:
  - Mecánica/Informática:
     - Diseño CAD/CAM parametrizado y animado (OpenSCAD + FreeCAD + Python)
  - Electrónica/Informática:
     - Diseño y fabricación de PCBs.
     - Regulación automática y control.
     - Programación de microcontroladores.
     - Control de motores paso a paso.
  - Impresión 3D.
- Se utilizará como base para tomar decisiones en el diseño de DeskBot.

---

- http://forums.modretro.com/viewtopic.php?f=3&t=10121
- ¿Para qué sirve el estabilizador magnético?
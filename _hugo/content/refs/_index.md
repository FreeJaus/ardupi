---
title: "Entorno de trabajo"
keywords: arduino atmel avr git vcs repositorio wiki arm linux markdown hugo
---

En este apartado se reúnen referencias relacionadas con las herramientas utilizadas de forma transversal en prácticamente todos los proyectos. Se agrupan en función del tipo de tarea para la que se utilizan:

# Desarrollo y diseño

## Esquemas, diagramas, PCBs y simulaciones

- [Fritzing](http://fritzing.org) para diseñar montajes, esquemas e incluso PCBs.

123circuits

## Microprocesadores

¿En que se diferencian un microprocesador y un microcontrolador (ambos de 32 bits)?

- ARM ([mbed.com](https://www.mbed.com/en/development/hardware/))
  - Raspberry Pi
  - Banana Pi
  - Orange Pi
  - Galileo
  - BragleBone
  - OLinuXino
  - pcDuino
- Intel
  - Galileo
  - Arduino 101

- Gizmo
- ODROID
- Fox SBC
- Zynq: MicroZed, ZYBO
- Parallela

Residualmente se puede ejecutar Windows IoT

http://www.eetimes.com/document.asp?doc_id=1328008

## Microcontroladores

Como puede intuirse por el nombre, en *FreeJaus - ArduPi* se utilizan principalmente las placas del ecosistema [Arduino](https://www.arduino.cc) (basadas en productos de [Atmel](https://www.atmel.com)) como plataforma para los diseños basados en microcontrolador, o uC. También se dispone de placas de desarollo basadas en uC de [Microchip](https://www.microchip.com), conocidos como *PICs*. En lo que respecta a las especificaciones técnicas de los dispositivos, tanto Atmel como Microchip, y otros como [STMicroelectronics](https://www.google.es/url?sa=t&rct=j&q=&esrc=s&source=web&cd=1&cad=rja&uact=8&ved=0ahUKEwjVx7_P1JjLAhXL7RQKHYX7DnsQFggoMAA&url=http%3A%2F%2Fwww.st.com%2F&usg=AFQjCNHCiJI1kEQQ_kNXNIxUqhoDnZJPpw&bvm=bv.115339255,d.bGs) o [NXP](www.nxp.com), comercializan productos en familias desde 8bits hasta 32bits con una muy amplia variedad de periféricos y características auxiliares. Por lo tanto, no existe una familia de productos que sea *mejor* a priori; todo depende de los requerimientos de la aplicación que se quiera desarrollar. Cualquiera servirá para prácticamente todos los proyectos de iniciación, ya que rara vez se llegan a aprovechar todos los recursos disponibles. Cuando necesitemos adquirir un componente más potente, ya sabremos lo suficiente sobre su funcionamiento para informarnos y decidirnos por un fabricante y un producto concretos.

Tradicionalmente los PIC han sido muy utilizados, a nivel profesional, y también entre aficionados y entusiatas, debido a su muy bajo coste y a granularidad en las familias de productos. Sin embargo, desde el lanzamiento de Arduino, el escenario ha dado un [vuelco](https://www.google.com/trends/explore#q=arduino%2C%20microchip&cmpt=q&tz=Etc%2FGMT-1). La explicación, tan sencilla como compleja, es que Arduino surgió desde un principio como un proyecto [Open Source](https://opensource.org/) y, especialmente, [Libre](http://www.gnu.org/philosophy/free-sw.es.html). Además, se inspiró en [Wiring](http://wiring.org.co/) para diseñar el entorno de desarrollo y ofrecer un lenguaje C simplificado (en el que se preconfiguran y ocultan los regisros de configuración del uC al usuario), facilitando que usuarios sin conocimientos de electrónica ni informática pudieran realizar montajes básicos. Cuando se presentó, Microchip, entre otros, ya disponía de una ingente cantidad de librerías y referencias en la red. Sin embargo, el enfoque era empresarial, de contacto con sus partners (empresas), y de protección de su propiedad intelectual (aunque gran cantidad de documentación y fuentes se ofrecieran de forma gratuita a través de su página). Por ello, la comunidad, ahora llamada maker, se encontró más cómoda en un entorno abierto.  Un gran esfuerzo de difusión y generación de contenido (librerías, tutoriales, vídeos...) hicieron el resto.

El resultado inicial fue la reinvención de la rueda, ya que la red se llenó de adaptaciones, reivindicadas como open source, de muchos diseños que hasta entonces se habían liberado con PICs como base. Si bien la *liberación* en páginas de aficionados (especialmente radioaficionados y entusiastas de los vehículos de radio control) era Libre, valga la redundancia, no era común que se especificara una licencia del tipo [Creative Commons](http://creativecommons.org/). En paralelo, la liberación de controladores para impresoras 3D y máquinas CNC basadas en Arduino, hizo de la marca una abanderada del movimiento maker. Comunidad que la ha utilizado en sistemas domóticos, de realidad aumentada, wearables...

*NOTA: desde 2015, los fundadores utilizan la marca [Genuino](https://www.arduino.cc/en/Main/GenuinoBrand) fuera de los EEUU. Ver [Marcas, diseños, piratería y open source](/notebook/refs/pir) para más información.*

Por lo anterior, como estudiantes de ingenierías industriales e informática, nuestro interés por los sistemas basados en microcontroladores se extiende a todos los fabricantes y modelos, desde los flujos de trabajo más rápidos y automatizados, hasta los complejos y detallados.
Tomamos Arduino como referencia porque la curva de aprendizaje inicial es muy tendida, pero entendemos que debemos mirar más allá y más atrás del *hype*. Bebemos de fuentes libres y publicamos abiertamente el contenido generado, y también nos identificamos con la cultura hacker, y tratamos de entender qué hacen los sistemas y cómo lo hacen.

Desde este punto de vista, aunque se utilizan nombres propios para referirse a diseños de placa concretos en el ecosistema Arduino, la mayoría son prácticamente el mismo circuito con variaciones en lo que respecta a la forma, el tipo de conectores utilizados, o el empaquetado del microcontrolador. Los componentes comunes son:

- Microcontrolador principal
- Oscilador de cristal
- Regulador de tensión
- Conversor USB-UART(TTL)
- Pulsador de reset
- LEDs indicadores
- Condensadores (para el cristal, el regulador y la entrada de alimentación del uC)
- Resistencias (para los LEDs o pullup/pulldown)

Por concretar, los modelos [Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno), [Pro](https://www.arduino.cc/en/Main/ArduinoBoardPro), [Pro Mini](https://www.arduino.cc/en/Main/ArduinoBoardProMini), [Mini](https://www.arduino.cc/en/Main/ArduinoBoardMini) y [Nano](https://www.arduino.cc/en/Main/ArduinoBoardNano) tienen un [ATmega168](http://www.atmel.com/dyn/resources/prod_documents/doc2545.pdf) o [ATmega328](http://www.atmel.com/dyn/resources/prod_documents/doc8025.pdf) como uC principal. Son dos variantes del mismo uC de 8 bits, con diferencias en el tamaño de la memoria. El modelo [Mega](https://www.arduino.cc/en/Main/ArduinoBoardMega2560) está basado en un [ATmega2560](http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf), que es esencialmente la misma arquitectura, pero tiene un número significativamente mayor de recursos (contadores, entradas/salidas, etc.). Todos ellos, además del uC principal, incluyen un oscilador de 8MHz o 16MHz, y reguladores de tensión de 3,3v o 5v, dependiendo del fabricante. Algunos incluyen conversor USB-UART, pero no es necesario, tal como se expone en [Arduino-USB: comunicación serie (RS232, USB, TTL)...](https://github.com/FreeJaus/ardupi/wiki/Arduino-USB:-comunicaci%C3%B3n-serie-%28RS232,-USB,-TTL%29-y-programaci%C3%B3n-%28sketch,-bootloader,-ISP...%29). En lo que respecta a los LEDs, suelen incluir dos para mostrar la trasferencia y recepción de datos a través la UART, y un tercero para uso general. La lectura pausada de las descripciones de cada modelo, y la [comparación](https://www.arduino.cc/en/Products/Compare) de las mismas, nos permite identificar cada uno de los componentes en las placas (en los modelos más compactos, hay que mirar las dos caras).

Es especialmente didáctico el siguiente vídeo, donde se muestra el montaje y programación de un Pro Mini con componentes discretos (uC, oscilador, dos condensadores y un LED): [1-Day Project: Build Your Own Arduino Uno for $5](https://www.youtube.com/watch?v=sNIMCdVOHOM). El proyecto [Acher](https://github.com/FreeJaus/ardupi/tree/master/Acher) va un paso más allá y utiliza un ATmega48 para controlar una matriz de LEDs a través del puerto serie (RS232) del ordenador. En lugar de un conversor USB-UART(TTL), se utiliza un [MAX232](https://www.maximintegrated.com/en/products/interface/transceivers/MAX232.html). En lo que respecta al uC, se trata de una versión [compatible](http://www.atmel.com/Images/doc2554.pdf) pero con menos memoria que el ATmega168/368. Sin embargo, el interés del proyecto reside en que no se utiliza Arduino, sino que se programa directamente en C. Por ello, es una referencia interesante para entender cuál es el valor añadido de Arduino/Genuino/Wiring desde el punto de vista de la usabilidad y simplicidad del entorno de desarrollo.

A finales de 2014, el fabricante de uno de los conversores USB-UART(TTL) más utilizados, FTDI, publicó una actualización del driver en Windows que borró el identificador de cualquier chip no oficial, dejando [aparentemente](/notebook/refs/pir) inservibles las placas de usuarios de todo el mundo. Como resultado, además del [revuelo](https://www.youtube.com/watch?v=eU66as4Bbds) que supuso en la industria, los diseñadores de placas optaron por otras [alternativas](http://www.eevblog.com/forum/reviews/alternatives-to-ftdi-usb-to-uart-converter/). Algunos optaron por modelos con la misma funcionalidad ([PL2303](http://www.prolific.com.tw/UserFiles/files/ds_pl2303HXD_v1_4_4.pdf), [CP210x](http://www.silabs.com/products/interface/usbtouart/Pages/usb-to-uart-bridge.aspx), [CH340](http://www.abclinuxu.cz/data/prilohy/8/0/208508-ch340ds2_e-9177667200158999136.PDF)...), que es lo más habitual en placas no oficiales adquiridas a través de páginas como las del grupo Alibaba. En estos casos, es habitual que al conectar las placas a un PC con Windows, éste no reconozca el driver automáticamente, como sí sucede con las oficiales. Para solucionarlo sólo hay que buscar y descargar el driver adecuado.

En el caso de las placas Arduino oficiales, optaron por renovar los diseños incluyendo un segundo uC en sustitución del chip de FTDI. Utilizaron ATmega8u2 o ATmega16u4, que tienen soporte para USB, y los programaron para que actuaran como conversores USB-UART. Este es el caso de la [Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno), y la Mega (además del cambio del ATmega1280 [original](https://www.arduino.cc/en/Main/ArduinoBoardMega) por el ATmega2560). Sin embargo, en el caso de la Uno, por ejemplo, se daba la paradoja de que el uC utilizado como conversor era tan potente o más que el uC principal. Por ello, surgieron modelos que utilizan sólo un ATmega16u4 o ATmega32u4, como uC y para la conexión USB, disminuyendo así el coste y simplificando el diseño de la placa. Por ejemplo, [Leonardo](https://www.arduino.cc/en/Main/ArduinoBoardLeonardo) es el equivalente a Uno, [Esplora](https://www.arduino.cc/en/Main/ArduinoBoardEsplora) es Leonardo con otra forma, [Micro](https://www.arduino.cc/en/Main/ArduinoBoardMicro) es el equivalente a Nano, y [LilyPad](https://www.arduino.cc/en/Main/ArduinoBoardLilyPadUSB) es un diseño pensado para utilizar en prendas de ropa.

Además de los modelos más conocidos de la familia, ya presentados, hay diseños aún más pequeños basados en la serie [ATtiny](http://www.atmel.com/images/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf), donde podemos encontrar modelos en encapsulados con ocho patillas (en [tinyAVR](http://www.atmel.com/products/microcontrollers/avr/tinyavr.aspx) los hay con menos aún). Por ejemplo, Arduino [Gemma](https://www.arduino.cc/en/Main/ArduinoGemma) utiliza un ATtiny85, el mayor de entre los más pequeños. En el siguiente vídeo se ve un montaje en una protoboard parecido al enlazado anteriormente, pero prescindiendo del oscilador de cristal, ya que se utiliza el interno del ATtiny: [How-To: Shrinkify Your Arduino Projects ](https://www.youtube.com/watch?v=30rPt802n1k). En el otro extremo, tras la estela del éxito de las arquitecturas ARM en dispositivos móviles, los modelos [Zero](https://www.arduino.cc/en/Main/ArduinoBoardZero) y [Due](https://www.arduino.cc/en/Main/ArduinoBoardDue) son los equivalentes a Uno/Mega, pero con uC de 32bits y relojes de 48MHz/84MHz, respectivamente. El [101](https://www.arduino.cc/en/Main/ArduinoBoard101) combina un x86 (Quark) con un ARC de 32bits, ambos a 32MHz.

Finalmente, se han comercializado modelos que incluían algún periférico para comunicaciones: [Yún](https://www.arduino.cc/en/Main/ArduinoBoardYun) con Ethernet y Wifi, [BT](https://www.arduino.cc/en/Main/ArduinoBoardBT) con Bluetooth, o [MegaADK](https://www.arduino.cc/en/Main/ArduinoBoardMegaADK) para interactuar con Android. No obstante, la mayoría de ellos ya no se comercializan, principalmente porque existe una amplia variedad de complementos (*shields*) con rangos de precio amplios y fáciles de conectar a los modelos básicos. También porque en 32bits y el Internet-of-Things (IoT), además de las plataformas compatibles con [ARM mbed](https://developer.mbed.org/platforms/), las placas comercializadas como *Single-Board-Computer (SBC)* permiten ejecutar distribuciones de GNU/Linux y [ofrecen](http://www.eetimes.com/document.asp?doc_id=1328008) prestaciones muy superiores.

## Arduino (AVR)

Aunque el IDE oficial de Arduino permite programar fácilmente las placas y probar los diferentes ejemplos con pequeñas variaciones, resulta insuficiente cuando los proyectos adquieren un mínimo de complejidad. Por ejemplo, cuando se tienen dos placas conectadas, o se trabaja con proyectos compuestos por varios ficheros. Por suerte, puesto que las librerías de Arduino son código C, hay múltiples IDEs alternativos:

- [CodeBlocks Arduino IDE](http://arduinodev.com/codeblocks/)
- [MariaMole](http://dalpix.com/mariamole)
- [Eclipse](https://eclipse.org/), [playground.arduino.cc/Code/Eclipse](http://playground.arduino.cc/Code/Eclipse)
- [Atmel Studio](http://www.atmel.com/tools/atmelstudio.aspx), requiere [Arduino for Microsoft Visual Studio](http://www.visualmicro.com/)
- Lenguajes gráficos:
  - [S4A](http://s4a.cat/), para unir [Scratch](https://scratch.mit.edu/) y Arduino
  - [Ardublock](http://blog.ardublock.com/)
  - [miniBloq](http://blog.minibloq.org/)
  - [Embrio.io](http://www.embrio.io/)
- [playground.arduino.cc/Main/DevelopmentTools](http://playground.arduino.cc/Main/DevelopmentTools)

# Control de versiones del contenido

La ventaja principal y más evidente de un [sistema de control de versiones](https://en.wikipedia.org/wiki/Version_control) (*Version Control System -VCS-*) es que nos permite tener una única copia de un proyecto, con la seguridad de poder hacer cambios y volver en cualquier momento a un estado anterior, si es que nos equivocamos. En otras palabras, evitamos tener varias carpetas con nombres como 'trabajo_final', 'trabajo_final2', 'trabajo_finalB', 'trabajo_definitivo', 'trabajo_finalfinal'... Esta es una característica que encontramos en Dropbox o Google Drive, por ejemplo, donde se guardan versiones de nuestros ficheros cada vez que los modificamos. Algunos procesadores de texto también incluyen ciertas funcionalidades similares.

Más allá, un buen VCS no trata los ficheros como binarios, guardando una copia nueva cada vez que se modifica el fichero. En su lugar, analiza el contenido y guarda únicamente las diferencias, que normalmente ocupan mucho menos. De esta forma no sólo se optimiza el espacio de almacenamiento, sino que se reducen significativamente los tiempos de transferencia. Al mismo tiempo, siempre y cuando el contenido de los ficheros sea accesible (por su formato), el sistema es capaz de gestionar y comprimir la información.

Como resultado de poder analizar el contenido, el VCS puede comparar e identificar las diferencias entre dos versiones del mismo fichero que hayan sido modificadas por personas diferentes (o en momentos diferentes) e identificar los cambios entran en conflicto entre sí. Si no es así, se unen automáticamente. Si hay conflicto, se indica dónde se ha dado y cuáles son los ficheros y líneas afectados.

Las características anteriores hacen prácticamente imprescindible el uso de un VCS cuando se trabaja habitualmente desde varios equipos, o cuando varias personas colaboran en la edición de los mismos ficheros. Por ello, hay un [amplio abanico](https://en.wikipedia.org/wiki/Comparison_of_version_control_software) de VCS, tanto libres como propietarios.

## Git

De entre ellos, [git](https://git-scm.com/), desarrollado por [Linus Torvalds](https://en.wikipedia.org/wiki/Linus_Torvalds), es el más utilizado. En [esta](https://www.youtube.com/watch?v=4XpnKHJAok8) charla de 2007 en Google, el autor presentó el proyecto y valoró sus características en comparación con otros sistemas de control de versiones, como Subversion (SVN), Bazaar, BitKeeper... Se podría resumir, con su estilo característico, en que git hace bien todo lo que el resto llevaban años queriendo conseguir: trabajar sin tener conexión a internet, poder hacer ramas/branches y unirlas, unir varios proyectos en uno, etc. En cierta forma, no le falta razón, porque git es muy potente y hace muy fáciles operaciones relativamente complejas. Sin embargo, su naturaleza distribuida y el hecho de ser principalmente una herramienta de terminal, hacen que el primer paso genere cierta reticencia. Algunas limitaciones, como la imposibilidad de descargar, modificar y enviar a un servidor sólo un subconjunto de fichero de un proyecto, puede crear cierta frustración inicial.

Aún así, el tiempo invertido merece la pena, ya que es un estandar de facto en las comunidades de software y hardware libre, y también en muchas empresas. Por suerte, además, hay disponible en la red todo tipo de información, tutoriales, ejercicios y ejemplos. Por ejemplo, [tryGit](https://try.github.io) es un tutorial interactivo de 15 minutos para conocer los comandos básicos de git desde terminal. Tanto en GNU/Linux como en [Windows](https://git-for-windows.github.io/), se proveen las herramientas `git-gui` (Git GUI) y `gitk` (Repository -> Visualize * History). Adicionalmente, existen [GUIs alternativas](https://git-scm.com/downloads/guis), gratuitas y de pago. Por ejemplo, [GitHub Desktop](https://desktop.github.com/) (disponible para Windows y Mac) ofrece una integración completa de credenciales (generación y adición de claves) con GitHub.

*NOTA: git es un sistema de control de versiones libre y multiplataforma que se puede utilizar en cualquier equipo. GitHub, como se explicará más adelante, es una forja que ofrece espacio web para alojar repositorios de git, además de wikis, alojamiento web, etc. A pesar del nombre, y aunque generalmente utilizamos GitHub como servidor central en el que sincronizar el contenido, es importante entender que son proyectos claramente diferenciados e independientes. No es necesaria una cuenta en GitHub para usar git, y no es necesario usar git para colaborar en GitHub.*

Siendo un sistema tan complejo, es recomendable adquirir las nociones básicas e ir investigando nuevas posibilidades de la herramienta en función de las necesidades. Generalmente suele haber varias formas de realizar tareas complejas, y la solución más adecuada depende del flujo de trabajo concreto que se quiera seguir.

# Documentación

- Wiki (en GitHub o wiki.freejaus.com)
- Markdown
  - Extensión para Firefox
  - Exportar a PDF
  - Convertir a LaTeX
- Plantillas
  - GEA
  - TFG
  - Evento/Actividad

# Difusión

- Webs estáticas en GitHub (freejaus.github.io [forja.freejaus.com] y una por repositorio -*gh-pages*-)
  - HTML + CSS
  - Markdown + Hugo (Golang)
  - Jekyll (Ruby)
- news.freejaus.com (Wordpress)
- Twitter, Youtube, Vimeo...
- Ikasletxea
- ¿? Telegram

# Forja

Se denomina [forja](https://en.wikipedia.org/wiki/Forge_%28software%29) a una plataforma que ofrece servicios integrados para facilitar el desarrollo colaborativo de software. Suelen incluir, al menos, alojamiento de repositorios de código mediante algún sistema de control de versiones, y alojamiento web. Además es habitual encontrar gestores de tareas, gestores de lanzamiento de ediciones, listas de correo o foros, wikis, etc. Las más conocidas son posiblemente [SourceForge](https://en.wikipedia.org/wiki/SourceForge), [Google Code](https://en.wikipedia.org/wiki/Google_Code#Project_hosting) y [GitHub](https://en.wikipedia.org/wiki/GitHub), pero la lista es [extensa](https://en.wikipedia.org/wiki/Comparison_of_source_code_hosting_facilities).

## GitHub

Además de la gestión de código fuente mediante Git, GitHub ofrece recursos para facilitar la gestión y documentación de los proyectos:

- Para la documentación se utiliza una sintaxis basada en [Markdown](https://es.wikipedia.org/wiki/Markdown), pero con ciertas particularidades. En [Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet) hay una referencia de la sintaxis utilizada en Github.
     - El contenido del fichero `REAMDE.md` en la raíz del repositorio se muestra en la página principal del proyecto.
	 - Se facilita una wiki, accesible a través de `github.com/<user|organization>/<repo>/wiki` compuesta por múltiples ficheros `.md`. Además de la posibilidad de editar el contenido a través de la web, en ["Adding and editing wiki pages locally"](https://help.github.com/articles/adding-and-editing-wiki-pages-locally/) hay instrucciones sobre cómo hacer un `git clone` de la wiki, y sobre el formato a utilizar a la hora de editar o crear ficheros.
- Se dispone de un gestor de tareas/bugs, accesible a través de `github.com/<user|organization>/<repo>/issues`. En [Mastering Issues](https://guides.github.com/features/issues/) hay una lectura de 10 minutos sobre su uso.
- Se provee espacio para almacenar una web estática en HTML + CSS, accesible a través de `<user|organization>.github.io/<repo>`. Al igual que en el caso de la wiki, el contenido de ésta se gestiona como un repositorio más, tal como se explica en [Getting Started with GitHub pages](https://guides.github.com/features/pages/). Se pueden utilizar generadores de contenido estático para facilitar la generación de la página estática, como por ejemplo, [Jekyll](https://jekyllrb.com/) (escrito en [Ruby](https://www.ruby-lang.org)) o [Hugo](https://gohugo.io) (escrito en [Go](https://golang.org/)). Los artículos [Using Jekyll with Pages](https://help.github.com/articles/using-jekyll-with-pages/) y [Hosting on GitHub Pages](https://gohugo.io/tutorials/github-pages-blog/) ofrecen más información al respecto.
- En [GitHub Guides](https://guides.github.com/) hay más guías para comprender el flujo de colaboración promovido en GitHub (basado en 'forks' y peticiones de 'pull').

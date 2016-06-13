#Introduccion

##¿Que es RetroPie? (Imagen para Tarjeta SD)

La [imagen para SD de RetroPie](http://blog.petrockblock.com/retropie/retropie-downloads/) contiene un sistema ready-to-use que provee una instalacion completa de todos los sistemas y funciones que estan soportadas por [el script de instalacion de RetroPie](http://blog.petrockblock.com/2012/07/22/retropie-setup-an-initialization-script-for-retroarch-on-the-raspberry-pi/)

- Instalacion de todos los emuladores soportados por el script de instalacion de RetroPie (see section "supported systems/emulators for details")
- Inicio automatico de [Emulation Station](https://github.com/Aloshi/EmulationStation?source=c), el front end para navegar a traves y cargar las ROMs que tengamos
- Splash Screen preconfigurada
- Sistema de comparticion SAMBA dispoible para copiar las ROMs a traves de la conexion de red
- Demonio USB para copiar las ROMs a traves de un pen-drive

##Sistemas/Emuladores soportados

The RetroPie SD-card includes emulators for a whole range of gaming history. Some of these systems are:

    Amiga (UAE4ALL)
    Apple II (LinApple)
    Atari 800 (Atari800)
    Atari 2600 (RetroArch/Stella)
    Atari ST/STE/TT/Falcon (Hatari)
    Apple Macintosh (Basilisk II)
    C64 (VICE)
    Amstrad CPC (#CPC4Rpi)
    Final Burn Alpha (RetroArch/PiFBA, RetroArch/FBA)
    Game Boy (RetroArch/Gambatte)
    Game Boy Advance (GpSP)
    Game Boy Color (RetroArch/Gambatte)
    Sega Game Gear (Osmose)
    Intellivision (jzIntv)
    MAME (RetroArch/mame4all-pi, RetroArch/mame4all)
    MSX (openMSX)
    PC – x86 (rpix86)
    NeoGeo (PiFBA, GnGeo)
    Nintendo Entertainment System (RetroArch/FCEUmm)
    Nintendo 64 (Mupen64Plus-RPi)
    TurboGrafx 16 – PC Engine (RetroArch/Mednafen/pce_fast)
    Ports
    – CaveStory (RetroArch/NXEngine)
    – Doom (RetroArch/PrBoom)
    – Duke Nukem 3D (eDuke)
    ScummVM
    Sega Master System / Mark III (RetroArch/Picodrive, Osmose, DGen)
    Sega Mega Drive / Genesis (RetroArch/Picodrive, DGen)
    Sega Mega-CD / CD (RetroArch/Picodrive, DGen)
    Sega 32X (RetroArch/Picodrive, DGen)
    Playstation 1 (RetroArch/PCSX ReARMed)
    Super Nintendo Entertainment System (RetroArch/Pocket SNES, snes9x-rpi)
    Sinclair ZX Spectrum (Fuse, FBZX)

Una lista de todos los sistemas por orden cronologico de aparicion puede encontrarse [aqui](http://blog.petrockblock.com/arcade-systems-game-consoles-and-home-computers-in-retropie/).

#Instalacion
##Componentes necesarios/recomendados

- Raspberry Pi (A, A+, B, B+, 2, Zero, or 3) - para obtener el mejor rendimientos usar la Raspberry Pi 3.
- Caja Raspberry Pi (opcional pero recomendado)
- Tarjeta MicroSD ([mirar](http://elinux.org/RPi_SD_cards) la lista de tarjetas admitidas)
- Lector de tarjetas MicroSD (para instalar RetroPie desde el PC)
- HDMI cable o cable de 4 Polos RCA a cable de 3.5mm (El HDMI da los mejores resultados)
- Television o Monitor de PC - cualquier dispositivo que funcione con RCA o HDMI
- Wifi Dongle o Cable Ethernet (El Dongle Wifi es mas comodo- lista de compatibilidad de dispositivos [aqui](http://elinux.org/RPi_USB_Wi-Fi_Adapters))
- Fuente de alimentacion Micro USB a 5V 2A (cargador de movil)
- Teclado y raton por USB (tambien es posible acceso por SSH en caso de no disponer)
- Mando de consola (DIY o de cualquier consola. Soporta enlace por bluetooth a mandos de PS3 y por el adaptador wireless de microsoft para mandos X360)

##SD Images
A dia 16/03/2016 hay disponibles dos versiones de RetroPie 3.6. Una version para los modelos RaspBerry Pi 1/Zero (Modelos A, A+,B,B+) y otra version para las RaspBerry Pi 2/3. Descarga la imagene correspondiente:

[Raspberry Pi 1 / Zero](https://github.com/RetroPie/RetroPie-Setup/releases/download/3.6/retropie-v3.6-rpi1.img.gz)

[Raspberry Pi 2 / Raspberry Pi 3](https://github.com/RetroPie/RetroPie-Setup/releases/download/3.6/retropie-v3.6-rpi2.img.gz)

Si los links estan caidos, visitar la pagina de descargas [aqui](https://github.com/RetroPie/RetroPie-Setup/releases)

- Si no estas seguro de que modelo de RaspBerry tienes:

 - Rpi 1/Zero= 1 raspberry when the pi boots up

 - Rpi 2/Rpi 3= 4 raspberries when the pi boots up
	
Si obtienes un error *Illegal Instruction* cuando arranca, has elegido la imagen erronea.

##Instalar la imagen de RetroPie en la SD

Para instalar la imagen SD RetroPie 3.6 en tu tarjeta MicroSD (puede que necesites un adaptador para conectarla a tu PC).

   1. Para Windows puedes utilizar un programa llamado [Win32Imager](http://sourceforge.net/projects/win32diskimager/)
   2. Para Mac puedes utilizar [Apple Pi Baker](http://www.tweaking4all.com/hardware/raspberry-pi/macosx-apple-pi-baker/)
   3. Para Linux puedes usar el comando "dd" o [UnetBootin](https://unetbootin.github.io/)

Si estas actualizando desde una version anterior de Retropie, ve [aqui](https://github.com/RetroPie/RetroPie-Setup/wiki/Updating-RetroPie)

#Primeras configuraciones

##Arranque y deteccion de mando(s)

Cuando el sistema arranquue por primera vez, veras una pantalla similar a esta: 

![](https://cloud.githubusercontent.com/assets/10035308/9140482/cf42f25c-3cee-11e5-8f91-c1fc1c57175c.png)

Manten pulsado cualquier boton de tu mando/teclado durante unos segundos para que detecte el mismo y te lance la pantalla de configuracion.

![](https://cloud.githubusercontent.com/assets/10035308/9140518/0263b9c8-3cef-11e5-922f-42f790f3be91.png)

La configuracion creada para RetroArch, se almacena en:
```bash
/opt/retropie/configs/all/retroarch-joypads

```

Para configurar un segundo controlador, sera necesario que lo hagamos desde el menu de Emulation Station por lo que hablaremos de ello mas adelante.

Como esquemas a tener en cuenta, como guia para la configuracion de los controladores:

![](https://cloud.githubusercontent.com/assets/10035308/7110174/0f2fdb54-e16a-11e4-8f3d-37bdca8f1ddf.png)

![](https://cloud.githubusercontent.com/assets/10035308/7110173/0f2ea784-e16a-11e4-9c6f-5fe7c594b05a.png)

![](https://cloud.githubusercontent.com/assets/10035308/7111199/e29365ec-e179-11e4-87b4-f00685661d7e.png)

###Utilizar el SmartPhone como mando a distancia (Experimental: 22/03/2016)
Este proyecyo es el resultado del duro trabajo de Miroof: https://github.com/miroof/node-virtual-gamepads

Instalable desde el menu de aplicaciones experimentales del script de instalacion (Setup-Script)(puede que solo funcione a partir de la RaspBerry 2)

####Utilizacion

Una vez que la aplicacion nodejs es lanzada, solo tienees que conectar tu gamepad accediendo con tu dispositivo a la misma red local y conectandote a la direccion http://node_server_adress (ej. la direccion de tu RaspBerry Pi) en tu navegador (se recomienda utilizar Chrome Mobile).

###Uso como aplicacion para SmartPhone (Chrome for Android)

Nota: tienes que configurar el gamepad virtual para EmulationStation ANTES de que crees la configuracion para la aplicacion en tu SmartPhone. En caso contrario, no funcionara la configuracion de entrada de EmulationStation (Input Configuration).

Con la caracteristica de chrome de añadir a la ventana de 'homescreen', puedes utilizar tus diferentes gamepads virtuales sin lanzar el navegador cada vez que quieras jugar.

Con solo 3 clicks, la aplicacion web para gamepads se convierte en una aplicacion standalone.


![](https://raw.githubusercontent.com/miroof/node-virtual-gamepads/resources/screenshots/standalone_step1.png)![](https://raw.githubusercontent.com/miroof/node-virtual-gamepads/resources/screenshots/standalone_step2.png)	

Entonces se generara un shortcut (acceso directo) a la aplicacion sin tener que abrir el navegador.

![](https://raw.githubusercontent.com/miroof/node-virtual-gamepads/resources/screenshots/standalone_step3.png)![](https://raw.githubusercontent.com/miroof/node-virtual-gamepads/resources/screenshots/standalone_step4.png)

###Funcionamiento de la aplicacion

Debido a que es dificil acertar al diseño/adaptacion de un mando convencional en una pantalla tactil, la zona de pulsacion de cada boton se ha aumentado. El boton LT ha sido ubicado en el centro en lugar de la izquierda para disponer de mas control sobre el pad de direccion.

![](https://github.com/miroof/node-virtual-gamepads/raw/resources/schemas/touch_zones.png)

Para saber si hemos pulsado un boton correctamente, la aplicacion web nos provee de un feedback haptico, el cual puede ser desactivado desactivando la vibracion del telefono.

Necesitaras configurar tu controlador con Emulation Station y RetroArch como si de cualquier otro controlador se tratara.

Tambien se puede instalar manualmente utilizando el siguiente script:

```bash
### Install Node.js

sudo apt-get update && sudo apt-get upgrade
wget http://node-arm.herokuapp.com/node_archive_armhf.deb
sudo dpkg -i node_archive_armhf.deb
rm node_archive_armhf.deb

### Install Virtual Gamepad (Must Be Run As Root!)

su
git clone https://github.com/miroof/node-virtual-gamepads
cd node-virtual-gamepads
npm install


### Enable Virtual Gamepad on Boot

sudo npm install pm2 -g
sudo pm2 start main.js
sudo pm2 startup
sudo pm2 save
```

###Configuracion del control en Emulation Station
####/opt/retropie/configs/all/retroarch-joypads/Virtualgamepad.cfg

```
input_device = "Virtual gamepad"
input_driver = "udev"
input_r_btn = "5"
input_save_state_btn = "5"
input_start_btn = "7"
input_exit_emulator_btn = "7"
input_l_btn = "4"
input_load_state_btn = "4"
input_up_axis = "-1"
input_a_btn = "0"
input_b_btn = "1"
input_reset_btn = "1"
input_down_axis = "+1"
input_right_axis = "+0"
input_state_slot_increase_axis = "+0"
input_x_btn = "2"
input_menu_toggle_btn = "2"
input_select_btn = "6"
input_enable_hotkey_btn = "6"
input_y_btn = "3"
input_left_axis = "-0"
input_state_slot_decrease_axis = "-0"
```


###Hot-Keys por defecto

Las hotkeys te permiten acceder a ciertas funciones del sistema tales como guardar, cargar y salir de los emuladores. La siguiente tabla muestra la combinacion por defecto de dichos botones. De forma predeterminada, la hotkey es el select, de forma que tienes que mantenerlo junto a otro boton para ejecutar un comando.

| Hotkeys | Action |
|--------|--------|
|Select + Start|Exit|
|Select + Right Shoulder|Save|
|Select + Left Shoulder| Load|
|Select + Right|Input State Slot Increase|
|Select + Left|Input State Slot Decrease|
|Select + X |RGUI Menu|
|Select + B |Reset|

##Expandir el sistema de ficheros

Si tu tarjeta es de mas de 4GB es necesario expandir el sistema raiz de archivos para que sea posible utilizar todo el almacenamiento disponible en la tarjeta SD

- Desde el menu de EmulationStation

Nos dirigimos a la seccion RetroPie y dentro de esta vamos a **Raspberry Pi configuration tool RASPI-CONFIG**

![](https://cloud.githubusercontent.com/assets/10035308/12865761/adc9f5c6-cc72-11e5-9b02-9e98b90bbd98.png)

Una vez dentro seleccionamos la opcion **expand filesystem**. Al terminar nos pedira si queremos reiniciar. Reiniciamos.

- Desde la terminal de Raspbian

Accedemos a la terminal pulsando F4 en el teclado en cualquier parte del menu de Emulation Station.

Se abrira una ventana de terminal. Tecleamos:

```bash
sudo raspi-config
```

##Configuracion Wifi

Si se desea utilizar la conexion wifi para realizar las actualizaciones o enviar las ROMs a la RaspBerry Pi deberemos abrir el menu "RetroPie" y en el, configuracion WiFi.

![](https://cloud.githubusercontent.com/assets/10035308/12865761/adc9f5c6-cc72-11e5-9b02-9e98b90bbd98.png) 

Se abrira el siguiente menu:

![](https://cloud.githubusercontent.com/assets/10035308/9141521/96ceb142-3cf6-11e5-9ba4-2b23a8b52480.png)

Con la ayuda del mando y/o del teclado. Buscaremos nuestra red y nos conectaremos a la misma.

Es necesario recordar la direccion IP para poder conectarnos a la RaspBerry mediante SSH o FTP.

Para mas configuraciones wifi visitar [esta](https://github.com/RetroPie/RetroPie-Setup/wiki/Wifi) pagina

##Actualizar RetroPie

Nos dirigiremos al menu RetroPie dentro de Emulation Station. 

Tambien se puede acceder desde la terminal con

```bash
cd RetroPie-Setup
sudo ./retropie_setup.sh
```

###Utilizando el Scrip de instalacion de RetroPie

![](/home/josu/Escritorio/e3f20a02-d957-11e5-9b10-3e3dc7da2bac.png)

En la parte superior nos indicara la **version de Script** que estamos utilizando, que no tiene por que ser la misma que la version de RetroPie. El **last commit** nos indicara cuando se ha actualizado el sistema desde Github.

Lo primero y **mas importante** es actualizar el script de instalacion con los ultimos cambios

1. **Binary based installation (recomended)**: Si quieres realizar una actualizacion total, esta es la mejor opcion que puedes elegir. Es altamente recomendable realizar una copia de seguridad antes de proceder con esta operacion.
2. **Source-based installation**: no recomiendo utilizar esta opcion dado que tarda unas 24h (en la RaspBerry 1) y suele terminar con errores por emuladores que no han sido instalados correctamente
3. **Setup/Configuration**: aqui es donde puedes actualizar configuraciones, instalar nuevos temas, nuevos controladores/drivers... muchas de estas opciones se encuentran tambien en el menu de RetroPie dentro de Emulation Station.
4. **Experimental Packages**: Como su nombre indica, contiene emuladores que un no han sido probados o testeados con tiempo.
5. **Install Individual Emulators from Binary or Source**: Desde aqui se pueden actualizar los emuladores de forma individual. Debes seleccionar actualizacion mediante binarios siempre que sea posible pues se actualizan con mas frecuencia, tienen menos bugs y son bastante mas rapidos de installar. Habra ocasiones donde tengas que hacerlo mediante **source**, pero siempre que te sea posible hazlo con **binary**
6. **Uninstall RetroPie**: Elimina la instalacion actual de RetroPie en Raspbian. Esta opcion esta aun en pruebas y hay cosas que se tendran que eliminar manualmente una vez finalice.
7. **Update RetroPie-Setup script**: Actualiza la informacion desde GitHub para disponer de los ultimos instaladores y las ultimas actualizaciones para los emuladores
8. **Perform Reboot**: Reinicia el sistema RaspBerry Pi

###Ultima imagen SD

En caso de que tengas problemas actualizando el sistema. Coge los archivos de tu sistema RetroPie y copialos en la ultima imagen disponible del sistema. De esta forma no perderas informacion.

##Transfiriendo ROMs

Debido a las restricciones de CopyRight's/Propiedad Intelectual no es posible facilitar ROMs. Y deben de ser obtenidas por el usuario. SOLO PUEDES TENER ROMs DE JUEGOS QUE HAS COMPRADO.

###Metodos principales para transferir ROMs

####USB

1. asegurate de que tu Pen-Drive esta formateado en FAT32
2. una vez formateado. Crea una carpeta llamada **retropie** en tu unidad USB
3. conectalo a la RaspBerry y espera a que el led indicador (del Pen-Drive) deje de parpadear
4. añade las roms a sus respectivas carpetas (dentro de retropie/roms) Ej. copiamos Crash.iso a /retropie/roms/psx (el nombre del emulador destino)
5. conectamos de nuevo a la RaspBerry 
6. esperamos a que el led del Pen-Drive deje de parpadear
7. refrescamos Emulation Station eligiendo esa opcion en el menu start

#####FTP (precisa conexion local al menos entre el PC y la RaspBerry)

1. asegurate de que tu RaspBerry y tu PC se encuentran en la misma red (estan conectados, bien por cable o por Wifi al mismo enrutador)
2. en caso de encontrarnos en windows podemos usar [WinSCP](https://winscp.net/eng/download.php) o [FileZilla](https://filezilla-project.org/), para Mac podemos usar [Cyberduck](https://cyberduck.io/?l=en) y en linux [FileZilla](https://filezilla-project.org/).

Como nombre de usuario usaremos **pi** y como contraseña **retropie**, el servidor sera **la direccion IP** de la RetroPie y el puerto, por defecto el **22**.

Si se quieren modificar mas archivos, sera necesario que hagamos login con el usuario **root**. Primero tendremos que habilitar el usuo de la contraseña para root, mas informacion [aqui](https://github.com/RetroPie/RetroPie-Setup/wiki/FAQ#why-cant-i-ssh-as-root-anymore).

####Samba-Share (necesita de conexion local al menos)

1. Si nos encontramos en Windows, en cualquier carpeta nos dirigimos a la barra de direcciones y tecleamos **\\retrope**. Tamien podemos acceder con la IP de nuestra RaspBerry.
2. Si estamos en MAC OS X. Abrimos finder y seleccionamos "Ir"  en el menu y "Conectar al servidor". Escribimos **smb://retropie** y elegimos "Conectar"

##Haciendo un BackUp (Opcion 1 - La imagen ocupa lo mismo que la capacidad maxima de la tarjeta)

Puedes crear una imagen de tu tarjeta SD actual con Win32DiskImager.

+ Conecta tu SD a tu PC
+ Abre Win32DiskImager como administrador (boton derecho, abrir como administrdor)

![](/home/josu/Escritorio/admin.png)

+ Selecciona la letra de unidad correspondiente a la tarjeta SD
+ Selecciona un lugar donde guardar la imagen. Crearemos un archivo llamado **backup.img**

![](/home/josu/Escritorio/imagen.png)

+ Clickamos sobre **read** para crear el backup.

Ten en cuenta que siempre creara un backup del tamaño total de almacenamiento de la tarjeta SD. Es decir, si tu tarjeta es de 64GB siempre creara un backup de 64GB.

En caso de no querer que esto ocurra. Nos dirigimos a la siguiente opcion.

##Haciendo un Backup (Opcion 2 - Solo guardamos lo que necesitamos)

Si no queremos guardar una imagen SD del sistema completo. Podemos conectarnos mediante SAMBA y copiar las carpetas **bios, configs y roms**.

![](/home/josu/Escritorio/backup.png)

##Haciendo un BackUp (Mac OS X)


Abrimos una ventana de terminal y escribimos``` diskutil list```. Una lista de todos los discos duros y de las particiones sera mostrada. Buscamos la particion con nombre **boot**. El relacionado **/dev/disk** es tu tarjeta SD. Escribe:```sudo dd if=/dev/disk* of=backup.img bs=1m
``` para escribir una imagen en tu drectorio de usuario.

##Conectando por SHH

Puedes conectarte a la RaspBerry Pi con un cliente SSH, uno recomendable/conocido es Putty.

'''
Nota: Tu RaspBerry Pi tiene que estar conectada a la misma red (da igual por cable o por WiFi) que el ordenador desde el cual se esta intentado acceder.

Cuando arranques Putty por primera vez, podras loguearte con los siguientes credenciales:

![](https://cloud.githubusercontent.com/assets/10035308/10655671/23eaa6b2-7834-11e5-8c85-9266c5ab808a.png)

Tambien se puede utilizar la direccion Ip de la RaspBerry para poder acceder, en lugar de utilizar **retropie**.

###Login por defecto

usuario: **pi**
contraseña: **root**

Mira [aqui](https://github.com/RetroPie/RetroPie-Setup/wiki/FAQ#why-cant-i-ssh-as-root-anymore) si quieres hacer login como root

###Algunos comandos utiles para la terminal

**reboot** ```sudo reboot -h now``` (Solicitara la password del usuario administrador o de un usuario con permisos administrativos)
**shutdown** ```sudo shutdown -h now```
**cambiar de directorio/carpeta** ```cd /ruta/de/destino```
**ver los archivos del directorio/carpeta actual** ```ls```
**iniciar el setup-script de RetroPie** ```cd Retropie && sudo ./retropie_setup.sh```
**editar un archivo (texto) con nano** ```nano /ruta/del/archivo.txt``` (Si el archivo especificado no existe, creara uno con el mismo nombre)
**cambiar el propietario de un arhivo al usuario Pi** ```sudo chown pi:pi archivoasercambiado```
**cambia el propietario de una carpeta y todos sus archivos al usuario Pi** ```sudo chown -R pi:pi /ruta/de/la/carpeta```
**hacer ejecutable un shellScript (.sh)** ```sudo chmod +x archivodeshell.sh```

#Problemas tras la instalacion

##Problemas con HDMI/Audio a traves de HDMI

###La RaspBerry no envia sonido a traves de HDMI.

En algunos casos, detecta que el televisor donde se esta mostrando el contenido no tiene altavoces. Es decir, lo dectecta en modo monitor de PC. Si hemos probado con otros televisiones y suena; o no tenemos posibilidad de probar con otro TV:

Pulsamos F4 para dirigirnos a la CLI (Interfaz en Linea de Comandos).

Nos dirigimos a la carpeta **/boot/configs.txt** y descomentamos **hdmi_drive=2**.

Reiniciamos la raspberry con el comando **sudo reboot -h now**

En caso de que siga sin emitir sonido a traves de HDMI tendremos que revisar otras opciones. Y volveremos a comentar la linea anteriormente mencionada.

###La RaspBerry no funciona por HDMI

Una vez comprobemos que tanto el cable como el TV funcionan bien (comprobar entre si, mediante prueba cruzada con otros equipos) procederemos a forzar el arranque del sistema con HDMI, a pesar de que la RaspBerry no detecte ninguno conectado.

Pulsamos F4 para dirigirnos a la CLI (Interfaz en Linea de Comandos).

Nos dirigimos a la carpeta **/boot/configs.txt** y descomentamos **hdmi_force_hotplug=1**.

Reiniciamos la raspberry con el comando **sudo reboot -h now**

##Ciertos juegos/emuladores funcionan muy lento

De [ToadKing](http://www.raspberrypi.org/phpBB3/viewtopic.php?p=137827#p137827):

BTW, for most of those cores you should be able to get at or near full speed, with some exceptions:

Para la mayoria de [estos cores](http://www.youtube.com/watch?v=rm3IuXeIfaw) deberias de ser capaz de optener toda o cerca de toda la velocidad, con algunas excepciones:

**imame4all**: La velocidad depende del juego. Ciertos juegos de Midway son conocidos por ser muy lentos (Mortal Kombat, NBA Jam...).
**pocketsnes**: Algunos juegos, especiamente los SuperFX y SA-1 funcionaran bastante lento en la velocidad por defecto de la RaspBerry Pi. Algunos efectos graficos de otros juegos pueden dar lag en algunas pantallas especificas. Si se overclockea la RaspBerry a 950 Mhz y ejecuta la mayoria de los juegos sin probelmas, a excepcion de los ya mencionados SuperFX y SA-1.
**vba-next**: Seguramente no conseguiras que funcione a la total velocidad. Otra alternativa seria utilizar algun otro port.
**genesis-plus-gx**: Sigue funcionando un poco lento en la RaspBerry. Otro port tambien seria una buena opcion.
**mupen64plus**: Debido a la limitada potencia de procesado algunos juegos nunca funcionaran a velocidad normal en la RaspBerry Pi 2.
**reicast**: Debido a la limitada potencia de procesado algunos juegos nunca funcionaran a velocidad normal en la RaspBerry Pi 2.
**ppsspp**: Debido a la limitada potencia de procesado algunos juegos nunca funcionaran a velocidad normal en la RaspBerry Pi 2.

###Mejoras generales en RetroArch

En caso de querer aplicar las mejoras para todos los sistemas que utilicen RetroArch nos dirigimos a la ruta``/opt/retropie/configs/all/retroarch.cfg `` y editamos el archivo con nano (nano /opt/retropie/configs/all/retroarch.cfg).

Modificamos la opcion correspondiente para que concuerde con ``video_threaded = true``.

En caso de querer aplicar esa configuracion unicamente para un emulador, tendremos que editar el archivo correspondiente al sistema que queramos. De la siguiente forma ```/opt/retropie/configs/NOMBREDELSISTEMA/retroarch.cfg```

Donde el nombre del sistema es atari2600, snes...

###Overclocking en la comunidad RaspBerry Pi (foro)
Hay un hilo acerca del overclocling en la RPi en el foro oficial de la fundacion. Puedes encontrarlo [aqui](http://www.raspberrypi.org/phpBB3/viewtopic.php?f=29&t=6201)

###Overclocking con RetroPie Setup
En el menu 'Setup' puedes encontrar la opcion para cambiar las frecuencias de ARM y SDRAM. Ten en cuenta que los cambios tendran efecto despues de reiniciar la RaspBerry.

###Overclocking con raspi-config
Puedes overclockear tu RaspBerry sin comprometer su garantia con el script oficial de raspi-config. Puede ser iniciado con ``sudo raspi-config``

##La configuracion de RetroArch (para los emuladores) y los juegos no se guardan una vez reiniciado el sistema
Debido a los permisos del sistema de archivos no es posible que se guarden las partidas al iniciar la RaspBerry Pi.Para solucionarlo, procederemos de la siguiente forma.

```bash
cd
sudo chown -R pi /home/pi/RetroPi
```

Reiniciamos y RetroArch ya sera capaz de guardar las partidas
##Configuracion avanzada de mandos
###Configurar un mando de la XBOX 360
####Configuracion automatica

Accede al **RetroPie Setup Script** y navega a **Setup/ Configuration >>> Xbox / Xbox 360 gamepad driver**

![](https://cloud.githubusercontent.com/assets/10035308/12218229/d397607e-b6d6-11e5-8a99-f3106d60425a.png)

**Enable xboxdrv**: Esto instalara el driver y añadira una configuracion de arranque en ```/etc/rc.local```
**Disable xboxdrv**: Esto desinstalara el driver y quitara la configuracion de arranque en ```/etc/rc.local```
**Set Number of Controllers To Enable**: El numero por defecto de gamepads/mandos es 2 (Si tienes mas de dos mandos/gamepads es necesario que indiques cuantos antes de lanzar *enable xboxdrv*)
**Set Analog Stick Deadzone**: numeros bajos = mas sensible, numeros altos = menos sensible
**Set dwc_otg.speed=1 in /boot/config.txt**: Puede ayudar en caso de que el controlador este dando problemas.
**Remove dwc_otg.speed=1 from /boot/config.txt**: Elimina la configuracion anterior.

***Nota***: Si estas utilizando controladores inalambricos, necesitaras tener el 'Wireless Receiver' conectado en tu RaspBerry Pi (Official Microsoft xbox360 Receiver o alguna replica conocida). Entonces, para conectar:

+ Pulsa en el boton del receptor inalambrico
+ Pulsa el pequeño boton de 'Wireless' en la parte superior del mando
+ Repite el proceso para cada controlador
+ Los controladores deben estar encendidos antes del arranque de la RaspBerry para funcionar correctamente
 + Prueba el dia 12/03/16. En los casos en los que el controlador esta emparejado con el 'Wireless Receiver', solo es necesario disponer de dicho controlador conectado a la RaspBerry Pi. 

####Configuracion manual de los botones

En caso de querer modificar algun boton manualmente:

Editaremos el fichero ```/home/pi/RetroPie/configs/all/retroarch.cfg``` (nano /home/pi/RetroPie/configs/all/retroarch.cfg)

```
#Player 1
input_player1_joypad_index = 0
input_player1_b_btn = 6
input_player1_a_btn = 4
input_player1_y_btn = 7
input_player1_x_btn = 5
input_player1_l_btn = 10
input_player1_r_btn = 11
input_player1_start_btn = 13
input_player1_select_btn = 12
input_player1_up_btn = 0
input_player1_down_btn = 1
input_player1_left_btn = 2
input_player1_right_btn = 3
input_exit_emulator_btn = 15
input_menu_toggle_btn = 16

#Player 2
input_player2_joypad_index = 1
input_player2_b_btn = 6
input_player2_a_btn = 4
input_player2_y_btn = 7
input_player2_x_btn = 5
input_player2_l_btn = 10
input_player2_r_btn = 11
input_player2_start_btn = 13
input_player2_select_btn = 12
input_player2_up_btn = 0
input_player2_down_btn = 1
input_player2_left_btn = 2
input_player2_right_btn = 3
```

##Algunos emuladores no funcionan debido a que falta un archivo de BIOS
En el caso de ciertos emuladores (Ej. PSP, Game Boy Advance, PSX) es necesario un arhivo de BIOS que se encargue de "entender" las imagenes de los juegos.

No es posible proveer las BIOS de los emuladores. **Y no es legal utilizar emuladores ni juegos de sistemas que no posees**

Para ciertos emuladores es necesario añadir archivos de BIOS diferentes por cada region (Ej. Europa, USA, Asia)

Sera necesario ubicar los archivos de BIOS de las roms en ```/home/pi/RetroPie/BIOS```






	


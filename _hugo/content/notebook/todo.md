---
menu:
  notebook:
    name: 'ToDo'
    identifier: 'todo'
    pre: "list-alt"
    weight: -0

categories: [ "Notebook" ]
tags: [ "todo" ]

title: "ToDo"
keywords: todo

publishdate: 2016-01-01
date: 2015-11-20
---

- Contenido
  - Participantes: ¡Privacidad! ¡SPAM! ¿añadir sección específica con la información abiertamente disponible? ¿o utilizar usuarios de GitHub y un grupo (*team*)? ¿o utilizar una rama del repositorio?
  - /ardupi/notebook/, que actualmente muestra DEFAULT LIST en blanco
  - Diseñar plantilla de contenido para los proyectos, para después diseñar el layout
  - Diseñar layout para los TFGs, imitando la plantilla de la guía
  - Diseñar layout para los GEA, imitando la plantilla de la guía
- Layouts y CSS
  - Adaptar CSSs para sustituir los colores ekin por freejaus.
  - Adaptar layouts notebook para compartir partials/nav con index. Tratar de mantener el mayor contenido en fj-base, y añadir sólo lo necesario a fj-index y fj-nb.
  - Eliminar los layouts no utilizados en partials/index/.
  - Eliminar los layouts no utilizados en notebook/.
  - Ajustar el CSS de las tablas escritas en Markdown, para incluir separación entre columnas.
- JavaScript
  - Cambiar el fondo de nav en index cuando se empieza a hacer scroll.
  - Desplegar los elementos de una categoría en notebook, cuando se está en la página principal de la misma (overview, list...) y el ratón está en el menú sobre la página principal, o cualquiera de las hijas.
  - Cuadros *spoiler*, que muestran la entradilla de un contenido y permiten desplegarlo en la misma página. Utilizarlo para código, avisos, notas...
  - Que cada usuario pueda escoger el estilo. ¿Se pueden ofrecer varios templates? ¿O sólo un cambio de CSS?
- Deployment
  - Actualizar automáticamente la fecha de cada contenido con el último commit en el que se haya modificado.
  - Mover el subdirectorio *_hugo* de la rama *gh-pages* al subdirectorio *web* de la rama *master*. Añadir un subdirectorio *public* en *web*, asociado a la rama *gh-pages*. El contenido se modifica en la rama máster, y cuando se hace un commit *'especial'* (¿*hook*?), se despliega:
     - Se elimina el contenido existente en *public* (salvo *.git/*, naturalmente).
	 - Se ejecuta Hugo sobre *_hugo* para exportar en *public*.
	 - Se hace commit en *public*, que es en realidad la rama *gh-pages*.
- Tutoriales
  - Cómo editar el contenido en la wiki
web
  - Cómo transferir el contenido de la wiki a la web
  - Cómo hacer deploy de la web. ¿Quién puede hacerlo?
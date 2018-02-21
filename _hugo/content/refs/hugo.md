---
title: "Hugo"
keywords: hugo static site generator golang tour doc
---

<!--
git bash
mingw
msys

La mayoría de las páginas que visitamos hoy en día están basadas en gestores de contenidos (*Content Management System -CMS-*). Algunos de los más conocidos son WordPress, Drupal o Joomla. Estos están escritos
-->

- [Hugo - Hosting on GitHub Pages](https://gohugo.io/tutorials/github-pages-blog/)

GitHub provee espacio de alojamiento para páginas web estáticas, lo que quiere decir que no se pueden utilizar gestores de contenidos como WordPress o Drupal (escritos en lenguajes como PHP, Ruby o Python para generar el contenido de forma dinámica. Sin embargo, no es necesario editar a mano todo el contenido utilizando HTML, CSS y JavaScript. Existen programas denominados *generadores* de páginas estáticas que, partiendo de contenido marcado (típicamente Markdown), aplican plantillas para facilitar la tarea de creación de las páginas en HTML. Estos permiten alojar en GitHub páginas de cierta complejidad con poco esfuerzo y en un tiempo muy reducido. Incluso pueden incluirse foros, vídeos y formularios. No obstante, en este artículo vamos a centrarnos en los aspectos básicos.

Los generadores de páginas estáticas más conocidos, aunque no los únicos, son [Jekyll]() (basado en Ruby) y [Hugo]() (basado en Golang). Ambos proveen funcionalidades similares, y muchas plantillas (generalmente de Bootstrap) están adaptadas a los dos. En FreeJaus utilizamos *Hugo* principalmente, pero en algunos repositorios es posible encontrar fuentes para ambos generadores.

# Estructura del proyecto

En los repositorios en que se utiliza *Hugo* para generar la página web, hay una carpeta `_hugo` en la rama (*branch*) `master`. La estructura de la misma es la esperada por el programa, tal como se indica [aquí](https://gohugo.io/overview/source-directory/). Como no se utilizan todas posibilidades que ofrece *Hugo*, es habitual encontrar sólo algunos de los directorios:

- [repositorio/_hugo]
  - [archetypes]
  - [content]
     - [seccion]
	     - post1.md
		 - post2.md
  - [layouts]
     - index.html
	 - [_default]
	 - [partials]
  - [static]
  - config.yaml

# Cómo obtener Hugo

Se pueden descargar los binarios del apartado [releases](https://github.com/spf13/hugo/releases) de la página [github.com/spf13/hugo](https://github.com/spf13/hugo/). Hay versiones de 32 y 64 bits para arquitecturas x86 y ARM y sistemas Linux, Windows, BSD (OpenBSD, NetBSD, FreeBSD, Darwin, Dragonfly)...

Alternativamente se puede compilar Hugo desde las fuentes. Como *Hugo* está escrito en Go, y se distribuye como un paquete, hay que instalar [golang](https://golang.org/). Una vez hecho, se establece el directorio de trabajo y se descargar y compila el paquete:

```
cd ~
mkdir gowork
cd gowork
export GOPATH=$(pwd)
go install -v github.com/spf13/hugo
```

El binario resultante estará en `$GOPATH/bin/`. Valiéndonos de las posibilidades de compilación cruzada de *Go*, se pueden generar binarios para otras arquitecturas.

PROBLEMA LIBRERÍA BITBUCKET QUE UTILIZA MERCURIAL Y DESDE WINDOWS NO SE PUEDE HACER PULL

# Escoger un tema

Hugo utiliza temas para generar el sitio web a partir del contenido escrito en Markdown. Se puede definir un único tema en los subdirectorios `layouts` y `static`, pero es más habitual utilizar el subdirectorio `themes` y crear un directorio por tema. En [gohugo.io/themes/overview](https://gohugo.io/themes/overview/) se explica cómo funcionan los temas, cómo instalarlos, utilizarlos y modificarlos. Asimismo, en [themes.gohugo.io](http://themes.gohugo.io/) hay un catálogo de temas, que pueden descargarse a través de la página o directamente del repositorio [github.com/spf13/hugoThemes](https://github.com/spf13/hugoThemes).

También hay disponibles temas en páginas de terceros. [Blakcburn](http://themes.gohugo.io/blackburn/), por ejemplo, está en el repositorio anterior y en [github.com/yoshiharuyamashita/blackburn](https://github.com/yoshiharuyamashita/blackburn). Para utilizarlo:

```
cd repositorio/_hugo
mkdir themes
cd themes
git clone https://github.com/yoshiharuyamashita/blackburn.git
```

Cada plantilla espera que el contenido esté organizado en un orden determinado. Del mismo modo, espera que en el fichero de configuración haya unos campos determinados. Si no se siguen los patrones esperados, es posible que parte o todo el contenido no se muestre, o lo haga parcialmente. Para conocerlos, es importante leer la documentación de quien ha diseñado la plantilla.

# Servidor local

Puesto que *Go* dispone de librerías integradas para desplegar servicios web, *Hugo* permite [probar](https://gohugo.io/overview/usage/) en tiempo real el resultado de la página, antes de generar los ficheros finales. Para ello, deberemos ejecutar el binario desde la carpeta donde se encuentra el fichero de configuración, con el argumento `serve` o `server`:

```
cd repositorio/_hugo
$GOPATH/bin/hugo -t TEMA server
```

Se mostrará en la terminal la URL local, normalmente `localhost:1313`, que introduciremos en el navegador para ver la página. Si modificamos cualquier fichero, *Hugo* regenerará las páginas afecatadas y actualizará el navegador. Debemos tener en cuenta que en caso de indicar en el fichero de configuración una dirección base del tipo `nombre.dominio/seccion`, deberemos introducir `localhost:1313/seccion` en el navegador.

# Publicación

Cuando el resultado sea satisfactorio y se desee actualizar la página, se ejecutará *Hugo* sin el argumento `server`. Como resultado, se generarán todas las páginas en HTML en el directorio `public` (o el que se haya indicado en el fichero de configuración). En otras palabras, sólo deberemos copiar el contenido de `public` a la ubicación del servidor web. En el caso de los repositorios de GitHub, esta ubicación es la rama (*branch*) `gh-pages`.

En primer lugar, moveremos `public` temporalmente fuera del repositorio:

```
cd repositorio
mv _hugo/public ../
```

Si no tenemos la rama `gh-pages` en nuestro equipo (podemos comprobarlo mediante `git branch`), la añadiremos y actualizaremos:

```
cd repositorio
git fetch
git checkout --orphan gh-pages
git rm -rf .
git pull -u origin gh-pages
```

Si ya la tenemos añadida, simplemente cambiaremos de rama y actualizaremos:

```
cd repositorio
git checkout gh-pages
git fetch
git pull
```

Para renovar el contenido, borraremos todo lo anterior, añadiremos lo nuevo, añadiremos todo y haremos un `commit`:

```
rm -rf ./*
mv ../public/* ./
git add ./*
git commit -am "Pagina actualizada"
```

Esperaremos unos segundos y actualizaremos el navegador: `freejaus.github.io/repositorio`

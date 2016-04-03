---
categories: [ nb-refs ]

title: "Docker"
keywords: docker container deployment cluster swarm

publishdate: 2016-01-01
date: 2016-01-01
---

https://docs.docker.com/engine/installation/linux/fedora/

```
sudo dnf install docker

sudo systemctl start docker  #Para iniciarlo en la sesión [stop]
sudo systemctl enable docker #Para iniciarlo al arrancar [disable]

sudo docker info
sudo docker run hello-world

sudo groupadd docker         #Para no tener que utilizar sudo
sudo usermod -aG docker user
```

---

Para compartir una carpeta entre el host y el contenedor, en este caso montada en `/src/dockershare` y `/opt/work`, respectivamente:

```
sudo docker run -itv /src/dockershare:/opt/work:z ubuntu bash
```

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

sudo systemctl start docker  #Para iniciarlo en la sesión
sudo systemctl enable docker #Para iniciarlo al arrancar

sudo docker info
sudo docker run hello-world

sudo groupadd docker         #Para no tener que utilizar sudo
sudo usermod -aG docker user


```

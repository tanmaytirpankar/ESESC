FROM ubuntu:16.04

MAINTAINER Tanmay


RUN apt-get update
RUN apt-get install -y gcc-4.8 g++-4.8 cmake git bison flex zlib1g-dev libboost-dev libglib2.0-dev libncurses5-dev libpixman-1-dev graphviz vim
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 10
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 10

COPY . /home/ESESC
RUN cp -r /home/ESESC/apps /home/
RUN mkdir /home/ESESC/esesc/build && cd /home/ESESC/esesc/build && cmake .. && make
RUN mv /home/ESESC/esesc/build/main/esesc /home/ESESC/esesc/work
RUN mkdir /home/ESESC/apps/phoenix && mkdir /home/ESESC/apps/phoenix/bin
RUN cp /home/ESESC/apps/kmeans/bin/kmeans_pthread.mips64 /home/ESESC/apps/phoenix/bin
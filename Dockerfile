FROM debian
Maintainer Chistyakova Ekaterina
RUN apt-get upgrade -y
RUN apt-get install -y vim
RUN apt-get install -y gcc-multlib
RUN apt-get install -y gcc
RUN apt-get install -y g++
RUN apt-get install -y python3

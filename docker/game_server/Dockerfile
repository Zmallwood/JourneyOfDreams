FROM ubuntu:latest
MAINTAINER zmallwood@proton.me

RUN mkdir -p /app

COPY ./bin_server /app

WORKDIR /app

RUN apt-get update
RUN apt-get -y install python2

EXPOSE 1238

CMD ["./Server"]

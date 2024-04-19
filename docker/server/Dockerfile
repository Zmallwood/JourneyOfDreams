#This is a sample Image
FROM ubuntu:latest
MAINTAINER zmallwood@proton.me

RUN mkdir -p /app

COPY ./bin_server /app

WORKDIR /app

RUN apt-get update

EXPOSE 80
EXPOSE 1238

CMD ["./Server"]

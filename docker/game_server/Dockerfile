FROM ubuntu:latest
MAINTAINER zmallwood@proton.me

RUN mkdir -p /app

COPY ./bin_server /app

WORKDIR /app

RUN apt-get update
RUN apt-get install -y libsoci-core4.0
RUN apt-get install -y libsoci-postgresql4.0

EXPOSE 1238

CMD ["./Server"]

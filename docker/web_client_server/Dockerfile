FROM ubuntu:latest
MAINTAINER zmallwood@proton.me

RUN mkdir -p /app

COPY ./bin_web_client /app

WORKDIR /app

RUN apt-get update
RUN apt-get -y install python2

EXPOSE 80

CMD ["python2", "-m", "SimpleHTTPServer", "80"]

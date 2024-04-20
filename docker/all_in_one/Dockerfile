#This is a sample Image
FROM ubuntu:latest
MAINTAINER zmallwood@proton.me

RUN mkdir -p /app

#RUN chmod 500 /app

COPY ./bin_server /app
COPY ./bin_web_client /app
COPY ./repository/docker/all_in_one/run_servers.sh /app

WORKDIR /app

RUN apt-get update
RUN apt-get -y install python2

EXPOSE 80
EXPOSE 1238

#RUN creaster user blablaba

#USER blablabla

CMD ["./run_servers.sh"]

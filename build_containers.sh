cd ..
sudo docker build -t jod.web_client_server:0.1 -f repository/docker/web_client_server/Dockerfile .
sudo docker build -t jod.server:0.1 -f repository/docker/server/Dockerfile .

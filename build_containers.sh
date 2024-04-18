cd ..
sudo docker build -t jod.client:0.1 -f repository/docker/client/Dockerfile .
sudo docker build -t jod.server:0.1 -f repository/docker/server/Dockerfile .

#sudo docker build -t jod.all_in_one:latest -f repository/docker/all_in_one/Dockerfile .
sudo docker build -t jod.web_client_server:latest -f docker/web_client_server/Dockerfile .
sudo docker build -t jod.game_server:latest -f docker/game_server/Dockerfile .

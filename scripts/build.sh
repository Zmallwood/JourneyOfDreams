./build_web_client.sh &&
./build_server.sh &&
./build_world_generator.sh &&
cd ..
sudo docker build -t jod.web_client_server:latest -f docker/web_client_server/Dockerfile . &&
sudo docker build -t jod.game_server:latest -f docker/game_server/Dockerfile .

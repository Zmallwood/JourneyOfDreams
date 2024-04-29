# Build web_client_server
source ~/temp/emsdk/emsdk_env.sh &&
cd .. &&
CC=emcc CXX=em++ cmake projects/web_client -B build_web_client &&
cd build_web_client
emmake make &&
mv ../bin_web_client/WebClient.html ../bin_web_client/index.html &&

# Build game_server
cd .. &&
cmake projects/server -B build_server &&
cd build_server &&
cmake --build . --parallel 6 &&

# Build WorldGenerator
cd .. &&
cmake projects/world_generator -B build_world_generator &&
cd build_world_generator &&
cmake --build . --parallel 6 &&

# Build docker images
cd .. &&
sudo docker build --no-cache -t jod.web_client_server:latest -f docker/web_client_server/Dockerfile . &&
sudo docker build --no-cache -t jod.game_server:latest -f docker/game_server/Dockerfile .

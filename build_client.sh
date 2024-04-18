source ~/temp/emsdk/emsdk_env.sh &&
CC=emcc CXX=em++ cmake project/client -B ../build_client &&
cd ../build_client &&
emmake make
#cmake --build . --parallel 6

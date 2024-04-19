source ~/temp/emsdk/emsdk_env.sh &&
CC=emcc CXX=em++ cmake project/web_client -B ../build_web_client &&
cd ../build_web_client &&
emmake make
#cmake --build . --parallel 6

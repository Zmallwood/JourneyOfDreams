cd ..
cmake projects/server -B build_server &&
cd build_server &&
cmake --build . --parallel 6

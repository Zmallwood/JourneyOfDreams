cd ..
cmake project/map_generator -B build_map_generator &&
cd build_map_generator &&
cmake --build . --parallel 6

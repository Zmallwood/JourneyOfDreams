cd ..
cmake projects/world_generator -B build_world_generator &&
cd build_world_generator &&
cmake --build . --parallel 6

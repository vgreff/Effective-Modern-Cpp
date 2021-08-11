rm -rf build
mkdir build && cd build
conan install ..
cmake .. -G "Unix Makefiles"
cmake --build . -- -j 4

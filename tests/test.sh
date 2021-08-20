cmake -S . -B build
ctest --build build
cd build && ctest
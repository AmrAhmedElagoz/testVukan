rmdir /S /Q build
mkdir build
cd build
cmake ..
cmake --build . --config Release
.\Release\testVulkan.exe
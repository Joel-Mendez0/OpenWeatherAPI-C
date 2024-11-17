# OpenWeather API in C

## Building and Running the Project

### Cloning the Repository

```bash
git clone https://github.com/Joel-Mendez0/OpenWeatherAPI-C.git OpenWeatherAPI
cd OpenWeatherAPI
```
### Linux

On Linux: Install libcurl and CMake using the following commands:
```bash
sudo apt-get update
sudo apt-get install libcurl4-openssl-dev cmake
```
After libcurl is installed, you can build and run the program with the following commands:
```bash
mkdir build
cd build
cmake ..
make
./OpenWeatherAPI
```
### Windows
On Windows: You can download and build libcurl manually or use package managers like vcpkg or Conan:
```bash
vcpkg install curl
```
Make sure to add the appropriate toolchain file to your CMake command if using vcpkg:
```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=<path-to-vcpkg>/scripts/buildsystems/vcpkg.cmake
```
After libcurl is installed, you can build and run the program with the following commands:
```bash
mkdir build
cd build
cmake ..
cmake --build .
OpenWeatherAPI.exe
```


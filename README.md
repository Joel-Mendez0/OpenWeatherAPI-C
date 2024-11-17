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
On Windows: You can download and build libcurl manually from the curl repository https://github.com/curl/curl or use package managers like vcpkg or Conan. If you do not have either installed you may follow these steps using vcpkg:
```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg install curl
```
After you have vcpkg installed, along with curl, clone the project and perform the following commands: 
```bash
git clone https://github.com/Joel-Mendez0/OpenWeatherAPI-C.git OpenWeatherAPI
cd OpenWeatherAPI
mkdir build
cd build
```
After you are in the build directory, make sure when building the project with CMake to specify the vcpkg toolchain with the appropiate directory (enter this manually)
```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=(Your vcpkg install directory)\vcpkg\scripts\buildsystems\vcpkg.cmake
cmake --build .
```
After everything is built, enter the directory where the executable is located and run it!
```bash
cd Debug
OpenWeatherAPI.exe

```


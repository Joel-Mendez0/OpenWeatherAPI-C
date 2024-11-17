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
After you are in the build directory, make sure when building the project with CMake to specify the vcpkg toolchain with the appropiate directory (enter this manually). If you do not have CMake installed and added to your path, go to https://cmake.org/download/ and install the binaries installer for CMake and continue.
```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=(Your vcpkg install directory)\vcpkg\scripts\buildsystems\vcpkg.cmake
cmake --build .
```
After everything is built, enter the directory where the executable is located and run it!
```bash
cd Debug
OpenWeatherAPI.exe

```
## Application Overview

This is a simple console-based weather application that allows users to search for the current weather in different cities, save favorite cities, and view the weather for those saved cities. The application interacts with the [OpenWeatherMap API](https://openweathermap.org/) to fetch weather data.

## Features 

### 1. **Search City Weather**
   - Allows the user to input the name of any city to fetch and display the current weather information.

### 2. **Display Favourite Cities**
   - Lists all cities saved as favorites, showing either the city name or a message indicating that the slot is empty.

### 3. **Update Favourite Cities**
   - Users can manage their list of favorite cities:
     - **Add**: Add a new city to a selected slot.
     - **Remove**: Remove a city from a selected slot.
     - **Return to Main Menu**: Exit the editing menu.

### 4. **Display Favourite Cities Weather**
   - Displays the weather for all cities saved as favorites. For each city in the list, weather data is fetched and shown.

### 5. **Quit**
   - Exits the application and frees up any memory allocated during the session.

cmake_minimum_required(VERSION 3.10)
project(OpenWeatherAPI)

# Add the source files
set(SOURCES
    src/main.c
    src/weather_app.c
)

# Find the curl library
find_package(CURL REQUIRED)

# Add the executable
add_executable(OpenWeatherAPI ${SOURCES})

# Link curl library
target_link_libraries(OpenWeatherAPI CURL::libcurl)

# Include directories
target_include_directories(OpenWeatherAPI PRIVATE ${CURL_INCLUDE_DIRS} include)

#ifndef WEATHER_APP_H
#define WEATHER_APP_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

// Max settings and API key
#define MaxFavouriteCount 3
#define MaxCityNameLength 100
extern const char* APIkey;  // API key for weather requests

// Favourite Cities List
extern char* FavouriteCitiesList[MaxFavouriteCount];

// Enum for the main menu options
enum MainMenu {
    Search = 1,
    List = 2,
    Update = 3,
    ListWeather = 4,
    Exit = 5
};

// Enum for the update menu options (Add/Remove a city)
enum UpdateMenu {
    Add = 1,
    Remove = 2,
    ReturnMainMenu = 3
};

// Function prototypes

// Main application loop
void App(void);

// Weather-related functions
void SearchCityWeather(void);
void SearchCityWeatherFavourites(void);
void FetchWeatherData(const char* City, const char* APIkey);
size_t WriteCallback(void* Ptr, size_t Size, size_t NumElementsBytes, char* Data);

// Favourite Cities management
void UpdateFavouriteCities(void);
void ListFavouriteCities(void);
void AddCity(uint32_t Slot);
void RemoveCity(uint32_t Slot);

// User input prompts
// Parameters for these functions are passed by referenced to be able to manipulate for the application flow based on user input
void PromptUserMenu(uint32_t* Selection);
void PromptUserEdit(uint32_t* Slot, uint32_t* Selection);
void PromptUserCityWeather(char* City);

// Helper functions
void ReplaceSpacesWithPlus(char* str); // Necessary to have places seperate by spaces like New York to be transformed to New+York for the url
void Quit(void); // Free all memory consumed by the program and exits the application

#endif // WEATHER_APP_H

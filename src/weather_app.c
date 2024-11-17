#include "weather_app.h"

const char* APIkey = "fe30d707d67d0f786ee0975bea98975c";

char* FavouriteCitiesList[MaxFavouriteCount] = { NULL };

void App(void)
{
    bool Done = false;
    uint32_t selection;
    while (!Done) {
        PromptUserMenu(&selection);

        while (getchar() != '\n');

        switch (selection) {
        case Search:
            SearchCityWeather();
            break;
        case List:
            ListFavouriteCities();
            break;
        case Update:
            UpdateFavouriteCities();
            break;
        case ListWeather:
            SearchCityWeatherFavourites();
            break;
        case Exit:
            Quit();
            Done = true;
            break;
        default:
            break;
        }
    }
}

void SearchCityWeather(void)
{
    char City[MaxCityNameLength];  // Allocate space for the city name input by the user

    // Prompt user for city name
    PromptUserCityWeather(City);

    // Fetch weather data for the entered city
    FetchWeatherData(City, APIkey);
}

void SearchCityWeatherFavourites(void)
{
    printf("\n");
    for (uint8_t CitySlot = 0; CitySlot < MaxFavouriteCount; CitySlot++) {
        if (FavouriteCitiesList[CitySlot] == NULL) {
            printf("No City Data for slot %u\n", CitySlot + 1);
            continue;
        }
        FetchWeatherData(FavouriteCitiesList[CitySlot], APIkey);
        printf("\n");
    }
    printf("\n");
}

void FetchWeatherData(const char* City, const char* APIkey)
{
    CURL* curl;
    CURLcode res;

    char url[256];
    snprintf(url, sizeof(url), "http://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s", City, APIkey);

    printf("http://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s", City, APIkey);

    curl = curl_easy_init();
    if (curl) {

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    printf("\n");
}

size_t WriteCallback(void* Ptr, size_t Size, size_t NumElementsBytes, char* Data)
{
    size_t DataLength = Size * NumElementsBytes;

    fwrite(Ptr, Size, NumElementsBytes, stdout);

    return DataLength;
}

void UpdateFavouriteCities(void)
{
    uint32_t Slot;
    uint32_t Selection;

    ListFavouriteCities();
    PromptUserEdit(&Slot, &Selection);

    switch (Selection) {
    case Add:
        AddCity(Slot);
        break;

    case Remove:
        RemoveCity(Slot);
        break;

    case ReturnMainMenu:
        printf("Returning to Main Menu...\n\n");
        break;

    default:
        break;
    }
}

void ListFavouriteCities(void)
{
    printf("Favourite Cities: \n\n");
    for (uint8_t i = 0; i < MaxFavouriteCount; i++) {
        if (FavouriteCitiesList[i] == NULL) {
            printf("City %u: (Empty)\n", i + 1);
        }
        else {
            printf("City %u: %s\n", i + 1, FavouriteCitiesList[i]);
        }
    }
    printf("\n");
}

void AddCity(uint32_t Slot)
{

    // Allocate memory for the city name
    FavouriteCitiesList[Slot - 1] = (char*)malloc(MaxCityNameLength * sizeof(char));
    if (FavouriteCitiesList[Slot - 1] == NULL) {
        printf("Memory allocation failed\n\n");
        return;
    }

    printf("Input name of City %u: ", Slot);
    if (scanf("%99[^\n]", FavouriteCitiesList[Slot - 1]) != 1) {
        printf("\nFailed to Add City\n\n");
        free(FavouriteCitiesList[Slot - 1]);
        FavouriteCitiesList[Slot - 1] = NULL;
        return;
    }
    ReplaceSpacesWithPlus(FavouriteCitiesList[Slot - 1]);
    printf("City added successfully!\n\n");
    ListFavouriteCities();
}

void RemoveCity(uint32_t Slot)
{
    if (FavouriteCitiesList[Slot - 1] != NULL) {
        free(FavouriteCitiesList[Slot - 1]);
        FavouriteCitiesList[Slot - 1] = NULL;
        printf("City in slot %u deleted successfully!\n\n", Slot);
    }
    else {
        printf("No city to delete in slot %u.\n\n", Slot);
    }
}

void PromptUserMenu(uint32_t* Selection)
{
    while (1) {  // Loop until valid input is provided
        printf("1. Search City Weather\n");
        printf("2. Display Favourite Cities\n");
        printf("3. Update Favourite Cities\n");
        printf("4. Display Favourite Cities Weather\n");
        printf("5. Quit\n");
        printf("\nInput the number corresponding to the action you wish to perform: ");

        if (scanf("%u", Selection) == 1 && *Selection >= 1 && *Selection <= 5) {
            break;  // Valid input; exit loop
        }
        else {
            printf("Invalid Input! Try again with a valid option.\n\n");
            while (getchar() != '\n');  // Clear input buffer
        }
    }
    printf("\n");
}

void PromptUserEdit(uint32_t* Slot, uint32_t* Selection)
{
    // Loop for selecting a slot
    while (1) {
        printf("Select City Slot to Edit (1-%d):\n", MaxFavouriteCount);
        if (scanf("%u", Slot) == 1 && *Slot >= 1 && *Slot <= MaxFavouriteCount) {
            break;  // Valid input; exit loop
        }
        else {
            printf("Invalid Input! Please select a slot between 1 and %d.\n\n", MaxFavouriteCount);
            while (getchar() != '\n');  // Clear input buffer
        }
    }
    while (getchar() != '\n');  // Consume newline left by scanf

    printf("\nYou have selected slot %u\n\n", *Slot);

    // Loop for editing options
    while (1) {
        printf("1. Change City\n");
        printf("2. Delete\n");
        printf("3. Main Menu\n");
        printf("\nInput the number corresponding to the action you wish to perform: ");
        if (scanf("%u", Selection) == 1 && *Selection >= 1 && *Selection <= 3) {
            break;  // Valid input; exit loop
        }
        else {
            printf("Invalid Input! Please select a valid option (1-3).\n\n");
            while (getchar() != '\n');  // Clear input buffer
        }
    }
    while (getchar() != '\n');  // Consume newline left by scanf
}

void PromptUserCityWeather(char* City)
{
    // Ask user for a city name
    printf("Enter the name of the city to search for weather: ");

    if (scanf("%99[^\n]", City) != 1) {
        printf("Invalid city name. Try again.\n");

        while (getchar() != '\n');
    }
    printf("\n");
}

void ReplaceSpacesWithPlus(char* str)
{
    while (*str != '\0') {
        if (*str == ' ') {
            *str = '+';
        }
        str++;
    }
}

void Quit(void)
{
    for (int i = 0; i < MaxFavouriteCount; i++) {
        if (FavouriteCitiesList[i] != NULL) {
            free(FavouriteCitiesList[i]);
        }
    }
    printf("Closing!\n");
}

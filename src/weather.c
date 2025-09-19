#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "libs/weather.h"
#include "libs/http.h"

void welcomeUser(void)
{
    printf("Welcome to the Weather Information App!\n");
    printf("These are the cities that you can choose from in our program: \n\n");
}


void weatherMenu(cityStruct *cities, int cityCount)
{
    int choice;
    cityStruct *selectedCity = NULL;

    while (1) 
    {
        printf("\nChoose a city number (1-%d) or type '0' to end the program: ", cityCount);
        if(scanf("%d", &choice) != 1)
        {
            printf("\nInvalid choice!\n");
            while (getchar() != '\n');
            continue;
        }
        if(choice == 0) 
        {
            printf("\n\n---------- Ending the program! ----------\n\n---------- Thank you for using our Weather Information App. ----------\n\n---------- Have a wonderful day! ----------\n");
            break;
        }
        if(choice < 1 || choice > cityCount) 
        {
            printf("\nERROR: The city number you have provided does not exist!\nTry Again!\n");
            continue;
        }
        selectedCity = &cities[choice-1];
        
        JasonInfo weatherData;
        if (getWeatherData(selectedCity->url, &weatherData) == 0) 
        {
            printf("\nJSON-data for %s:\n%s\n", selectedCity->name, weatherData.data);
            parseWeatherJSON(weatherData.data);
            free(weatherData.data);
        } 
        else 
        {
            printf("\nFailed retrieving data for %s.\n", selectedCity->name);
        }
    }
}

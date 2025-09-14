#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "libs/weather.h"
#include "libs/http.h"

void weatherMenu(cityStruct *cities, int cityCount)
{
    char choice[50];

    while (1) 
    {
        printf("\nChoose a city or type 'exit' to end the program: ");
        scanf("%49s", choice);

        if (strcmp(choice, "exit") == 0) 
        {
            printf("Ending the program!\n\nThank you for using our Weather Information App.\n\nHave a wonderful day!\n");
            break;
        }

        choice[0] = toupper(choice[0]);
        int i;
        for (i = 1; choice[i] != '\0'; i++) 
        {
            choice[i] = tolower(choice[i]);
        }

        cityStruct *selectedCity = NULL;
        for (i = 0; i < cityCount; i++) 
        {
            if (strcmp(choice, cities[i].name) == 0) 
            {
                selectedCity = &cities[i];
                break;
            }
        }

        if (!selectedCity) 
        {
            printf("ERROR: The name of the city you have entered is not in the list!\nTry Again!\n");
            continue;
        }

        JasonInfo weatherData;
        if (getWeatherData(selectedCity->url, &weatherData) == 0) 
        {
            printf("\nJSON-data for %s:\n%s\n", selectedCity->name, weatherData.data);
            free(weatherData.data);
        } 
        else 
        {
            printf("Failed retrieving data for %s.\n", selectedCity->name);
        }
    }
}

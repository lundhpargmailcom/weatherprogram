#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cities.h"
#include "weather.h"
#include "libs/http.h"

void welcomeUser()
    {
        printf("Welcome to the Weather Information App!\n");
        printf("Cities to choose from:\n\n");    
    }

int weather(httpStruct* h)
{       
    const char* temp = "https://api.open-meteo.com/v1/forecast?latitude=%lf&longitude=%lf&current_weather=true";
    
    listCities();

    char choice[50];
    double lat, lon;

    while(1)
    {
        printf("\nSelect a city (Or type 'exit' to end the program): ");
        scanf("%49s", choice);

        
        if (strcmp(choice, "exit") == 0) 
        {
            printf("Ending the program!\n");
            return -1;
        }

        choice[0] = toupper(choice[0]);
        int i = 0;
        for (i = 1 ; choice[i] != '\0'; i++)
        {
            choice[i] = tolower(choice[i]);
        }             

        if(!findCity(choice, &lat, &lon)) 
        {
            printf("ERROR!: The name of the city you have entered is not in the list!\n\nPlease try again!\n");
            continue;
        }

        sprintf(h->url, temp, lat, lon);
        printf("Generated URL: %s\n", h->url);
        continue;        
    }
    return 1;
}
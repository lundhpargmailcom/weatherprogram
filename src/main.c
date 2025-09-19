#include <stdio.h>
#include <curl/curl.h>
#include "libs/cities.h"
#include "libs/weather.h"

int main()
{
    if (curl_global_init(CURL_GLOBAL_DEFAULT) != CURLE_OK) 
    {
        fprintf(stderr, "Could not initialize libcurl.\n");
        return -1;
    }

    welcomeUser();
    
    cityStruct cities[MAX_CITIES];
    int cityCount = listCities(cityData, cities, MAX_CITIES);    
    int i;
    for (i = 0; i < cityCount; i++) 
    {
        printf("%d. %s\n", i + 1, cities[i].name);
    }

    weatherMenu(cities, cityCount);

    curl_global_cleanup();
    return 0;
}

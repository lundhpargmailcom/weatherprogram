#include <stdio.h>
#include <curl/curl.h>
#include "libs/data.h"
#include "libs/weather.h"
#include "libs/welcome.h"

int main()
{
    if (curl_global_init(CURL_GLOBAL_DEFAULT) != 0) 
    {
        fprintf(stderr, "Could not initialize libcurl.\n");
        return -1;
    }

    cityStruct cities[MAX_CITIES];
    int cityCount = listCities(cityData, cities, MAX_CITIES);

    welcomeUser();

    int i;
    for (i = 0; i < cityCount; i++) 
    {
        printf("%d. %s\n", i + 1, cities[i].name);
    }

    weatherMenu(cities, cityCount);

    curl_global_cleanup();
    return 0;
}

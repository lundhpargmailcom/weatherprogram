#include <stdlib.h>
#include <string.h>
#include "libs/data.h"
#include <stdio.h>

const char *cityData =
    "Stockholm:59.3293:18.0686\n"
    "Göteborg:57.7089:11.9746\n"
    "Malmö:55.6050:13.0038\n"
    "Uppsala:59.8586:17.6389\n"
    "Västerås:59.6099:16.5448\n"
    "Örebro:59.2741:15.2066\n"
    "Linköping:58.4109:15.6216\n"
    "Helsingborg:56.0465:12.6945\n"
    "Jönköping:57.7815:14.1562\n"
    "Norrköping:58.5877:16.1924\n"
    "Lund:55.7047:13.1910\n"
    "Gävle:60.6749:17.1413\n"
    "Sundsvall:62.3908:17.3069\n"
    "Umeå:63.8258:20.2630\n"
    "Luleå:65.5848:22.1567\n"
    "Kiruna:67.8558:20.2253\n";


int listCities(const char *data, cityStruct *cities, int maxCities)
{
    int count = 0;
    const char *ptr = data;

    while (*ptr != '\0' && count < maxCities) 
    {
        char line[100];
        int i = 0;

        while (*ptr != '\n' && *ptr != '\0' && i < (int)sizeof(line) - 1) 
        {
            line[i++] = *ptr++;
        }
        line[i] = '\0';

        if (*ptr == '\n') ptr++;

        if (strlen(line) == 0) continue;

        char name[50];
        double lat, lon;

        if (sscanf(line, "%49[^:]:%lf:%lf", name, &lat, &lon) == 3) 
        {
            strncpy(cities[count].name, name, sizeof(cities[count].name));
            cities[count].latitude = lat;
            cities[count].longitude = lon;

            snprintf(cities[count].url, sizeof(cities[count].url), 
                "https://api.open-meteo.com/v1/forecast?latitude=%lf&longitude=%lf&current_weather=true", lat, lon);
            count++;

        } else 
        {
            fprintf(stderr, "Incorrect data: %s\n", line);
        }
    }

    return count;
}

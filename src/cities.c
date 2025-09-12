#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cities.h"

const char *cities =                                /*Can I make this look a bit cleaner? Maybe put it into it's own file? I chose now to put all the info on one line, because the 16 cities took up too much space.*/
    "Stockholm:59.3293:18.0686\n" "Göteborg:57.7089:11.9746\n" "Malmö:55.6050:13.0038\n" "Uppsala:59.8586:17.6389\n" "Västerås:59.6099:16.5448\n" "Örebro:59.2741:15.2066\n" "Linköping:58.4109:15.6216\n" "Helsingborg:56.0465:12.6945\n" "Jönköping:57.7815:14.1562\n" "Norrköping:58.5877:16.1924\n" "Lund:55.7047:13.1910\n" "Gävle:60.6749:17.1413\n" "Sundsvall:62.3908:17.3069\n" "Umeå:63.8258:20.2630\n" "Luleå:65.5848:22.1567\n" "Kiruna:67.8558:20.2253\n";

void listCities(void) 
{
    const char* search = cities;
    char name[20];

    while (*search != '\0') 
    {
        sscanf(search, "%19[^:]", name);
        printf("%s\n", name);

        search = strchr(search, '\n');
        if (search == NULL) 
        break;
        search++;
    }
}

int findCity(const char* choice, double* lat, double* lon) {
    const char* search = cities;
    char name[20];

    while (*search != '\0') {
        sscanf(search, "%19[^:]:%lf:%lf", name, lat, lon);

        if (strcmp(choice, name) == 0) {
            return 1;
        }

        if ((search = strchr(search, '\n')) == NULL)
            break;
        search++;

    }   

    return 0;
}

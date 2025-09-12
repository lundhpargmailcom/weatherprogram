#ifndef __cities_
#define __cities_

extern const char *cities;

typedef struct                              /*I need to use a struct for a cleaner code*/
{
    char name[25];
    char listName[25];
    double latitude;
    double longitude;
    char url[250];
} cityStruct;

void listCities(void);

int findCity(const char* choice, double* lat, double* lon);

#endif
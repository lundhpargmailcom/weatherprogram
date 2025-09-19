#ifndef CITIES_H
#define CITIES_H

#define MAX_CITIES 20

typedef struct 
{
    char name[50];       
    double latitude;     
    double longitude;    
    char url[250];       
} cityStruct;

extern const char *cityData;

int listCities(const char *data, cityStruct *cities, int maxCities);

#endif

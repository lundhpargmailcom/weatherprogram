#ifndef HTTP_H
#define HTTP_H

#include <stddef.h>

typedef struct 
{
    char *data;
    size_t size;
} JasonInfo;

int getWeatherData(const char *url, JasonInfo *response);

#endif

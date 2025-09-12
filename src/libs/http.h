#ifndef __http_
#define __http_

#include <stdbool.h>

typedef struct
{
    bool temp;
    char url[200];
} httpStruct;

int http_init(httpStruct *h);

void welcomeUser();                     /*Cleaned this up a bit, I used to have three header-files, but that felt a bit excessive*/

int weather(httpStruct* h);

/*void http_dispose(httpStruct *h);*/           /*Not really sure what to do with this*/

#endif
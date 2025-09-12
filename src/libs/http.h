#ifndef __http_
#define __http_

#include <stdbool.h>

typedef struct
{
    bool temp;
    char url[200];
} httpStruct;

int http_init(httpStruct *h);

void welcomeUser();                     /*Do I really need three different h-files, or should I clean it up a little bit?*/
                                        /*This looks a bit empty, maybe squish it into one of the other headers with all the functions gathered?*/

int weather(httpStruct* h);

/*void http_dispose(httpStruct *h);*/           /*Not really sure what to do with this*/

#endif
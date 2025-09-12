#ifndef __weather_
#define __weather_

#include "libs/http.h"

void welcomeUser();                     /*Do I really need three different h-files, or should I clean it up a little bit?*/
                                        /*This looks a bit empty, maybe squish it into one with all the functions?*/

int weather(httpStruct* h);

#endif
#include <stdio.h>
#include <string.h>
#include "libs/http.h"

int main()
{
    
    welcomeUser();

    httpStruct h;
    h.temp = false;    
    if(weather(&h) != 0)
    { 
        printf("Failed to get weather link.\n");
        return -1;
    }

    http_init(&h);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "libs/http.h"


static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    JasonInfo *mem = (JasonInfo *)userp;

    char *ptr = realloc(mem->data, mem->size + realsize + 1);
    if (ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 0;
    }

    mem->data = ptr;
    memcpy(&(mem->data[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->data[mem->size] = '\0';

    return realsize;
}

int getWeatherData(const char *url, JasonInfo *response)
{
    CURL *curl = curl_easy_init();
    if (!curl) 
    {
        fprintf(stderr, "Could not initialize CURL.\n");
        return -1;
    }

    response->data = malloc(1);
    if (!response->data)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        curl_easy_cleanup(curl);
        return -1;
    }
    response->size = 0;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        fprintf(stderr, "CURL request failed: %s\n", curl_easy_strerror(res));
        free(response->data);
        response->data = NULL;
        response->size = 0;
        curl_easy_cleanup(curl);
        return -1;
    }

    curl_easy_cleanup(curl);
    return 0;
}
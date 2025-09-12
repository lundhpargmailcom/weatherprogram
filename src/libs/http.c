#include <stdio.h>
#include <stdbool.h>
#include "http.h"
#include <curl/curl.h>

int http_init(httpStruct *h)
{
	h->temp = true;

	CURL* curl = curl_easy_init();
	if(curl == NULL)										/*Using NULL insted of curl != to prevent mistakes*/
	{
		printf("Failed to initialize CURL\n");
		return -1;
	}
	
	curl_easy_setopt(curl, CURLOPT_URL, h->url);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	CURLcode result = curl_easy_perform(curl);
	if(result != CURLE_OK)
	{
		printf("CURL request failed: %s\n", curl_easy_strerror(result));
		curl_easy_cleanup(curl);
		return -2;
	}
	
	curl_easy_cleanup(curl);

	printf("HTTP initialized\n");
	return 0;
}

/*void http_dispose(http *h)						Not sure what this does, look it up!
{
	h->temp = false;
}*/

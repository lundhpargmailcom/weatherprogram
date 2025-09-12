#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "http.h"
#include <curl/curl.h>

size_t got_data(char *buffer, size_t itemsize, size_t nitems, void* ignorethis){				/*Implementing the code from the video about libcurl to collect the data*/
	size_t bytes = itemsize + nitems;
	size_t linenumber = 1;																		/*Maybe I do no need this (linenumber), as of now I don't even output the data anyway.*/
	size_t i;
	printf("New chunk (%zu bytes)\n", bytes);
	for(i = 0; i < bytes; i++){
		printf("%c", buffer[i]);
		if (buffer[i] == '\n'){
			linenumber++;
			printf("%ld:\t", linenumber);
		}
	}
	printf("\n\n");
	return bytes;
}

int http_init(httpStruct *h)
{
	h->temp = true;

	CURL* curl = curl_easy_init();
	if(curl == NULL)										/*Using NULL insted of curl != to prevent mistakes*/
	{
		fprintf(stderr, "Failed to initialize CURL\n");
		return EXIT_FAILURE;
	}
	
	curl_easy_setopt(curl, CURLOPT_URL, h->url);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);

	CURLcode result = curl_easy_perform(curl);
	if(result != CURLE_OK)
	{
		fprintf(stderr, "CURL request failed: %s\n", curl_easy_strerror(result));
		curl_easy_cleanup(curl);
		return EXIT_FAILURE;
	}
	
	curl_easy_cleanup(curl);

	printf("HTTP initialized\n");
	return EXIT_SUCCESS;
}

/*void http_dispose(http *h)						Not sure what this does, look it up!
{
	h->temp = false;
}*/

#include <stdio.h>
#include "libs/cjson/cJSON.h"
#include "parse_weather.h"

void parseWeatherJSON(const char *jsonData) {
    cJSON *root = cJSON_Parse(jsonData);
    if (!root) {
        fprintf(stderr, "Error parsing JSON!\n");
        return;
    }

    cJSON *current = cJSON_GetObjectItem(root, "current_weather");
    if (!cJSON_IsObject(current)) {
        fprintf(stderr, "JSON missing 'current_weather'\n");
        cJSON_Delete(root);
        return;
    }

    cJSON *temp = cJSON_GetObjectItem(current, "temperature");
    cJSON *windspeed = cJSON_GetObjectItem(current, "windspeed");
    cJSON *winddir = cJSON_GetObjectItem(current, "winddirection");
    cJSON *time = cJSON_GetObjectItem(current, "time");

    if (cJSON_IsNumber(temp) && cJSON_IsNumber(windspeed) && cJSON_IsNumber(winddir) && cJSON_IsString(time)) {
        printf("\nCurrent weather:\n");
        printf("Temperature: %.1f °C\n", temp->valuedouble);
        printf("Wind speed: %.1f m/s\n", windspeed->valuedouble);
        printf("Wind direction: %.0f°\n", winddir->valuedouble);
        printf("Time: %s\n", time->valuestring);
    } else {
        printf("Error: Could get all the values out of JSON.\n");
    }

    cJSON_Delete(root);
}

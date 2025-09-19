This is a start to my weather information app.
A small project during our first weeks at CHAS Academy.

After a few tries to get the libcurl and json-parts to sync with my initial program, I just scrapped it all and reworked it from scratch to avoid annoying conflicts. Because it was getting rather messy in the code structure. There are still improvements to be made in a lot of places, but now I get the json-data to be output for the user based on the city they chose in the console.

Update 19/9: 
- Now I have implemented a function that parses the json-data through cjson and outputs the temperature, wind speed, wind direction and time from the selected city.
Added the cjson.h and cjson.c to a new created libs-folder and created a parse_weather.c and a parse_weather.h that implements the code necessary for the parsing.
- I have also made a few changes to the structure and changes a few names of both variables and functions. I'm never completely satisfied with the way the code is looking, so there will be more changes coming :)

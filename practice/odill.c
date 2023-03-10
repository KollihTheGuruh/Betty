#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

// callback function to receive the data obtained from the website
static size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    // process the data obtained from the website
    // in this example, we simply print it to the console
    printf("%.*s", (int)(size * nmemb), ptr);
    return size * nmemb;
}

int main()
{
    char Team1[50], Team2[50];

    printf("Enter Team1: ");
    scanf("%s", Team1);
    printf("Enter Team2: ");
    scanf("%s", Team2);

    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        char url[100];
        sprintf(url, "https://odibets.com/league/Results/%s-vs-%s", Team1, Team2);

        curl_easy_setopt(curl, CURLOPT_URL, url);

        // set the callback function to receive the data obtained from the website
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        // perform the request
        res = curl_easy_perform(curl);

        // check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // clean up the curl handle
        curl_easy_cleanup(curl);
    }

    // analyze the results and calculate the possible win
    // in this example, we simply set a fixed value for demonstration purposes
    char Possiblewin = 'H';

    printf("The possible win is: %c\n", Possiblewin);

    return 0;
}


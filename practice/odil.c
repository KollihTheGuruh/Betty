#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <libxml/parser.h>

// Function prototypes
int didTeamWin(char* team, int opponentIndex);
int didTeamLose(char* team, int opponentIndex);
void parse_html(char* html);

// Callback function for libcurl
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    // Write the response from the web server to stdout
    return fwrite(ptr, size, nmemb, stdout);
}

// Function to parse the HTML response using libxml2
void parse_html(char* html) {
    xmlDocPtr doc;
    xmlNodePtr node;

    // Parse the HTML string
    doc = htmlReadDoc((xmlChar*) html, NULL, "utf-8", XML_PARSE_RECOVER);
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse HTML\n");
        return;
    }

    // Traverse the DOM tree to find the relevant data
    node = xmlDocGetRootElement(doc);
    // TODO: Write code to traverse the DOM tree and extract the relevant data

    // Clean up
    xmlFreeDoc(doc);
}

int main()
{
    char *teams[] = {"Tottenham", "Liverpool", "West Ham", "Manchester Reds", "Aston V", "Leeds", "Brighton", "Southampton", "Wolves", "West Brom", "Sheffield U", "London Reds", "Burnley", "Palace", "Fulham", "Manchester Blue", "Leicester", "Everton", "Newcastle", "London Blues"};
    char team1[20], team2[20];
    int team1Index = -1, team2Index = -1;
    int opponents[19];
    int numOpponents = 0;
    int team1Wins = 0, team1Losses = 0, team1Draws = 0;
    int team2Wins = 0, team2Losses = 0, team2Draws = 0;
    float team1WinPercentage = 0.0, team1LossPercentage = 0.0, team1DrawPercentage = 0.0;
    float team2WinPercentage = 0.0, team2LossPercentage = 0.0, team2DrawPercentage = 0.0;

    // Prompt the user to enter the playing teams
    printf("Enter the first team: ");
    scanf("%s", team1);
    printf("Enter the second team: ");
    scanf("%s", team2);

    // Search the array of team names to find the index of the entered teams
    for (int i = 0; i < 20; i++) {
        if (strcmp(team1, teams[i]) == 0) {
            team1Index = i;
        }
        if (strcmp(team2, teams[i]) == 0) {
            team2Index = i;
        }
    }

    // If either team is not found in the array, print an error message and exit the program
    if (team1Index == -1 || team2Index == -1) {
        printf("One or more teams not found. Exiting...\n");
        return 0;
    }

    // Construct the URL to access the website
    char url[100];
    sprintf(url, "https://odibets.com/league" );

    // Initialize libcurl
    CURL *curl = curl_easy_init();
    if (!curl) {
       
// Create a libcurl handle for making the HTTP request
CURL *curl_handle = curl_easy_init();
if (curl_handle == NULL) {
    fprintf(stderr, "Failed to initialize libcurl\n");
    return 0;
}

// Set the URL to fetch and the callback function to handle the response
curl_easy_setopt(curl_handle, CURLOPT_URL, url);
curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);

// Perform the HTTP request and capture the response
CURLcode res = curl_easy_perform(curl_handle);
if (res != CURLE_OK) {
    fprintf(stderr, "Failed to fetch webpage: %s\n", curl_easy_strerror(res));
    return 0;
}

// Clean up the libcurl handle
curl_easy_cleanup(curl_handle);

// Parse the HTML response using libxml2
parse_html(html);

return 0;
}

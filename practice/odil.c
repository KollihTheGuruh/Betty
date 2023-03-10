#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

// Function prototypes
int didTeamWin(char* team, int opponentIndex); // Change opponent parameter to index of opponent in teams array
int didTeamLose(char* team, int opponentIndex); // Change opponent parameter to index of opponent in teams array

int main()
{
    char *teams[] = {"Tottenham", "Liverpool", "West Ham", "Manchester Reds", "Aston V", "Leeds", "Brighton", "Southampton", "Wolves", "West Brom", "Sheffield U", "London Reds", "Burnley", "Palace", "Fulham", "Manchester Blue", "Leicester", "Everton", "Newcastle", "London Blues"};
    char team1[20], team2[20];
    int team1Index = -1, team2Index = -1;
    int opponents[19];
    int numOpponents = 0;
    int team1Wins = 0, team1Losses = 0, team1Draws = 0; // Declare team1Win, team1Loss and team1Draw variables outside the loop
    int team2Wins = 0, team2Losses = 0, team2Draws = 0; // Declare team2Win, team2Loss and team2Draw variables outside the loop
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

    // Set up curl to retrieve the website data
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        char url[1000];
        sprintf(url, "https://odibets.com/leagueResults?team1=%s&team2=%s", teams[team1Index], teams[team2Index]);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    // Based on the indices of the entered teams, generate a list of the teams that the entered teams have played against previously
// Predict the outcome of the match based on the win percentages of the two teams
if (team1WinPercentage > team2WinPercentage) {
    printf("%s is predicted to win the match.\n", teams[team1Index]);
} else if (team2WinPercentage > team1WinPercentage) {
    printf("%s is predicted to win the match.\n", teams[team2Index]);
} else {
    printf("The match is predicted to end in a draw.\n");
}

return 0;
}

// Function definitions
int didTeamWin(char* team, int opponentIndex) {
// TODO: Implement logic to check if the team won against the specified opponent
// For now, return true for all opponents
return 1;
}

int didTeamLose(char* team, int opponentIndex) {
// TODO: Implement logic to check if the team lost to the specified opponent
// For now, return false for all opponents
return 0;
}

//Note that the code currently only predicts the outcome based on the win percentages of the two teams and does not take into account any information about the specific match that is being played. To make more accurate predictions, you will need to gather information about the teams and the match, such as their recent form, injuries, and other relevant factors. This information can be obtained by accessing a website or other data source and analyzing the data. Depending on the specific website or data source you use, you may need to modify the code to parse the data and extract the relevant information.







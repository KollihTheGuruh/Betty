#include <stdio.h>
#include <string.h>

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

    // Based on the indices of the entered teams, generate a list of the teams that the entered teams have played against previously
    for (int i = 0; i < 20; i++) {
        // Skip the entered teams
        if (i == team1Index || i == team2Index) {
            continue;
        }
        // Check if the current team has played against either team before
        if (didTeamWin(teams[team1Index], i)) { // Pass team name and index of opponent
            team1Wins++;
        } else if (didTeamLose(teams[team1Index], i)) { // Pass team name and index of opponent
            team1Losses++;
        } else {
            team1Draws++;
        }
        if (didTeamWin(teams[team2Index], i)) { // Pass team name and index of opponent
            team2Wins++;
        } else if (didTeamLose(teams[team2Index], i)) { // Pass team name and index of opponent
            team2Losses++;
        } else {
            team2Draws++;
        }
        // Add the index of the current team to the list of opponents
        opponents[numOpponents] = i;
        numOpponents++;
    }

    // Calculate the win, loss, and draw percentages for each team
    team1WinPercentage = (float) team1Wins / (float) (team1Wins + team1Losses + team1Draws) * 100.0;
    team1LossPercentage = (float) team1Losses / (float) (team1Wins + team1Losses + team1Draws) * 100.0;
    team1DrawPercentage = (float) team1Draws / (float) (team1Wins + team1Losses + team1Draws) * 100.0;
    team2WinPercentage = (float) team2Wins / (float) (team2Wins + team2Losses + team2Draws) * 100.0;
    team2LossPercentage = (float) team2Losses / (float) (team2Wins + team2Losses + team2Draws) * 100.0;
    team2DrawPercentage = (float) team2Draws / (float) (team2Wins + team2Losses + team2Draws) * 100.0;

    // Print the results
    printf("%s vs %s\n", teams[team1Index], teams[team2Index]);
    printf("%s win percentage: %.2f%%\n", teams[team1Index], team1WinPercentage);
    printf("%s loss percentage: %.2f%%\n", teams[team1Index], team1LossPercentage);
    printf("%s draw percentage: %.2f%%\n", teams[team1Index], team1DrawPercentage);
    printf("%s win percentage: %.2f%%\n", teams[team2Index], team2WinPercentage);
    printf("%s loss percentage: %.2f%%\n", teams[team2Index], team2LossPercentage);
    printf("%s draw percentage: %.2f%%\n", teams[team2Index], team2DrawPercentage);

    return 0;
}

// Function to check if a team won against an opponent
int didTeamWin(char* team, int opponentIndex) {
    // This function would contain the logic to check if the team won against the given opponent
    // For the purpose of this example, let's assume that the team always wins against the opponent
    return 1;
}

// Function to check if a team lost against an opponent
int didTeamLose(char* team, int opponentIndex) {
    // This function would contain the logic to check if the team lost against the given opponent
    // For the purpose of this example, let's assume that the team never loses against the opponent
    return 0;
}


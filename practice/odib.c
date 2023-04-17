#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATCHES 100
#define MAX_TEAMS 10

struct Match {
  int team1, team2;
  int score1, score2;
};

struct Team {
  int name;
  int num_wins;
  int num_losses;
  int num_ties;
};

int main(int argc, char *argv[]) {
  // Get the website URL
  char *website = argv[1];

  // Get the user input
  int team1 = atoi(argv[2]);
  int team2 = atoi(argv[3]);

  // Access the website and get the previous match results
  int num_matches = 0;
  struct Match matches[MAX_MATCHES];
  while (1) {
    // Get the next match result
    int score1, score2;
    char winner;
    int error = curl_fetch(website, "/api/v1/matches", matches + num_matches, &score1, &score2, &winner, NULL);
    if (error != 0) {
      printf("Error fetching match result: %d\n", error);
      break;
    }

    // If the match is finished, increment the num_matches counter
    if (winner != 'T') {
      num_matches++;
    }
  }

  // Get the teams' information
  struct Team teams[MAX_TEAMS];
  for (int i = 0; i < MAX_TEAMS; i++) {
    teams[i].name = "Team " + (i + 1);
    teams[i].num_wins = 0;
    teams[i].num_losses = 0;
    teams[i].num_ties = 0;
  }

  // Loop through the match results and update the teams' information
  for (int i = 0; i < num_matches; i++) {
    if (matches[i].team1 == team1) {
      teams[teams[team1 - 1].name].num_wins++;
    } else if (matches[i].team1 == team2) {
      teams[teams[team1 - 1].name].num_losses++;
    } else if (matches[i].team2 == team1) {
      teams[teams[team2 - 1].name].num_ties++;
    } else if (matches[i].team2 == team2) {
      teams[teams[team2 - 1].name].num_wins++;
    }
  }

  // Print the teams' information
  for (int i = 0; i < MAX_TEAMS; i++) {
    printf("%s: %d wins, %d losses, %d ties\n", teams[i].name, teams[i].num_wins, teams[i].num_losses, teams[i].num_ties);
  }

  // Calculate the teams' win-loss ratio
  for (int i = 0; i < MAX_TEAMS; i++) {
    teams[i].win_loss_ratio = teams[i].num_wins / (teams[i].num_wins + teams[i].num_losses);
  }

  // Calculate the teams' predicted outcome
  for (int i = 0; i < MAX_TEAMS; i++) {
    if (teams[i].win_loss_ratio > 0.5) {
      teams[i].predicted_outcome = 1;
    } else {
      teams[i].predicted_outcome = 0;
    }
  }

  // Print the teams' predicted outcome
  for (int i = 0; i < MAX_TEAMS; i++) {
    printf("%s: Predicted outcome: %d\n", teams[i].name, teams[i].predicted_outcome);
  }

  return 0;
}

#include <stdio.h>
#include <unistd.h>

#define RED "\033[31m"
#define RESET "\033[0m"

void print_slowly(char* text) {
  for (int i = 0; text[i] != '\0'; i++) {
    putchar(text[i]);
    fflush(stdout);
    usleep(50000); // sleep for 50 milliseconds
  }
}

int main() {
  char* text = "HAPPY WOMEN'S DAY";
  int max_col, max_row;
  printf("\033[2J"); // clear screen
  while (1) {
    printf("\033[%d;%dH%s%s%s\n", 10, 1, RED, text, RESET); // set cursor to row 10, column 1 and print text in red color
    usleep(50000); // sleep for 50 milliseconds
    printf("\033[2K"); // clear current line
    fflush(stdout);
    text++; // shift text to the right
    if (*text == '\0') text = "HAPPY WOMEN'S DAY"; // reset text when it reaches the end
    // get the terminal size
    printf("\033[6n"); // request cursor position
    scanf("\033[%d;%dR", &max_row, &max_col); // read cursor position response
    max_col -= 5; // adjust max_col to avoid text wrapping
    if (text - "HAPPY WOMEN'S DAY" >= max_col) {
      printf("\033[2J"); // clear screen
      text = "HAPPY WOMEN'S DAY"; // reset text to the beginning
    }
  }
  return 0;
}

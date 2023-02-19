#include <stdio.h>
#include <libxl.h>

int main(void) {
    int i, j, rows, cols;
    int math, eng, sci, sst, kisw, tot, avg;
    char student_name[50];

    // Create a new Excel book object
    Book* book = xlCreateBook();
    if (!book) {
        printf("Error: Failed to create book.\n");
        return 1;
    }

    // Load the Excel file
    if (!book->load("students_marks.xlsx")) {
        printf("Error: Failed to load file.\n");
        return 1;
    }

    // Get the number of rows and columns in the sheet
    Sheet* sheet = book->getSheet(0);
    if (!sheet) {
        printf("Error: Failed to get sheet.\n");
        return 1;
    }

    rows = sheet->lastRow();
    cols = sheet->lastCol();

    // Loop through the rows in the sheet
    for (i = 0; i < rows; i++) {
        // Get the name of the student from the first column
        student_name = sheet->readStr(i + 1, 0);

        // Reset the total and average
        tot = 0;
        avg = 0;

        // Loop through the columns in the sheet
        for (j = 1; j < cols; j++) {
            // Get the marks for each subject
            if (j == 1) eng = sheet->readNum(i + 1, j);
            if (j == 2) sci = sheet->readNum(i + 1, j);
            if (j == 3) sst = sheet->readNum(i + 1, j);
            if (j == 4) math = sheet->readNum(i + 1, j);
            if (j == 5) kisw = sheet->readNum(i + 1, j);

            // Calculate the total marks
            tot += eng + sci + sst + math + kisw;
        }

        // Calculate the average marks
        avg = (float)(tot) / (cols - 1);

        // Print the results
        printf("Name: %s\n", student_name);
        printf("English: %d\n", eng);
        printf("Science: %d\n", sci);
        printf("Social Studies: %d\n", sst);
        printf("Maths: %d\n", math);
        printf("Kiswahili: %d\n", kisw);
        printf("Total marks: %d\n", tot);
        printf("Average marks: %d\n\n", avg);
    }

    // Free the Excel book object
    book->release();

    return 0;
}

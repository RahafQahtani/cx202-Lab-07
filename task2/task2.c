#include <stdio.h>

int main() {
    FILE *file;
	   
    file = fopen("task2test.txt", "r");
    if (file == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }

    char ch;
    int chars = 0, words = 0, lines = 0;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        // Count characters excluding spaces and newline characters
        if (ch != ' ' && ch != '\n') {
            chars++;
        }

        // Count words
        if (ch == ' ' || ch == '\n') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }

        // Count lines
        if (ch == '\n') {
            lines++;
        }
    }

    fclose(file);

    // Display the results
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters (excluding spacing): %d\n", chars);

    return 0;
}


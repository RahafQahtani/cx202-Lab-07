#include <stdio.h>
#include <stdlib.h>

void caesar_cipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + shift + 26) % 26) + 'A';
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((text[i] - 'a' + shift + 26) % 26) + 'a';
    }
}

int main() {
    FILE *file, *outputFile;
    char data[1000], filename[100], choice, choice1;
    int shift;

    printf("Welcome to the Caesar Cipher Program!\n");
    printf("Do you want to perform (E)ncryption or (D)ecryption? ");
    scanf(" %c", &choice);

    // Set shift based on choice
    if (choice == 'E' || choice == 'e') {
        shift = 3;
    } else if (choice == 'D' || choice == 'd') {
        shift = -3;
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    // Ask if the user wants to use a file or string input
    printf("Do you want to use data from a (F)ile or enter a (S)tring? ");
    scanf(" %c", &choice1);

    if (choice1 == 'F' || choice1 == 'f') {
        // File input
        printf("Enter the file name to read: ");
        scanf("%s", filename);

        // Open the input file
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error! Could not open file.\n");
            return 1;
        }

        // Read the content of the file
        fgets(data, 1000, file);
        fclose(file);

        // Apply Caesar Cipher
        caesar_cipher(data, shift);

        // Open the output file based on the choice
        if (choice == 'E' || choice == 'e') {
            outputFile = fopen("encrypted.txt", "w");
            if (outputFile == NULL) {
                printf("Error! Could not open output file.\n");
                return 1;
            }
            fprintf(outputFile, "%s", data);
            fclose(outputFile);
            printf("The encrypted text has been saved to encrypted.txt\n");
        } else if (choice == 'D' || choice == 'd') {
            outputFile = fopen("decrypted.txt", "w");
            if (outputFile == NULL) {
                printf("Error! Could not open output file.\n");
                return 1;
            }
            fprintf(outputFile, "%s", data);
            fclose(outputFile);
            printf("The decrypted text has been saved to decrypted.txt\n");
        }

    } else if (choice1 == 'S' || choice1 == 's') {
        // String input
        if (shift == 3) {
            printf("Please enter the string to encrypt: ");
        } else if (shift == -3) {
            printf("Please enter the string to decrypt: ");
        }
        scanf(" %[^\n]", data);  

        // Apply Caesar Cipher
        caesar_cipher(data, shift);

        if (shift == 3) {
            printf("Encrypted string: %s\n", data);
        } else if (shift == -3) {
            printf("Decrypted string: %s\n", data);
        }
    } else {
        printf("Invalid option for file or string input!\n");
        return 1;
    }

    return 0;
}

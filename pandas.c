#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int checkArguments(int numOfArguments, char **cmdLineArguments);   // Difficulty: 2
int printFileNames(int numberOfFiles, char **fileNames);           // Difficulty: 1
int checkFileExists(char *fileName);                               // Difficulty: 2
int readFile(char *fileName);                                      // Difficulty: 3
int extractSample(char *fileName);                                 // Difficulty: 4

// Main function
int main(int argc, char **argv) {
    // Check if the correct number of arguments is passed
    if (checkArguments(argc, argv) != 1) {
        printf("Invalid number of arguments.\n");
        return 1;
    }

    // Check if the first file exists
    if (checkFileExists(argv[1]) != 1) {
        printf("File %s does not exist.\n", argv[1]);
        return 1;
    }

    // Print the file names
    printFileNames(argc - 1, &argv[1]);

    // Read the first file's contents
    readFile(argv[1]);

    // Extract a sample from the second file, if present
    if (argc >= 3) {
        extractSample(argv[2]);
    }

    return 0;
}

// Check if the number of arguments is correct
int checkArguments(int numOfArguments, char **cmdLineArguments) {
    if (numOfArguments >= 2) {
        printf("Arguments: true\n");
        return 1;
    } else {
        printf("Arguments: false\n");
        return 0;
    }
}

// Print the file names passed as arguments
int printFileNames(int numberOfFiles, char **fileNames) {
    for (int i = 0; i < numberOfFiles; i++) {
        printf("File Name: %s\n", fileNames[i]);
    }
    return 1;
}

// Check if a file exists
int checkFileExists(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file) {
        printf("File Exists: true\n");
        fclose(file);
        return 1;
    } else {
        printf("File Exists: false\n");
        return 0;
    }
}

// Read the contents of a file and print each character
int readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Could not open file %s\n", fileName);
        return 0;
    }

    char ch;
    printf("Name: ");
    while ((ch = fgetc(file)) != EOF) {
        // Print each character, handling newlines appropriately
        if (ch == '\n') {
            printf(" ");
        } else {
            printf("%c", ch);
        }
    }
    printf("\n");
    fclose(file);
    return 1;
}

// Extract and print lines with 6 or more characters
int extractSample(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Could not open file %s\n", fileName);
        return 0;
    }

    char line[100];
    int sampleCount = 1;
    while (fgets(line, sizeof(line), file)) {
        // Count the number of characters in the line
        int charCount = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            charCount++;
            // Stop counting if we hit a newline character
            if (line[i] == '\n') {
                break;
            }
        }

        // Check if the line has 6 or more characters
        if (charCount >= 6) {
            // Manually replace the newline character with a null terminator for printing
            line[charCount - 1] = '\0';  // This replaces the newline with null terminator
            printf("Sample %d: %s\n", sampleCount++, line);
        }
    }
    fclose(file);
    return 1;
}
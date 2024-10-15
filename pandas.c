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


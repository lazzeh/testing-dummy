//li767225
//Liborio collazo
#include <stdio.h>
#include <stdlib.h>

int checkArguments(int numOfArguments, char **cmdLineArguments);   
int printFileNames(int numberOfFiles, char **fileNames);           
int checkFileExists(char *fileName);                               
int readFile(char *fileName);                                     
int extractSample(char *fileName);                                

// Two arguments: one for checking the given arguments and one for checking if the file exists
int main(int argc, char **argv) 
{
    if (checkArguments(argc, argv) != 1) {
        printf("Invalid number of arguments.\n");
        return 1;
    }

    // Checking if the file exists
    if (checkFileExists(argv[1]) != 1) {
        printf("File %s does not exist.\n", argv[1]);
        return 1;
    }

    printFileNames(argc - 1, &argv[1]);

    readFile(argv[1]);

    // Grab a sample from the second file
    if (argc >= 3) {
        extractSample(argv[2]);
    }
    return 0;
}

// Check if the number of arguments is correct
int checkArguments(int numOfArguments, char **cmdLineArguments) 
{
    if (numOfArguments >= 2) {
        printf("Arguments: true\n");
    } else {
        printf("Arguments: false\n");
        return 0;  // Difficulty rating
    }
    return 1;  
}

// Print the file names as arguments
int printFileNames(int numberOfFiles, char **fileNames) 
{
    for (int i = 0; i < numberOfFiles; i++) {
        printf("File Name: %s\n", fileNames[i]);
    }
    return 1;  // Difficulty rating for printFileNames
}

// Check if the file exists
int checkFileExists(char *fileName) 
{
    FILE *file = fopen(fileName, "r");
    if (file) {
        printf("File Exists: true\n");
        fclose(file);
        return 1;
    } else {
        printf("File Exists: false\n");
        return 0;  // Difficulty rating
    }
    return 1;  // Difficulty rating for checkFileExists
}

// Read and print the contents of the file
int readFile(char *fileName) 
{
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Could not open file %s\n", fileName);
        return 0;  // Difficulty rating
    }

    char ch;
    printf("Name: ");
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            printf(" ");
        } else {
            printf("%c", ch);
        }
    }
    printf("\n");
    fclose(file);
    return 3;  // Difficulty rating for readFile
}

// Extract words of 6 or more characters, skipping samples when necessary
int extractSample(char *fileName) 
{
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Could not open file %s\n", fileName);
        return 0;  // Difficulty rating
    }

    char word[100];  // Buffer to hold each word
    int sampleCount = 1;  // Total sample counter

    // Reading the file word by word
    while (fscanf(file, "%s", word) != EOF) 
    {
        int charCount = 0;

        // Counting characters in the word
        for (int i = 0; word[i] != '\0'; i++) 
        {
            charCount++;
        }

        // Only print words with 6 or more characters
        if (charCount >= 6) 
        {
            printf("Sample %d: %s\n", sampleCount, word);
        }

        // Increment the sample count for every word, regardless of length
        sampleCount++;
    }

    fclose(file);
    return 5;  // Difficulty rating for extractSample
}
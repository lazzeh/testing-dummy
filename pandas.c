//li767225
//Liborio collazo
#include <stdio.h>
#include <stdlib.h>

int checkArguments(int numOfArguments, char **cmdLineArguments);   
int printFileNames(int numberOfFiles, char **fileNames);           
int checkFileExists(char *fileName);                               
int readFile(char *fileName);                                     
int extractSample(char *fileName);                                

//Two arguements one for checking the given aguments and one checking if the file exists
int main(int argc, char **argv) 
{
    if (checkArguments(argc, argv) != 1) {
        printf("Invalid number of arguments.\n");
        return 1;
    }

//Seeing if the file exists using this code
    if (checkFileExists(argv[1]) != 1) {
        printf("File %s does not exist.\n", argv[1]);
        return 1;
    }

    printFileNames(argc - 1, &argv[1]);

    readFile(argv[1]);

//Grab a sample from the second file
    if (argc >= 3) {
        extractSample(argv[2]);
    }
    return 0;
}

//Check if the number of arguments is true or false/ correct
int checkArguments(int numOfArguments, char **cmdLineArguments)
 {
    if (numOfArguments >= 2) {
        printf("Arguments: true\n");
        
    } else {
        printf("Arguments: false\n");
        return 0;
    }
    return 2;
}

//Print the file names as arugments using our given integers and info
int printFileNames(int numberOfFiles, char **fileNames) 
{
    for (int i = 0; i < numberOfFiles; i++) {
        printf("File Name: %s\n", fileNames[i]);
    }
    return 1;
}

//Check the file to see if it exists 
int checkFileExists(char *fileName) 
{
    FILE *file = fopen(fileName, "r");
    if (file) {
        printf("File Exists: true\n");
        fclose(file);
        
    } else {
        printf("File Exists: false\n");
        return 0;
    }
    return 2;
}

//Read the given info in the file and print the info by charecter trying to focus on the newlines with the guidelines in the assignment
int readFile(char *fileName) 
{
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Could not open file %s\n", fileName);
        return 0;
    }

    char ch;
    printf("Name: ");
    while ((ch = fgetc(file)) != EOF)
     {
        if (ch == '\n') {
            printf(" ");
        } else {
            printf("%c", ch);
        }
    }
    printf("\n");
    fclose(file);
    return 3;
}

//Grab lines or words from the files with 6 or more charecters, using a for loop and and stopping the counting once hitting a newline. 
int extractSample(char *fileName) 
{
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Could not open file %s\n", fileName);
        return 0;
    }

    char line[100];
    int sampleCount = 1;
    while (fgets(line, sizeof(line), file)) 
    {
        int charCount = 0;
        for (int i = 0; line[i] != '\0'; i++) 
        {
            if (line[i] != '\n') {
                charCount++;
            }
        }

        // Print lines with 6 or more characters
        if (charCount >= 6) 
        {
            printf("Sample %d: ", sampleCount++);  // Print sample number and increment
            for (int i = 0; line[i] != '\n' && line[i] != '\0'; i++) {
                printf("%c", line[i]);  // Print the line character by character
            }
            printf("\n");
        }
    }
    fclose(file);
    return 1;
}
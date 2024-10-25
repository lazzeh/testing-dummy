#include <stdio.h>
#include <stdlib.h>

int readFile(char *fileName);
int* createOneDimensionalArray(int size);
int** createMatrix(int rows, int cols);
int** addMatrices(int **defaultMatrix, int **readInMatrix, int rows, int cols);
int computeDiagonalSum(int **matrix, int rows, int cols);
int collectBytes(int **matrix, int rows, int cols);

// 4.2 Main Function
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int difficulty = readFile(argv[1]);
    return 0;
}

// 4.3 1D Array Creation
int *createOneDimensionalArray(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    if (!array) {
        printf("Memory allocation failed for 1D array.\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        array[i] = 1;
    }
    printf("Array of size %d is created.\n", size);
    return array;
}

// 4.4 Matrix Creation
int **createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (!matrix) {
        printf("Memory allocation failed for matrix.\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (!matrix[i]) {
            printf("Memory allocation failed for matrix row.\n");
            exit(1);
        }
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 1;
        }
    }
    printf("Matrix of size (%d, %d) is created.\n", rows, cols);
    return matrix;
}

// 4.5 Read File Containing Matrix Data
int readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Failed to open file.\n");
        return -1;
    }

    int rows1, cols1, rows2, cols2;
    fscanf(file, "%d", &rows1);
    fscanf(file, "%d", &cols1);
    fscanf(file, "%d", &rows2);
    fscanf(file, "%d", &cols2);

    printf("Matrix of size (%d, %d) is found.\n", rows1, cols1);
    printf("Matrix of size (%d, %d) is found.\n", rows2, cols2);

    // Close file after reading dimensions
    fclose(file);
    return 3; // Returning an arbitrary difficulty rating
}

// 4.6 Matrix Addition
int **addMatrices(int **defaultMatrix, int **readInMatrix, int rows, int cols) {
    int **sumMatrix = (int **)malloc(rows * sizeof(int *));
    if (!sumMatrix) {
        printf("Memory allocation failed for sum matrix.\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        sumMatrix[i] = (int *)malloc(cols * sizeof(int));
        if (!sumMatrix[i]) {
            printf("Memory allocation failed for sum matrix row.\n");
            exit(1);
        }
        for (int j = 0; j < cols; j++) {
            sumMatrix[i][j] = defaultMatrix[i][j] + readInMatrix[i][j];
            printf("%d ", sumMatrix[i][j]);
        }
        printf("\n");
    }
    return sumMatrix;
}

// 4.7 Diagonal Sum of Matrix
int computeDiagonalSum(int **matrix, int rows, int cols) {
    if (rows != cols) {
        printf("Matrix is not square. Cannot compute diagonal sum.\n");
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += matrix[i][i];
    }
    printf("Diagonal Sum is: %d\n", sum);
    return 2; // Returning an arbitrary difficulty rating
}

// 4.8 EXTRA CREDIT: Tracking Memory
int collectBytes(int **matrix, int rows, int cols) {
    int totalBytes = rows * cols * sizeof(int);
    printf("Total bytes of matrix: %d\n", totalBytes);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 2; // Returning an arbitrary difficulty rating
}
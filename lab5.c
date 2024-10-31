#include <stdio.h>
#include <string.h>

// Function to find string length
int string_length(char *str) {
    return strlen(str);
}

// Function to compare strings alphabetically
void compare_strings(char *str1, char *str2) {
    int cmp = strcmp(str1, str2);
    if (cmp < 0) {
        printf("%s comes before %s alphabetically\n", str1, str2);
    } else if (cmp > 0) {
        printf("%s comes after %s alphabetically\n", str1, str2);
    } else {
        printf("%s and %s are the same\n", str1, str2);
    }
}

// Function to concatenate strings
void concatenate_strings(char *str1, char *str2) {
    char result[100];  // Ensure this is large enough to hold both strings
    strcpy(result, str1);
    strcat(result, str2);
    printf("Concatenated string: %s\n", result);
}

// Function to reverse a string
void string_reverse(char *str) {
    int length = strlen(str);
    char reversed[length + 1];
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0';
    printf("Reversed string: %s\n", reversed);
}

int main() {
    char str1[50], str2[50];
    
    printf("Enter the first string: ");
    scanf("%49s", str1);
    printf("Enter the second string: ");
    scanf("%49s", str2);

    // Length of strings
    printf("Length of first string: %d\n", string_length(str1));
    printf("Length of second string: %d\n", string_length(str2));

    // Compare strings
    compare_strings(str1, str2);

    // Concatenate strings
    concatenate_strings(str1, str2);

    // Reverse strings
    printf("Reversed first string: ");
    string_reverse(str1);
    printf("Reversed second string: ");
    string_reverse(str2);

    return 0;
}
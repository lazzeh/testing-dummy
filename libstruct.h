#ifndef LIBSTRUCT_H
#define LIBSTRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct Definitions
typedef struct Book {
    char *title;
    char *author;
    int year;
    int isAvailable;
} Book;

typedef struct Library {
    Book *library[100];
    int count;
} Library;

// Function Prototypes
void addBook(Library *library, const char *title, const char *author, int year);
void removeBook(Library *library, const char *title, const char *author, int year);
void printLibrary(const Library *library);
Book *findBook(const Library *library, const char *title, const char *author, int year);
void checkoutBook(Library *library, const char *title, const char *author, int year);
void returnBook(Library *library, const char *title, const char *author, int year);

#endif // LIBSTRUCT_H
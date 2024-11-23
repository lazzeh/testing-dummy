#ifndef LIBSTRUCT_H
#define LIBSTRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 1024
#define MAX_AUTHOR_LENGTH 1024
#define MAX_LIBRARY_SIZE 100

typedef struct {
    char *title;
    char *author;
    int year;
    int isAvailable;
} Book;

typedef struct {
    Book *library[MAX_LIBRARY_SIZE];
    int count;
} Library;


void addBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear);
void removeBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear);
void printLibrary(Library *library);
Book *findBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear);
void checkoutBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear);
void returnBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear);

#endif 
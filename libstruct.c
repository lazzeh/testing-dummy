#include "libstruct.h"  

void addBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear) {
    if (library->count >= MAX_LIBRARY_SIZE) {
        printf("The library is full. Cannot add more books.\n");
        return;
    }

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->library[i]->title, bookTitle) == 0 &&
            strcmp(library->library[i]->author, bookAuthor) == 0 &&
            library->library[i]->year == bookYear) {
            printf("Book with title %s, author %s, and year %d is already in the library.\n",
                   bookTitle, bookAuthor, bookYear);
            return;
        }
    }

    Book *newBook = malloc(sizeof(Book));
    newBook->title = strdup(bookTitle);
    newBook->author = strdup(bookAuthor);
    newBook->year = bookYear;
    newBook->isAvailable = 1;

    library->library[library->count++] = newBook;

    printf("Book with title %s, author %s, and year %d added to the library.\n",
           bookTitle, bookAuthor, bookYear);
}

void removeBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear) {
    for (int i = 0; i < library->count; i++) {
        Book *book = library->library[i];
        if (book != NULL &&
            strcmp(book->title, bookTitle) == 0 &&
            strcmp(book->author, bookAuthor) == 0 &&
            book->year == bookYear) {
            free(book->title);
            free(book->author);
            free(book);
            library->library[i] = NULL;

            printf("Book with title %s, author %s, and year %d has been removed from the library.\n",
                   bookTitle, bookAuthor, bookYear);
            return;
        }
    }

    printf("Book not found\n");
}

void printLibrary(Library *library) {
    for (int i = 0; i < library->count; i++) {
        Book *book = library->library[i];
        if (book != NULL) {
            printf("Book with title %s, author %s, and year %d is in the library and is%s checked out.\n",
                   book->title, book->author, book->year, book->isAvailable ? " not" : "");
        }
    }
}

Book *findBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear) {
    for (int i = 0; i < library->count; i++) {
        Book *book = library->library[i];
        if (book != NULL &&
            strcmp(book->title, bookTitle) == 0 &&
            strcmp(book->author, bookAuthor) == 0 &&
            book->year == bookYear) {
            printf("Book with title %s, author %s, and year %d is found!\n",
                   bookTitle, bookAuthor, bookYear);
            return book;
        }
    }

    printf("Book not found\n");
    return NULL;
}

void checkoutBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear) {
    Book *book = findBook(library, bookTitle, bookAuthor, bookYear);
    if (book == NULL) {
        return;
    }

    if (!book->isAvailable) {
        printf("Book with title %s, author %s, and year %d is already checked out.\n",
               bookTitle, bookAuthor, bookYear);
        return;
    }

    book->isAvailable = 0;

    printf("Book with title %s, author %s, and year %d is checked out.\n",
           bookTitle, bookAuthor, bookYear);
}

void returnBook(Library *library, char *bookTitle, char *bookAuthor, int bookYear) {
    Book *book = findBook(library, bookTitle, bookAuthor, bookYear);
    if (book == NULL) {
        return;
    }

    if (book->isAvailable) {
        printf("Book with title %s, author %s, and year %d is not checked out.\n",
               bookTitle, bookAuthor, bookYear);
        return;
    }

    book->isAvailable = 1;

    printf("Book with title %s, author %s, and year %d is returned.\n",
           bookTitle, bookAuthor, bookYear);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    Library library = {.count = 0};

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char operation[16], title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH];
    int year;

    while (fscanf(file, "%s", operation) != EOF) {
        if (strcmp(operation, "add") == 0) {
            fscanf(file, " %[^\n,], %[^\n,], %d", title, author, &year);
            addBook(&library, title, author, year);
        } else if (strcmp(operation, "remove") == 0) {
            fscanf(file, " %[^\n,], %[^\n,], %d", title, author, &year);
            removeBook(&library, title, author, year);
        } else if (strcmp(operation, "print") == 0) {
            printLibrary(&library);
        } else if (strcmp(operation, "checkout") == 0) {
            fscanf(file, " %[^\n,], %[^\n,], %d", title, author, &year);
            checkoutBook(&library, title, author, year);
        } else if (strcmp(operation, "return") == 0) {
            fscanf(file, " %[^\n,], %[^\n,], %d", title, author, &year);
            returnBook(&library, title, author, year);
        }
    }

    fclose(file);
    return 0;
}
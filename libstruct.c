#include "libstruct.h"

void addBook(Library *library, const char *title, const char *author, int year) {
    if (library->count >= 100) {
        printf("The library is full. Cannot add more books\n");
        return;
    }

    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->library[i]->title, title) == 0 &&
            strcmp(library->library[i]->author, author) == 0 &&
            library->library[i]->year == year) {
            printf("Book with title %s, author %s,\n    and year %d is already in the library\n", title, author, year);
            return;
        }
    }

    Book *newBook = (Book *)malloc(sizeof(Book));
    newBook->title = strdup(title);
    newBook->author = strdup(author);
    newBook->year = year;
    newBook->isAvailable = 1;

    library->library[library->count++] = newBook;
    printf("Book with title %s, author %s,\n    and year %d added to the library\n", title, author, year);
}

void removeBook(Library *library, const char *title, const char *author, int year) {
    for (int i = 0; i < library->count; i++) {
        if (library->library[i] &&
            strcmp(library->library[i]->title, title) == 0 &&
            strcmp(library->library[i]->author, author) == 0 &&
            library->library[i]->year == year) {

            free(library->library[i]->title);
            free(library->library[i]->author);
            free(library->library[i]);

            for (int j = i; j < library->count - 1; j++) {
                library->library[j] = library->library[j + 1];
            }

            library->library[library->count - 1] = NULL;

            library->count--;

            printf("Book with title %s, author %s,\n and year %d has been removed from the library\n", title, author, year);
            return;
        }
    }
    printf("Book not found\n");
}

void printLibrary(const Library *library) {
    for (int i = 0; i < 100; i++) {
        if (library->library[i]) {
            printf("Book with title %s, author %s,\n    and year %d is in the library and %s checked out\n",
                   library->library[i]->title, library->library[i]->author, library->library[i]->year,
                   library->library[i]->isAvailable ? "isn't" : "is");
        }
    }
}

Book *findBook(const Library *library, const char *title, const char *author, int year) {
    for (int i = 0; i < library->count; i++) {
        if (library->library[i] &&
            strcmp(library->library[i]->title, title) == 0 &&
            strcmp(library->library[i]->author, author) == 0 &&
            library->library[i]->year == year) {
            printf("Book with title %s, author %s,\n    and year %d is found!\n", title, author, year);
            return library->library[i];
        }
    }
    printf("Book not found\n");
    return NULL;
}

void checkoutBook(Library *library, const char *title, const char *author, int year) {
    Book *book = findBook(library, title, author, year);
    if (!book) return;

    if (!book->isAvailable) {
        printf("Book with title %s, author %s,\n    and year %d is already checked out\n", title, author, year);
    } else {
        book->isAvailable = 0;
        printf("Book with title %s, author %s,\n    and year %d is checked out\n", title, author, year);
    }
}

void returnBook(Library *library, const char *title, const char *author, int year) {
    Book *book = findBook(library, title, author, year);
    if (!book) return;

    if (book->isAvailable) {
        printf("Book with title %s, author %s,\n    and year %d is not checked out\n", title, author, year);
    } else {
        book->isAvailable = 1;
        printf("Book with title %s, author %s,\n    and year %d is returned\n", title, author, year);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    Library library = { .count = 0 };
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char command[1024], title[1024], author[1024];
    int year;

    while (fscanf(file, "%s", command) != EOF) {
        if (strcmp(command, "add") == 0) {
            fscanf(file, " %1023[^,], %1023[^,], %d", title, author, &year);
            addBook(&library, title, author, year);
        } else if (strcmp(command, "remove") == 0) {
            fscanf(file, " %1023[^,], %1023[^,], %d", title, author, &year);
            removeBook(&library, title, author, year);
        } else if (strcmp(command, "print") == 0) {
            printLibrary(&library);
        } else if (strcmp(command, "checkout") == 0) {
            fscanf(file, " %1023[^,], %1023[^,], %d", title, author, &year);
            checkoutBook(&library, title, author, year);
        } else if (strcmp(command, "return") == 0) {
            fscanf(file, " %1023[^,], %1023[^,], %d", title, author, &year);
            returnBook(&library, title, author, year);
        }
    }

    fclose(file);
    return 0;
}
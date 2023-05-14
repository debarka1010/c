#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[50];
    int id;
    int is_available;
} book;

book books[MAX_BOOKS];
int num_books = 0;

void add_book() {
    book new_book;
    printf("Enter book title: ");
    fgets(new_book.title, 50, stdin);
    printf("Enter book author: ");
    fgets(new_book.author, 50, stdin);
    new_book.is_available = 1;
    new_book.id = num_books + 1;
    books[num_books++] = new_book;
    printf("Book added successfully!\n");
}

void display_books() {
    printf("ID\tTitle\t\tAuthor\t\tAvailability\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d\t%s\t%s\t%s\n", books[i].id, books[i].title, books[i].author, books[i].is_available ? "Available" : "Not Available");
    }
}

void borrow_book() {
    int book_id;
    printf("Enter book ID to borrow: ");
    scanf("%d", &book_id);
    getchar();
    for (int i = 0; i < num_books; i++) {
        if (books[i].id == book_id) {
            if (books[i].is_available) {
                books[i].is_available = 0;
                printf("Book \"%s\" borrowed successfully!\n", books[i].title);
                return;
            } else {
                printf("Book \"%s\" is not available for borrowing.\n", books[i].title);
                return;
            }
        }
    }
    printf("Book with ID %d not found.\n", book_id);
}

void return_book() {
    int book_id;
    printf("Enter book ID to return: ");
    scanf("%d", &book_id);
    getchar();
    for (int i = 0; i < num_books; i++) {
        if (books[i].id == book_id) {
            if (!books[i].is_available) {
                books[i].is_available = 1;
                printf("Book \"%s\" returned successfully!\n", books[i].title);
                return;
            } else {
                printf("This book \"%s\" was not borrowed.\n", books[i].title);
                return;
            }
        }
    }
    printf("Book with ID %d not found.\n", book_id);
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Borrow a book\n");
        printf("4. Return a book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                borrow_book();
                break;
            case 4:
                return_book();
                break;
            case 5:
                printf("Exiting library system...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
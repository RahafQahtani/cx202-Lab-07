#include <stdio.h>

typedef struct {
    int bookID;
    char title[100];
    char author[50];
    int year;
    float price;
} Book;

Book books[100];  
int N = 0;        

void loadBookData() {
    FILE *file = fopen("books.dat", "rb");
    if (file == NULL) {
        printf("No existing data found. Starting with an empty library.\n");
        return;
    }
    fread(&N, sizeof(int), 1, file);
    fread(books, sizeof(Book), N, file);
    fclose(file);
    printf("Loaded existing data from books.dat\n");
}

void saveBookData() {
    FILE *file = fopen("books.dat", "wb");
    if (file == NULL) {
        printf("Error saving data to file.\n");
        return;
    }
    fwrite(&N, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), N, file);
    fclose(file);
}

void inputBookData() {
    printf("Enter book details:\n");
    printf("ID: ");
    scanf("%d", &books[N].bookID);
    printf("Title: ");
    scanf(" %[^\n]", books[N].title);
    printf("Author: ");
    scanf(" %[^\n]", books[N].author);
    printf("Year: ");
    scanf("%d", &books[N].year);
    printf("Price (in SAR): ");
    scanf("%f", &books[N].price);
    N++;
    saveBookData();
    printf("Book added successfully and data saved to books.dat\n");
}

void displayBookData() {
    if (N == 0) {
        printf("No books available in the library.\n");
        return;
    }
    printf("Displaying all books:\n");
    for (int i = 0; i < N; i++) {
        printf("ID: %d\nTitle: %s\nAuthor: %s\nYear: %d\nPrice: %.2f SAR\n\n",
               books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
    }
}

void findBookByID() {
    int id;
    printf("Enter the Book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < N; i++) {
        if (books[i].bookID == id) {
            printf("Book found:\nID: %d\nTitle: %s\nAuthor: %s\nYear: %d\nPrice: %.2f SAR\n",
                   books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
            return;
        }
    }
    printf("No book found with ID %d\n", id);
}

void calculateTotalValue() {
    float totalValue = 0.0;
    for (int i = 0; i < N; i++) {
        totalValue += books[i].price;
    }
    printf("Total value of all books: %.2f SAR\n", totalValue);
}

int main() {
    loadBookData();  

    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for Book by ID\n");
        printf("4. Calculate Total Value of Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputBookData();
                break;
            case 2:
                displayBookData();
                break;
            case 3:
                findBookByID();
                break;
            case 4:
                calculateTotalValue();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX 100
#define TITLE_LEN 50

/*---------------------------------------------------
 Q1 PART 1: createBook
 Takes ID and Title and returns them in a struct
---------------------------------------------------*/
typedef struct
{
    int id;
    char title[TITLE_LEN];
} Book;

Book createBook(int id, char t[])
{
    Book b;
    b.id = id;
    strcpy(b.title, t);
    return b;
}

/*---------------------------------------------------
 Q1 PART 2: displayAllBooks (recursive)
---------------------------------------------------*/
void displayAllBooks(int ids[], char titles[][TITLE_LEN], int index, int total)
{
    if (index == total) // stop when finished
        return;

    printf("ID: %d  Title: %s\n", ids[index], titles[index]);

    displayAllBooks(ids, titles, index + 1, total); // next book
}

/*---------------------------------------------------
 Q1 PART 3: searchBookByID (recursive)
---------------------------------------------------*/
int searchBookByID(int ids[], int index, int total, int target)
{
    if (index == total) // not found
        return -1;

    if (ids[index] == target)
        return index;

    return searchBookByID(ids, index + 1, total, target);
}

/*---------------------------------------------------
 Q1 PART 4: changeBookTitle
---------------------------------------------------*/
void changeBookTitle(char titles[][TITLE_LEN], int index, char newTitle[])
{
    strcpy(titles[index], newTitle);
}

/*---------------------------------------------------
 Q1 PART 5: clearAllBooks (recursive)
---------------------------------------------------*/
void clearAllBooks(int ids[], char titles[][TITLE_LEN], int index, int total)
{
    if (index == total)
        return;

    ids[index] = 0;
    strcpy(titles[index], "");

    clearAllBooks(ids, titles, index + 1, total);
}

/*---------------------------------------------------
 SIMPLE MAIN to demonstrate
---------------------------------------------------*/
int main()
{
    int ids[3];
    char titles[3][TITLE_LEN];

    Book b1 = createBook(1, "C Book");
    Book b2 = createBook(2, "Math Book");
    Book b3 = createBook(3, "Science Book");

    ids[0] = b1.id;
    strcpy(titles[0], b1.title);
    ids[1] = b2.id;
    strcpy(titles[1], b2.title);
    ids[2] = b3.id;
    strcpy(titles[2], b3.title);

    printf("All Books:\n");
    displayAllBooks(ids, titles, 0, 3);

    printf("\nSearching for ID 2:\n");
    int pos = searchBookByID(ids, 0, 3, 2);
    printf("Found at index: %d\n", pos);

    printf("\nChanging title of book 1...\n");
    changeBookTitle(titles, 1, "New Math Book");
    displayAllBooks(ids, titles, 0, 3);

    printf("\nClearing all books...\n");
    clearAllBooks(ids, titles, 0, 3);
    displayAllBooks(ids, titles, 0, 3);

    return 0;
}

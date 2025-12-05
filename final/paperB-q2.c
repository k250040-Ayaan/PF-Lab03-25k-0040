#include <stdio.h>
#include <string.h>

#define PROD 4
#define LEN 50

int main()
{
    char name[PROD][LEN];
    float price[PROD];
    char category[PROD][LEN];

    int i, j;

    /* ---------------- PART 1: create arrays and input data ---------------- */
    for (i = 0; i < PROD; i++)
    {
        printf("Product %d name: ", i + 1);
        scanf(" %s", name[i]); // simple, no spaces

        printf("Product %d price: ", i + 1);
        scanf("%f", &price[i]);

        printf("Product %d category: ", i + 1);
        scanf(" %s", category[i]); // should be Electronics/Clothing/Home/Books
    }

    /* ---------------- PART 2: verify categories ---------------- */
    printf("\nCategory check:\n");
    for (i = 0; i < PROD; i++)
    {
        if (strcmp(category[i], "Electronics") == 0 ||
            strcmp(category[i], "Clothing") == 0 ||
            strcmp(category[i], "Home") == 0 ||
            strcmp(category[i], "Books") == 0)
        {
            printf("%s has valid category %s\n", name[i], category[i]);
        }
        else
        {
            printf("%s has INVALID category %s\n", name[i], category[i]);
        }
    }

    /* ---------------- PART 3: products with same name ---------------- */
    printf("\nProducts with the same name:\n");
    for (i = 0; i < PROD; i++)
    {
        for (j = i + 1; j < PROD; j++)
        {
            if (strcmp(name[i], name[j]) == 0)
            {
                printf("Same name: %s\n", name[i]);
                printf("  Product %d: price = %.2f, category = %s\n",
                       i + 1, price[i], category[i]);
                printf("  Product %d: price = %.2f, category = %s\n",
                       j + 1, price[j], category[j]);
            }
        }
    }

    /* ---------------- PART 4: group by categories ---------------- */
    printf("\nProducts grouped by category:\n");

    // Electronics
    printf("\nElectronics:\n");
    for (i = 0; i < PROD; i++)
        if (strcmp(category[i], "Electronics") == 0)
            printf("%s  (%.2f)\n", name[i], price[i]);

    // Clothing
    printf("\nClothing:\n");
    for (i = 0; i < PROD; i++)
        if (strcmp(category[i], "Clothing") == 0)
            printf("%s  (%.2f)\n", name[i], price[i]);

    // Home
    printf("\nHome:\n");
    for (i = 0; i < PROD; i++)
        if (strcmp(category[i], "Home") == 0)
            printf("%s  (%.2f)\n", name[i], price[i]);

    // Books
    printf("\nBooks:\n");
    for (i = 0; i < PROD; i++)
        if (strcmp(category[i], "Books") == 0)
            printf("%s  (%.2f)\n", name[i], price[i]);

    return 0;
}

#include <stdio.h>
#include <string.h>

#define USERS 3
#define LEN 100

int main()
{
    char username[USERS][LEN];
    char post[USERS][LEN];
    char date[USERS][LEN];

    int i, j;

    // -------------------- PART 1 --------------------
    for (i = 0; i < USERS; i++)
    {
        printf("Enter username: ");
        scanf("%s", username[i]);

        printf("Enter post: ");
        scanf(" %[^\n]", post[i]); // takes spaces

        printf("Enter date: ");
        scanf("%s", date[i]);
    }

    // -------------------- PART 2 --------------------
    printf("\nChecking usernames:\n");
    for (i = 0; i < USERS; i++)
    {
        if (username[i][0] != '@')
        {
            printf("%s is INVALID (must start with @)\n", username[i]);
            continue;
        }

        int valid = 1;
        for (j = 0; j < strlen(username[i]); j++)
            if (username[i][j] == ' ')
                valid = 0;

        if (valid)
            printf("%s is VALID\n", username[i]);
        else
            printf("%s is INVALID (space found)\n", username[i]);
    }

    // -------------------- PART 3 --------------------
    printf("\nWords starting with #:\n");
    for (i = 0; i < USERS; i++)
    {
        for (j = 0; j < strlen(post[i]); j++)
        {
            if (post[i][j] == '#')
            {
                int k = j;
                while (post[i][k] != ' ' && post[i][k] != '\0')
                {
                    printf("%c", post[i][k]);
                    k++;
                }
                printf("\n");
            }
        }
    }

    // -------------------- PART 4 --------------------
    printf("\nPost count per user:\n");
    for (i = 0; i < USERS; i++)
    {
        int count = 0;
        for (j = 0; j < USERS; j++)
        {
            if (strcmp(username[i], username[j]) == 0)
                count++;
        }
        printf("%s made %d posts\n", username[i], count);
    }

    return 0;
}

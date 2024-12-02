#include "b24ci1008_b24ee1085_b24bb1024_b24cy1015_features.h"

// Effect of displaying text on screen
void typingEffect(const char *text)
{
    struct timespec ts = {0, 20000000L}; // 50 milliseconds (50 million nanoseconds)
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        nanosleep(&ts, NULL); // Pause for the specified time
    }
    printf("\n");
}

/*--------LOGIN-----------*/

// verify
int verify()
{
    printf("Do you want to continue or go back?\n");
    printf("1. Continue\n0. Go Back\n");
    int option;
    while (1) // Loop until valid input is entered
    {
        int validInput = scanf("%d", &option);

        // If input is invalid or choice is out of range, ask for input again
        if (validInput == 1 && (option == 0 || option == 1))
        {
            printf(RESET);
            fflush(stdin);
            break;
        }
        else
        {
            fflush(stdin);
            printf(RED);
            printf("Enter a valid choice\n");
            printf(RESET);
        }
    }
    return option;
}

// Function to register a user
void registerUser()
{
    char password[50];
    FILE *file = fopen("users.txt", "a");

    // error handling
    if (file == NULL)
    {
        printf("\033[1;31;40mError opening file!\n\033[0m");
        return;
    }

    printf("\033[1;37;40mEnter username: \033[0m");

    printf("\033[1;31;47m");
    scanf("%s", username);
    printf("\033[0m");

    printf("\033[1;37;40mEnter password: \033[0m");

    printf("\033[1;31;47m");
    scanf("%s", password);
    printf("\033[0m");

    printf("\033[1;34;40m");
    fprintf(file, "%s %s\n", username, password);
    printf("\033[0m");

    fclose(file);

    printf("\033[1;32;40mUser registered successfully!\n\033[0m");
}
// Function to login a user
int loginUser()
{
    char password[50], fileUsername[50], filePassword[50];
    printf("\033[1;37;40m");
    FILE *file = fopen("users.txt", "r");
    printf("\033[0m");

    if (file == NULL)
    {
        printf("\033[1;31;40mError opening file!\n\033[0m");
        return 0;
    }

    printf("\033[1;37;40mEnter username: \033[0m");
    printf("\033[1;31;47m");
    scanf("%s", username);
    printf("\033[0m");

    printf("\033[1;37;40mEnter password: \033[0m");

    printf("\033[1;31;47m");
    scanf("%s", password);
    printf("\033[0m");

    while (fscanf(file, "%s %s", fileUsername, filePassword) != EOF)
    {
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int loginmain(int choice)
{
    switch (choice)
    {
    case 1:
        if (verify())
        {
            system(CLEAR);
            registerUser();
            return 1;
        }
        break;
    case 2:
        if (verify())
        {
            system(CLEAR);
            if (loginUser())
            {
                printf("\033[1;32;40mLogin successful!\n\033[0m");
                return 1;
            }
            else
            {
                printf("\033[1;31;40mInvalid username or password!\n\033[0m");
                return -1;
            }
        }
        break;
    }
    return 0;
}

// reading a recipe
void readFile(char *name)
{
    char new[50];
    int i, j;
    i = j = 0;
    while (name[i] != '\n' && name[i])
    {
        if (name[i] != ' ')
            new[j++] = name[i];
        i++;
    }
    new[j] = '\0';

    char filePath[100];
    snprintf(filePath, sizeof(filePath), "Recipes/%s.txt", new);

    FILE *read = NULL;
    read = fopen(filePath, "r");

    char con[1000]; // con represents content
    if (read != NULL)
    {
        while (fgets(con, 1000, read))
        {
            printf("\033[1;35;40m%s\033[0m", con);
        }
        printf("\n--------------------------------------------------------------\n");
    }
    else
    {
        printf(RED);
        printf("Recipe Not Found\n");
        printf(RESET);
    }

    fclose(read);

    spinner();
    printf("\rPress Enter to continue....");
    while (getchar() != '\n')
        ;
    system(CLEAR);
}

// Spinner
void spinner()
{
    const char *symbols = "|/-\\";
    struct timespec ts = {0, 100000000L};
    for (int i = 0; i < 40; i++)
    { // Loop for a certain number of spins
        printf("\r%c Loading...", symbols[i % 4]);
        fflush(stdout);
        nanosleep(&ts, NULL); // 100ms delay
    }
}

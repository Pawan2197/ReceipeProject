#include "b24ci1008_b24ee1085_b24bb1024_b24cy1015_features.h"

#define MAX 50

// user's choice
int choice;

// global initialisation of categories
char *snack[MAX] = {"veg hakka noodles", "panipuri", "pakoras", "onion rings", "cheese balls", "chaat papdi", "bhelpuri", "aloo tikki", "samosa", "chicken lollipop", "chicken nuggets", "chicken tikka", "chicken wings", "chicken satay", "fish cake", "fish fingers", "fish pakoras", "prawn tempura", "prawn tempura rolls"};
char *mainCourse[MAX] = {"vegetable kurma", "vegetable biryani", "veg pulao", "veg fried rice", "stuffed capsicum", "rajma masala", "pumpkin curry", "paneer butter masala", "paneer bhurji", "palak paneer", "moong dal tadka", "mixed vegetable curry", "matar paneer", "masoor dal", "malai kofta", "kadhi pakora", "kadhai paneer", "gobi masala", "dum aloo", "dal tadka", "dal makhani", "aloo gobi", "aloo matar", "baingan bharta", "bhajia", "bhindi masala", "cabbage sabzi", "chana masala", "chole masala"};
char *dessert[MAX] = {"mango mousse", "vanilla pudding", "chocolate brownies", "gajar halwa", "rice kheer", "cheese cake", "tiramisu", "gulab jamun", "apple pie", "fruit salad"};
char *beverage[MAX] = {"lemonade", "mango smoothie", "hot chocolate", "cold coffee", "orange juice", "strawberry milkshake", "masala chai", "mojito", "banana shake", "watermelon juice"};

// structure of a Recipe
typedef struct
{
    char tag[10];
    char name[50];
    char type[10];
    int servings;
    int time;
    char ingredients[100][100];
    char procedure[50][1000];
} Recipe;

// state variable
char state = 'm';

// force user to enter a valid choice
void input(int a, int b)
{
    int validInput;

    while (1) // Loop until valid input is entered
    {
        printf(RED);
        validInput = scanf("%d", &choice);

        // If input is invalid or choice is out of range, ask for input again
        if (validInput == 1 && choice >= a && choice <= b)
        {
            system(CLEAR);
            printf(RESET);
            fflush(stdin);
            return;
        }
        else
        {
            // Clear invalid input from the buffer
            while (getchar() != '\n')
                ;
            printf(RED);
            printf("Enter a valid choice\n");
            printf(RESET);
        }
    }
}

// Main Menu
void menu()
{
    printf(MAGENTA);
    typingEffect("\n================= MENU =================\n");
    printf(CYAN);
    typingEffect("1. Search a Recipe\n");
    typingEffect("2. Add a Recipe\n");
    typingEffect("3. Exit\n");
    printf(MAGENTA);
    printf("========================================\n");
    printf(RESET);

    printf("\033[2;31;40m");
    printf("\n(Press '0' to go to the previous interface)\n" RESET);
    printf("Choice : ");
    input(1, 3);
}

// print filtered Category
void dispDish(char *dishCategory[50])
{
    printf(YELLOW);
    int i;
    for (i = 0; i < 100; i++)
    {
        if (dishCategory[i] == '\0')
            break;

        printf("%d. %s\n", i + 1, dishCategory[i]);
    }
    printf(RESET);
    input(0, i);
    printf("\033[0;32;40m");
    if (choice != 0)
        readFile(dishCategory[choice - 1]);
    printf(RESET);
    if (choice == 0)
    {
        choice = 2;
        state = 's';
    }
    else
    {
        state = 's';
        choice = 0;
    }
}

// search option
void search()
{
    if (state == 's' && choice == 0)
    {
        system(CLEAR);
        printf("\033[1;4;34;40m"); // colour changed to blue
        typingEffect("Search menu, please choose any one of the option.");
        printf(RESET);

        printf(CYAN);
        typingEffect("1. Type a dish name.");
        typingEffect("2. Apply a filter.");
        printf(RESET);

        input(0, 2);
    }

    // Dish Name
    if (choice == 1 && state == 's')
    {
        printf(YELLOW);
        printf("Enter the name of your recipe: ");
        printf(RESET);

        printf(MAGENTA);
        char name[30];

        printf("\033[2;31;40m");
        printf("(Enter '0' to go back)\n" RESET);

        // taking recipe name
        fflush(stdin);
        fgets(name, sizeof(name), stdin);

        // opening up the recipe
        if (name[0] != '0')
            readFile(name);
        else
            choice = 0;
    }
    // Apply Filter
    else if (choice == 2 && state == 's')
    {
        printf(CYAN);
        typingEffect("Filters");
        printf(YELLOW);
        typingEffect("1. Snacks\n2. Main Course\n3. Dessert\n4. Beverage");
        printf(RESET);
        input(0, 4);
        if (choice == 1)
            dispDish(snack);
        else if (choice == 2)
            dispDish(mainCourse);
        else if (choice == 3)
            dispDish(dessert);
        else if (choice == 4)
            dispDish(beverage);
        else if (choice == 0)
            state = 's';
        search();
    }
    else if (choice == 0 && state == 's')
    {
        state = 'm';
        return;
    }
    // search();
}

// welcome message
void welcomeMessage()
{
    system(CLEAR);
    printf("\033[1;4;32;40m"); // Green color and underlined
    printf("****************************************\n");
    typingEffect("*********** WELCOME TO RECIPE **********");
    typingEffect("*************    APP  ******************");
    printf("****************************************\n");
    // typingEffect("Welcome to the Recipe App!");
    printf(RESET);
}

// registering a user
void login()
{
    printf(GREEN); // colour to bold green
    printf("1. Register\n");
    printf("2. Login\n");
    printf(RESET); // colour to normal

    printf("\033[1;33;40m"); // colour to YELLOW
    printf("Enter your choice: \n");
    printf("\033[2;33;40m(Enter '0' to go back)\n");
    printf(RESET); // colour to normal

    printf(RED);
    input(0, 3);
    printf(RESET);

    if (choice == 0)
    {
        // state = 'm';
        return;
    }
    state = 'l';
    int flag = loginmain(choice);
    if (flag == -1)
        login();
    else if (flag == 0)
        choice = 0;
}

void addRecipe()
{
    Recipe recipe;
    printf(GREEN "1. Veg\n");
    printf(RED "2. Non Veg\n" RESET);

    input(1, 2);
    choice == 1 ? strcpy(recipe.tag, "Veg") : strcpy(recipe.tag, "Non - Veg");

    strcmp(recipe.tag, "Veg") == 0 ? printf(GREEN "VEG\n") : printf(RED "NON - VEG\n" RESET);

    // Dish Type Selection
    typingEffect("Type : \n");
    typingEffect("1. Snack");
    typingEffect("2. Main Course");
    typingEffect("3. Dessert");
    typingEffect("4. Beverage");
    printf("Enter choice : ");
    input(1, 4);

    switch (choice)
    {
    case 1:
        strcpy(recipe.type, "Snack");
        break;
    case 2:
        strcpy(recipe.type, "Main Course");
        break;
    case 3:
        strcpy(recipe.type, "Dessert");
        break;
    case 4:
        strcpy(recipe.type, "Beverage");
        break;
    }

    strcmp(recipe.tag, "Veg") == 0 ? printf(GREEN "VEG\n") : printf(RED "NON - VEG\n" RESET);
    printf("Name : ");
    fflush(stdin);
    fgets(recipe.name, sizeof(recipe.name), stdin);
    recipe.name[strcspn(recipe.name, "\n")] = '\0'; // Remove newline

    // File name creation
    char r[10] = "Recipes/";
    char e[5] = ".txt";
    char fname[100];
    strcpy(fname, r);
    strcat(fname, recipe.name);
    strcat(fname, username); // Assuming username is a valid global variable
    strcat(fname, e);

    // Creating the file
    FILE *file = fopen(fname, "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write recipe details to file
    fprintf(file, "%s\n\n", recipe.tag);
    fprintf(file, "Dish type : %s\n\n", recipe.type);
    fprintf(file, "Dish name : %s\n\n", recipe.name);

    printf("Serving : ");
    scanf("%d", &recipe.servings);
    fprintf(file, "Servings : %d\n\n", recipe.servings);

    printf("Enter number of Ingredients : ");
    int noi;
    scanf("%d", &noi);
    typingEffect("Enter Ingredients\n");
    fprintf(file, "Ingredients : \n\n");
    fflush(stdin);
    for (int i = 0; i < noi; i++)
    {
        printf("%d. ", i + 1);
        fgets(recipe.ingredients[i], sizeof(recipe.ingredients[i]), stdin);
        recipe.ingredients[i][strcspn(recipe.ingredients[i], "\n")] = '\0';
        fprintf(file, "%d. %s\n", i + 1, recipe.ingredients[i]);
    }

    printf("Time (in minutes) : ");
    scanf("%d", &recipe.time);
    fprintf(file, "\n\nCooking Time : %d minutes\n\n", recipe.time);

    printf("Enter number of steps : ");
    int nop;
    scanf("%d", &nop);
    typingEffect("Procedure in steps\n");
    fprintf(file, "Procedure :\n");
    fflush(stdin);
    for (int i = 0; i < nop; i++)
    {
        printf("%d. ", i + 1);
        fgets(recipe.procedure[i], sizeof(recipe.procedure[i]), stdin);
        recipe.procedure[i][strcspn(recipe.procedure[i], "\n")] = '\0';
        fprintf(file, "%d. %s\n", i + 1, recipe.procedure[i]);
    }

    fprintf(file, "\npublished by %s", username);
    fclose(file);

    // Now, add the recipe to the corresponding array (snack, mainCourse, etc.)
    char name[50];
    strcpy(name, recipe.name);
    strcat(name, " ");
    strcat(name, username);
    if (strcmp(recipe.type, "Snack") == 0)
    {
        // Append to snack array
        int i = 0;
        while (snack[i] != NULL) // Find the first empty spot
        {
            i++;
        }
        snack[i] = (char *)malloc(sizeof(char) * (strlen(name) + 1));
        if (snack[i] != NULL)
        {
            strcpy(snack[i], name); // Store the recipe filename
        }
    }
    else if (strcmp(recipe.type, "Main Course") == 0)
    {
        // Append to mainCourse array
        int i = 0;
        while (mainCourse[i] != NULL) // Find the first empty spot
        {
            i++;
        }
        mainCourse[i] = (char *)malloc(sizeof(char) * (strlen(name) + 1));
        if (mainCourse[i] != NULL)
        {
            strcpy(mainCourse[i], name); // Store the recipe filename
        }
    }
    else if (strcmp(recipe.type, "Dessert") == 0)
    {
        // Append to dessert array
        int i = 0;
        while (dessert[i] != NULL) // Find the first empty spot
        {
            i++;
        }
        dessert[i] = (char *)malloc(sizeof(char) * (strlen(name) + 1));
        if (dessert[i] != NULL)
        {
            strcpy(dessert[i], name); // Store the recipe filename
        }
    }
    else if (strcmp(recipe.type, "Beverage") == 0)
    {
        // Append to beverage array
        int i = 0;
        while (beverage[i] != NULL) // Find the first empty spot
        {
            i++;
        }
        beverage[i] = (char *)malloc(sizeof(char) * (strlen(name) + 1));
        if (beverage[i] != NULL)
        {
            strcpy(beverage[i], name); // Store the recipe filename
        }
    }

    printf(YELLOW "THANK YOU !!\n");
    printf("\rPress Enter to continue....");
    while (getchar() != '\n')
        ;

    state = 'm';
    // printf("%c", state); // Return to menu
}

// Driver Function
int main()
{
    system("title Recipe App");
    system(CLEAR);

    while (state != 'e')
    {
        switch (state)
        {
        case 'm':
            welcomeMessage();
            menu();
            if (choice == 1)
                state = 's';
            else if (choice == 2)
                state = 'a';
            else if (choice == 3)
                state = 'e';
            break;
        case 's':
            choice = 0;
            search();
            // state = 'm';
            break;
        case 'a':
            login();
            if (choice != 0)
                addRecipe();
            else if (choice == 0 && state == 'l')
            {
                system(CLEAR);
                state = 'a';
            }
            else
                state = 'm';
            break;
        }
    }

    // freeing the memory
    for (int i = 0; i < 50; i++)
    {
        if (snack[i] != NULL)
            free(snack[i]);
        if (mainCourse[i] != NULL)
            free(mainCourse[i]);
        if (dessert[i] != NULL)
            free(dessert[i]);
        if (beverage[i] != NULL)
            free(beverage[i]);
    }
    return 0;
}

/*
m : menu
e : exit
s : search
f : filter
a : add recipe
*/

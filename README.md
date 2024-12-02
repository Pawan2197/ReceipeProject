
# Interactive Recipe Management Application

This project is a console-based application developed in C to simplify recipe organization and access. It features user account management, recipe searching, and the ability to add customized recipes in an interactive and visually appealing environment.

## Key Features

- **Account Management**:
  - User registration with secure username and password storage.
  - Login functionality for personalized access.
- **Recipe Search**:
  - Find recipes by typing the name or browsing by category filters.
  - Display user-submitted recipes with their names appended to the recipe name.
- **Add Recipes**:
  - Add detailed recipes, specifying ingredients, procedure, serving size, and preparation time.
  - Recipes are saved with the user's name included, ensuring clear attribution.
- **Categorized Recipes**:
  - Organized into Snacks, Main Course, Desserts, and Beverages for ease of access.
- **User-Friendly Interface**:
  - Includes effects like typing animations and a loading spinner to enhance the experience.

## New Functionalities

- **Personalized Recipe Addition**:
  - Users can input their own recipes, which are saved with their usernames appended to the recipe names.
  - When searched, these personalized recipes are displayed prominently along with their details.

## Project Layout

- **Header File** (`features.h`): Defines function declarations, global variables, and macros for dynamic UI elements.
- **Feature Implementations** (`features.c`): Contains logic for user login, file listing, typing effects, and file operations.
- **Application Core** (`Recipe.c`): Manages the main application flow, including menu handling and recipe search filters.

## Getting Started

### Prerequisites
- C compiler (e.g., GCC).
- A terminal or IDE for running the application.

### Compilation & Execution
1. Clone or download the repository.
2. Compile the source files using:
   ```bash
   gcc b24ci1008_b24ee1085_b24bb1024_b24cy1015_Recipe.c b24ci1008_b24ee1085_b24bb1024_b24cy1015_features.c -o RecipeApp
   ```
3. Run the executable:
   ```bash
   ./RecipeApp
   ```

#ifndef FEATURES_H
#define FEATURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// color codes
#define RED "\033[1;31;40m"
#define GREEN "\033[1;32;40m"
#define YELLOW "\033[1;33;40m"
#define MAGENTA "\033[1;35;40m"
#define CYAN "\033[1;36;40m"
#define RESET "\033[0m"

// Clear
#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls" // For Windows
#elif defined(__APPLE__) || defined(__MACH__)
#define CLEAR "clear"
#endif

// Effect of displaying text on screen
void typingEffect(const char *text);

// LOGIN
char username[50];
int loginmain(int choice);

// reading a recipe
void readFile(char *name);

// Spinner
void spinner();

#endif
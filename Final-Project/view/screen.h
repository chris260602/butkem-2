#include<stdio.h>
#include<stdlib.h>




void UI() {
    puts("░██╗░░░░░░░██╗██╗░░██╗██╗░██████╗██╗░░██╗");
    puts("░██║░░██╗░░██║██║░░██║██║██╔════╝██║░██╔╝");
    puts("░╚██╗████╗██╔╝███████║██║╚█████╗░█████═╝░");
    puts("░░████╔═████║░██╔══██║██║░╚═══██╗██╔═██╗░");
    puts("░░╚██╔╝░╚██╔╝░██║░░██║██║██████╔╝██║░╚██╗");
    puts("░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝╚═════╝░╚═╝░░╚═╝");
    puts("");
    puts("");

    puts(" █     █░ ██░ ██  ██▓  ██████  ██ ▄█▀");
    puts("▓█░ █ ░█░▓██░ ██▒▓██▒▒██    ▒  ██▄█▒");
    puts("▒█░ █ ░█ ▒██▀▀██░▒██▒░ ▓██▄   ▓███▄░");
    puts("░█░ █ ░█ ░▓█ ░██ ░██░  ▒   ██▒▓██ █▄");
    puts("░░██▒██▓ ░▓█▒░██▓░██░▒██████▒▒▒██▒ █▄");
    puts("░ ▓░▒ ▒   ▒ ░░▒░▒░▓  ▒ ▒▓▒ ▒ ░▒ ▒▒ ▓▒");
    puts("  ▒ ░ ░   ▒ ░▒░ ░ ▒ ░░ ░▒  ░ ░░ ░▒ ▒░");
    puts("  ░   ░   ░  ░░ ░ ▒ ░░  ░  ░  ░ ░░ ░");
    puts("    ░     ░  ░  ░ ░        ░  ░  ░  ");
    puts("");
    puts("");
}

void Login() {
    system("cls || clear");
    UI();
    puts("1. Login");
    puts("2. Sign Up");
    puts("3. Exit");
    printf(">> ");
}

void Main_Screen(char* name) {
    system("cls || clear");
    UI();
    printf("Welcome %s\n", name);
    puts("1. Home Page");
    puts("2. CookBook");
    puts("3. Kitchen");
    puts("4. Pantry");
    puts("5. Profile");
    puts("6. Exit");
    printf(">> ");
}

void Home_Page() {
    system("cls || clear");
    puts("1. Recipe Suggestion");
    puts("2. Search");
    puts("3. Exit");
    printf(">> ");
}

void Cook_Book() {
    system("cls || clear");
    puts("1. Saved Recipes");
    puts("2. Search");
    puts("3. Add Recipe");
    puts("4. Remove Recipe");
    puts("5. Exit");
    printf(">> ");
}

void Kitchen() {
    system("cls || clear");
    puts("1. Selected Recipes");
    puts("2. Ingredients List");
    puts("3. Start Cooking");
    puts("4. Exit");
    printf(">> ");
}

void Pantry() {
    system("cls || clear");
    puts("1. Ingredient");
    puts("2. Search");
    puts("3. Add");
    puts("4. Remove");
    puts("5. Exit");
    printf(">> ");
}

void Profile() {
    system("cls || clear");
    puts("1. Preferences");
    puts("2. Settings");
    puts("3. Exit");
    printf(">> ");
}

void settings() {
    system("cls || clear");
    puts("1. Change Username");
    puts("2. Change Password");
    puts("3. Exit");
}

void Recipe_Screen() {
    system("cls || clear");
    puts("1. Description");
    puts("2. Instruction");
    puts("3. Ingredient");
    puts("4. Exit");
    printf(">> ");
}

void Start_Cooking() {
    system("cls || clear");
    puts("1. Status & Progress");
    puts("2. Instruction");
    puts("3. Stop Cooking");
    puts("4. Exit");
    printf(">> ");
}

void Add() {
    system("cls || clear");
    puts("1. Scan Receipt");
    puts("2. Manual Entry");
    puts("3. Exit");
    printf(">> ");
}

void preference_screen() {
    system("cls || clear");
    puts("1. Kering");
    puts("2. Basah");
    puts("3. Minuman");
    puts("4. Dessert");
    printf(">> ");
}



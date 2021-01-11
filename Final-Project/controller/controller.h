#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../model/model.h"

user* create_user(char* name, char* pass) {
    user* temp = (user*)malloc(sizeof(user));
    strcpy(temp->name, name);
    strcpy(temp->pass, pass);
    temp->prev = temp->next = NULL;
    return temp;
}

user* push_user(char* name, char* pass) {
    user* temp = create_user(name, pass);
    if (!headuser) {
        headuser = tailuser = temp;
    }
    else {
        temp->next = headuser;
        headuser->prev = temp;
        headuser = temp;
    }
}

user* find_user(char* name) {
    user* temp = headuser;
    while (temp && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }
    return temp;
}

void change_user_name(user* curr, char* name) {
    strcpy(curr->name, name);
    return;
}

void change_user_pass(user* curr, char* pass) {
    strcpy(curr->pass, pass);
    return;
}


void print() {
    user* temp = headuser;
    while (temp) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}



//Recipe

void add_recipe(user* curr, recipe* temp, int qty) {
    int i = 0;
    int flag = 0;
    while (flag == 0 || i > 49) {
        if (curr->masakan.name[i][0] == '\0') {
            strcpy(curr->masakan.name[i], (char*)temp->name);
            strcpy(curr->masakan.description[i], (char*)temp->description);
            strcpy(curr->masakan.instruction[i], (char*)temp->instruction);
            for (int j = 0;j < qty;j++) {
                strcpy(curr->masakan.ingredient[i][j], (char*)temp->ingredient);
            }
            flag == 1;
            break;
        }
        else {
            i++;
        }
    }
    // printf("%s\n", curr->masakan.name[i]);
    // printf("%s\n", curr->masakan.description[i]);
    // printf("%s\n", curr->masakan.instruction[i]);
    // printf("%s\n", curr->masakan.ingredient[i][0]);
    if (i > 49) {
        puts("Recipe is Full");
        getchar();
    }
    else {
        puts("Recipe added");
        getchar();
    }
    return;
}

void print_recipe(user* curr) {
    user* temp = curr;
    int i = 0;
    if (temp->masakan.name[0] == '\0') {
        puts("You have no dish");
        getchar();
        return;
    }
    while (temp->masakan.name[i][0] != '\0') {
        printf("Dish name: %s\n", temp->masakan.name[i]);
        printf("Dish Description: %s\n", temp->masakan.description[i]);
        printf("Dish Instruction: %s\n", temp->masakan.instruction[i]);
        int j = 0;
        printf("Dish Ingredients:\n");
        while (temp->masakan.ingredient[i][j][0] != '\0') {
            printf("%d. %s\n", j + 1, temp->masakan.ingredient[i][j]);
            j++;
        }
        puts("--------------------------------");
        i++;
        puts("Press enter to continue");
        getchar();
    }
    return;
}





/***********
 Validation
 ***********/

bool validate_new_user(char* name) {
    user* curr = headuser;
    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            puts("User already exist!");
            getchar();
            return false;
        }
        curr = curr->next;
    }
    return true;
}

bool validate_login(char* name, char* pass) {
    user* curr = headuser;
    while (curr) {
        if (strcmp(curr->name, name) == 0 && strcmp(curr->pass, pass) == 0) {
            return true;
        }
        curr = curr->next;
    }
    puts("Wrong Username or password");
    return false;

}
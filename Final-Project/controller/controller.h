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

//Preferences

void add_preference(user* curr, int choice) {
    curr->preference = choice;
    puts("Preferences has been set!");
    getchar();
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
    if (i > 49) {
        puts("Recipe is Full");
        getchar();
    }
    else {
        puts("Recipe added");
    }
}

void print_recipe(user* curr) {
    user* temp = curr;
    int i = 0, flag = 0;
    while (i <= 49) {
        if (temp->masakan.name[i][0] != '\0') {
            system("cls || clear");
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
            puts("Press enter to continue");
            flag = 1;
            getchar();
        }
        i++;
    }
    if (flag == 0) {
        puts("No dish available!");
        getchar();
    }
    return;
}

int Remove_recipe(user* curr, char* name) {
    int i = 0;
    while (i <= 49 && strcmp(curr->masakan.name[i], name) != 0) {
        i++;
    }
    if (i > 49) {
        puts("No dish available");
        getchar();
        return 0;
    }
    else if (strcmp(curr->masakan.name[i], name) == 0) {
        curr->masakan.name[i][0] = '\0';
        curr->masakan.description[i][0] = '\0';
        curr->masakan.instruction[i][0] = '\0';
        int j = 0;
        while (curr->masakan.ingredient[i][j][0] != '\0') {
            curr->masakan.ingredient[i][j][0] = '\0';
            j++;
        }
        puts("Dish has been removed!");
        getchar();
        return 1;
    }
}

void search_recipe(user* curr, char* name) {
    int i = 0, flag = 0;
    while (i <= 49) {
        if (strcmp(curr->masakan.name[i], name) == 0) {
            flag = 1;
            printf("%s is found\n", curr->masakan.name[i]);
            printf("Description: %s\n", curr->masakan.description[i]);
            printf("Instruction: %s\n", curr->masakan.instruction[i]);
            int j = 0;
            printf("Ingredients:\n");
            while (curr->masakan.ingredient[i][j][0] != '\0') {
                printf("%d. %s\n", j + 1, curr->masakan.ingredient[i][j]);
                j++;
            }
            puts("Press enter to continue!");
            getchar();
            break;
        }
        i++;
    }
    if (flag == 0) {
        printf("%s not found!\n", name);
        getchar();
    }
}

global_recipe* make_global(recipe* curr, int qty) {
    global_recipe* temp = (global_recipe*)malloc(sizeof(global_recipe));
    strcpy(temp->name, curr->name[0]);
    strcpy(temp->description, curr->description[0]);
    strcpy(temp->instruction, curr->instruction[0]);
    temp->type = curr->type[0];
    temp->next = temp->prev = NULL;
    int j = 0;
    for (int j = 0;j < qty;j++) {
        strcpy(temp->ingredient[j], (char*)curr->ingredient[j]);
    }
    getchar();
    return temp;
}

void add_global(recipe* curr, int qty) {
    global_recipe* temp = make_global(curr, qty);

    if (!head_global) {
        head_global = tail_global = temp;
    }
    else {
        temp->next = head_global;
        head_global->prev = temp;
        head_global = temp;
    }
}

void print_global(int type) {
    global_recipe* curr = head_global;
    int flag = 0;
    if (!head_global) {
        puts("No suggestion available!");
        getchar();
    }
    else {
        while (curr) {
            if (curr->type == type) {
                flag = 1;
                system("cls || clear");
                printf("Dish name: %s\n", curr->name);
                printf("Dish Description: %s\n", curr->description);
                printf("Dish Instruction: %s\n", curr->instruction);
                int j = 0;
                printf("Dish Ingredients:\n");
                while (curr->ingredient[j][0] != '\0') {
                    printf("%d. %s\n", j + 1, curr->ingredient[j]);
                    j++;
                }
                puts("--------------------------------");
                puts("Press enter to continue");
                getchar();
            }
            curr = curr->next;
        }
        if (flag == 0) {
            puts("No suggestion available!");
            getchar();
        }
    }
}

void Remove_global(char* Remove_global) {
    global_recipe* curr = head_global;
    if (!head_global) {
        return;
    }
    else {
        while (curr) {
            if (strcmp(curr->name, Remove_global) == 0) {
                curr->name[0] = '\0';
                curr->description[0] = '\0';
                curr->instruction[0] = '\0';
                int j = 0;
                while (curr->ingredient[j][0] != '\0') {
                    curr->ingredient[j][0] = '\0';
                    j++;
                }
                break;
            }
            curr = curr->next;
        }
    }
}

void search_global(int type) {
    global_recipe* curr = head_global;
    int flag = 0;
    while (curr) {
        if (curr->type == type) {
            flag = 1;
            system("cls || clear");
            printf("Dish name: %s\n", curr->name);
            printf("Dish Description: %s\n", curr->description);
            printf("Dish Instruction: %s\n", curr->instruction);
            int j = 0;
            printf("Dish Ingredients:\n");
            while (curr->ingredient[j][0] != '\0') {
                printf("%d. %s\n", j + 1, curr->ingredient[j]);
                j++;
            }
            puts("--------------------------------");
            puts("Press enter to continue");
            getchar();
        }
        curr = curr->next;
    }
    if (flag == 0) {
        puts("No suggestion available!");
        getchar();
    }
}

//Ingredient

void print_ingredient(user* curr) {
    int i = 0, index = 1, flag = 0;
    while (i <= 99) {
        if (curr->makanan.name[i][0] != '\0') {
            printf("%d. %-25s X %d\n", index, curr->makanan.name[i], curr->makanan.qty[i]);
            flag = 1, index++;
        }
        i++;
    }
    if (flag == 0) {
        puts("No ingredient left");
        getchar();
    }
    else {
        getchar();
    }
}

void add_ingredient(user* curr, bahan* temp) {
    int i = 0, flag = 0;
    while (i <= 99) {
        if (curr->makanan.name[i][0] == '\0') {
            strcpy(curr->makanan.name[i], temp->name[0]);
            curr->makanan.qty[i] = temp->qty[0];
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0) {
        puts("You have too much ingredients!");
        getchar();
    }
    else {
        puts("Ingredient added succesfully!");
        getchar();
    }
}

void remove_ingredient(user* curr, bahan* temp) {
    int i = 0, flag = 0;
    while (i <= 99) {
        if (strcmp(curr->makanan.name[i], temp->name[0]) == 0) {
            if ((curr->makanan.qty[i] - temp->qty[0]) <= 0) {
                curr->makanan.name[i][0] = '\0';
                curr->makanan.qty[i] = 0;
            }
            else {
                curr->makanan.qty[i] -= temp->qty[0];
            }
            flag = 1;
        }
        i++;
    }
    if (flag == 0) {
        puts("ingredients not found!");
        getchar();
    }
    else {
        puts("Ingredient removed!");
        getchar();
    }
}

void search_ingredient(user* curr, char* name) {
    int i = 0, flag = 0;
    while (i <= 99) {
        if (strcmp(curr->makanan.name[i], (char*)name) == 0) {
            printf("%s found!\n", curr->makanan.name[i]);
            printf("%d left!\n", curr->makanan.qty[i]);
            getchar();
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0) {
        printf("%s not found!\n", name);
        getchar();
    }
}




/***********
 Validation
 ***********/

bool validate_new_user(char* name) {
    user* curr = headuser;
    if (strlen(name) < 3 || strlen(name) > 50) {
        puts("Name length from 3-50 only!");
        getchar();
        return false;
    }
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

bool validate_new_pass(char* pass) {
    if (strlen(pass) < 4 || strlen(pass) > 12) {
        puts("Name length from 4-12 only!");
        getchar();
        return false;
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
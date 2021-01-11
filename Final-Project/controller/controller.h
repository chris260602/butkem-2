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

void Remove_recipe(user* curr, char* name) {
    int i = 0;
    while (i <= 49 && strcmp(curr->masakan.name[i], name) != 0) {
        i++;
    }
    if (i > 49) {
        puts("No dish available");
        getchar();
        return;
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
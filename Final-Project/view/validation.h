#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// VALIDATION
void validate_register(char* name, char* pass)
{
    user* curr = headuser;
    
    // VALIDATE NAME REGISTRATION
    do
    {
        scanf("%[^\n]", curr -> name);
    } while (strlen(curr -> name) < 3 || strlen(curr -> name) > 50 || isdigit(curr -> name) != 0); // validate that the name can't contain number and must use 3 -- 50 characters
    strcpy(curr -> name, name);
    
    // VALIDATE PASSWORD REGISTRATION
    do
    {
        scanf("%[^\n]", curr -> pass);
    } while (strlen(curr -> pass) < 12 || isalnum(curr -> pass) != 0); // validate that the password must be 12 characters minimum and alphanumeric
    strcpy(curr -> pass, pass);
}

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

// REGISTER
void register()
{
    char new_user[100];
    char new_pass[100];
    do {
        printf("Input new name: ");
        scanf("%[^\n]", new_user);
        getchar();
    } while (!validate_new_user(new_user));
    printf("Input new password: ");
            scanf("%[^\n]", new_pass);
            getchar();
            push_user(new_user, new_pass);
            printf("%s Succefully Registered\n", new_user);
            getchar();
}

// LOGIN
void login()
{
    //Login
        //DONE
            do {
                puts("Type 'back' to go back");
                printf("Input Username: ");
                scanf("%[^\n]", userr);
                getchar();
                if (strcmp(userr, "back") == 0) {
                    break;
                }
                printf("Input your password: ");
                scanf("%[^\n]", pass);
                getchar();
            } while (!validate_login(userr, pass));
            if (strcmp(userr, "back") != 0) {
                verified = true;
            }
            curr_user = find_user(userr);
}
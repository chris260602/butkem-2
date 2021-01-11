#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../controller/controller.h"
#include "screen.h"


int main() {
    bool running = true;
    while (running) {
        char userr[100];
        char pass[100];
        user* curr_user = NULL;
        int opt = -1;
        bool verified = false;
        Login();
        do {
            scanf("%d", &opt);
            getchar();
        } while (opt < 1 || opt>3);

        //Login
        if (opt == 1) {
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

        //Register
        else if (opt == 2) {
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

        //Exit
        else if (opt == 3) {
            running = false;
        }
        while (verified) {
            Main_Screen(curr_user->name);
            int opt1 = -1;
            do {
                scanf("%d", &opt1);
                getchar();
            } while (opt1 < 1 && opt1>6);
            if (opt1 == 1) {
                Home_Page();
            }
            else if (opt1 == 2) {
                Cook_Book();
                int opt2 = -1;
                do {
                    scanf("%d", &opt2);
                    getchar();
                } while (opt2 < 1 && opt2>3);
                if (opt2 == 1) {
                    print_recipe(curr_user);
                }
                else if (opt2 == 2) {

                }
                else if (opt2 == 3) {
                    continue;
                }
            }
            else if (opt1 == 3) {
                Kitchen();
            }
            else if (opt1 == 4) {
                Pantry();
                int opt4 = -1;
                do {
                    scanf("%d", &opt4);
                    getchar();
                } while (opt4 < 1 && opt4>5);
                if (opt4 == 1) {

                }
                else if (opt4 == 2) {

                }
                else if (opt4 == 3) {
                    int recipe_qty;
                    recipe* temp = (recipe*)malloc(sizeof(recipe));
                    printf("What is the name of your recipe: ");
                    scanf("%[^\n]", temp->name);
                    getchar();
                    printf("What is your description of %s: ", temp->name);
                    scanf("%[^\n]", temp->description);
                    getchar();
                    printf("What is your instruction of %s: ", temp->name);
                    scanf("%[^\n]", temp->instruction);
                    getchar();
                    printf("How many ingredients are there: ");
                    scanf("%d", &recipe_qty);
                    getchar();
                    printf("List your Ingredients (Name#QTY):\n");
                    for (int i = 0;i < recipe_qty;i++) {
                        scanf("%[^\n]", temp->ingredient[i]);
                        getchar();
                    }
                    add_recipe(curr_user, temp, recipe_qty);

                }
                else if (opt4 == 4) {

                }
                else if (opt4 == 5) {
                    continue;
                }
            }

            //Profile
            else if (opt1 == 5) {
                bool run5 = true;
                while (run5) {
                    Profile();
                    int opt5 = -1;
                    do {
                        scanf("%d", &opt5);
                        getchar();
                    } while (opt5 < 1 && opt5>3);

                    //Preferences
                    if (opt5 == 1) {
                        puts("Coming soon!");
                        getchar();
                    }

                    // Settings
                    else if (opt5 == 2) {
                        settings();
                        int opt_setting = -1;
                        do {
                            scanf("%d", &opt_setting);
                            getchar();
                        } while (opt_setting < 1 && opt_setting>3);

                        //Change Username
                        if (opt_setting == 1) {
                            char new_name[255];
                            scanf("%[^\n]", new_name);
                            getchar();
                            if (validate_new_user(new_name) == false) {
                                continue;
                            }
                            else {
                                change_user_name(curr_user, new_name);
                                puts("Succesfully change your username");
                            }
                        }

                        //Change Password
                        else if (opt_setting == 2) {
                            char new_pass[255];
                            scanf("%[^\n]", new_pass);
                            getchar();
                            change_user_pass(curr_user, new_pass);
                            puts("Succesfully change your password");
                            getchar();
                        }

                        //Exit
                        else if (opt_setting == 3) {
                            break;
                        }
                    }

                    //Exit
                    else if (opt5 == 3) {
                        run5 = false;
                    }
                }
            }

            //Exit
            else if (opt1 == 6) {
                verified = false;
            }
        }

    }

    return 0;
}
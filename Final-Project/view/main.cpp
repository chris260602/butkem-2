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
        //DONE
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
        //DONE
        else if (opt == 2) {
            char new_user[100];
            char new_pass[100];
            do {
                printf("Input new name: ");
                scanf("%[^\n]", new_user);
                getchar();
            } while (!validate_new_user(new_user));
            do {
                printf("Input new password: ");
                scanf("%[^\n]", new_pass);
                getchar();
            } while (!validate_new_pass(new_pass));
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
            //Homepage (DONE)
            if (opt1 == 1) {
                Home_Page();
                int opt_home = -1;
                do {
                    scanf("%d", &opt_home);
                    getchar();
                } while (opt_home < 1 && opt_home>3);

                //Suggestion (DONE)
                if (opt_home == 1) {
                    print_global(curr_user->preference);
                }

                //Search (DONE)
                else if (opt_home == 2) {
                    int opt_filter = -1;
                    preference_screen();
                    do {
                        scanf("%d", &opt_filter);
                        getchar();
                    } while (opt_filter < 1 && opt_filter>4);
                    search_global(opt_filter);
                }

                //Exit
                else if (opt_home == 3) {
                    continue;
                }
            }

            //CookBook (DONE)
            else if (opt1 == 2) {
                Cook_Book();
                int opt2 = -1;
                do {
                    scanf("%d", &opt2);
                    getchar();
                } while (opt2 < 1 && opt2>4);

                //Saved Recipe (DONE)
                if (opt2 == 1) {
                    print_recipe(curr_user);
                }
                //Search (DONE)
                else if (opt2 == 2) {
                    char recipe_name[100];
                    printf("What recipe do you want to find: ");
                    scanf("%[^\n]", recipe_name);
                    getchar();
                    search_recipe(curr_user, recipe_name);
                }
                //Add recipe (DONE)
                else if (opt2 == 3) {
                    int recipe_qty;
                    recipe* temp = (recipe*)malloc(sizeof(recipe));
                    printf("What is your recipe type:\n");
                    preference_screen();
                    do {
                        scanf("%d", &temp->type[0]);
                        getchar();
                    } while (temp->type[0] < 1 && temp->type[0]>4);
                    printf("What is the name of your recipe: ");
                    scanf("%[^\n]", temp->name[0]);
                    getchar();
                    printf("What is your description of %s: ", temp->name[0]);
                    scanf("%[^\n]", temp->description[0]);
                    getchar();
                    printf("What is your instruction of %s: ", temp->name);
                    scanf("%[^\n]", temp->instruction[0]);
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
                    add_global(temp, recipe_qty);
                    free(temp);
                }
                //Remove Recipe (DONE)
                else if (opt2 == 4) {
                    char rem_rec[100];
                    printf("What dish do you want to remove: ");
                    scanf("%[^\n]", rem_rec);
                    getchar();
                    int flag = Remove_recipe(curr_user, rem_rec);
                    if (flag == 1) {
                        Remove_global(rem_rec);
                    }
                }
                //Exit
                else if (opt2 == 5) {
                    continue;
                }
            }

            //Kitchen
            else if (opt1 == 3) {
                Kitchen();
            }

            //Pantry (DONE)
            else if (opt1 == 4) {
                Pantry();
                int opt4 = -1;
                do {
                    scanf("%d", &opt4);
                    getchar();
                } while (opt4 < 1 && opt4>5);
                //Ingredient (DONE)
                if (opt4 == 1) {
                    print_ingredient(curr_user);
                }
                //Search (DONE)
                else if (opt4 == 2) {
                    char ingredient_name[100];
                    printf("What ingredient are you looking for: ");
                    scanf("%[^\n]", ingredient_name);
                    getchar();
                    search_ingredient(curr_user, ingredient_name);
                }
                //Add ingredient (DONE)
                else if (opt4 == 3) {
                    bahan* temp = (bahan*)malloc(sizeof(bahan));
                    printf("What is your ingredient name: ");
                    scanf("%[^\n]", temp->name[0]);
                    getchar();
                    printf("What is the quantity of your ingredient : ");
                    scanf("%d", &temp->qty[0]);
                    getchar();
                    add_ingredient(curr_user, temp);
                    free(temp);
                }
                //Remove ingredient (DONE)
                else if (opt4 == 4) {
                    bahan* temp = (bahan*)malloc(sizeof(bahan));
                    printf("What is your ingredient name: ");
                    scanf("%[^\n]", temp->name[0]);
                    getchar();
                    printf("What how many do you want to remove : ");
                    scanf("%d", &temp->qty[0]);
                    getchar();
                    remove_ingredient(curr_user, temp);
                    free(temp);
                }

                //Exit
                else if (opt4 == 5) {
                    continue;
                }
            }

            //Profile (DONE)
            else if (opt1 == 5) {
                bool run5 = true;
                while (run5) {
                    Profile();
                    int opt5 = -1;
                    do {
                        scanf("%d", &opt5);
                        getchar();
                    } while (opt5 < 1 && opt5>3);

                    //Preferences (DONE)
                    if (opt5 == 1) {
                        int opt_pref = -1;
                        preference_screen();
                        do {
                            scanf("%d", &opt_pref);
                            getchar();
                        } while (opt_pref < 1 && opt_pref>4);
                        add_preference(curr_user, opt_pref);
                    }

                    // Settings (DONE)
                    else if (opt5 == 2) {
                        settings();
                        int opt_setting = -1;
                        do {
                            scanf("%d", &opt_setting);
                            getchar();
                        } while (opt_setting < 1 && opt_setting>3);

                        //Change Username (DONE)
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

                        //Change Password (DONE)
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

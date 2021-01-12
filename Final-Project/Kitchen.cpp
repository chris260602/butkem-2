#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct recipe {
    char name[50][100];
    char description[50][255];
    char ingredient[50][20][50];
    char instruction[50][20][500];
    int  type[50];


    char satuan[50][20][50];
    int  qty[50][20];
    int  total_ins[50];
};

struct bahan {
    char name[100][100];
    int  qty[100];
};

struct user {
    char name[100];
    char pass[100];
    recipe masakan;
    //    bahan  makanan;
    user* next, * prev;
}*headuser, * tailuser;

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
                //            	int lenQty = 3;  //maximal panjang qty
                //            	int lenStr = 2;  //maximal panjang satuan
                //            	if (strcmp(temp->masakan.satuan[i][j], "secukupnya") == 0){
                //            		printf("%d. %*s%s (%s)\n", j + 1
                //											 , lenQty+lenStr+2, ""
                //											 , temp->masakan.ingredient[i][j]
                //											 , temp->masakan.satuan[i][j]);
                //											
                //				} else{
                //					printf("%d. %*d %*s %s\n", j + 1
                //											, lenQty
                //											, temp->masakan.qty[i][j]
                //											, lenStr, temp->masakan.satuan[i][j]
                //											, temp->masakan.ingredient[i][j]);
                //				}
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

//=========================================================
//=========================================================
//=========================================================
struct user user[10];

void start() {

    //	FILE *f;
    //	f = fopen()

        //profile org 1
    strcpy(user[0].name, "Andy");
    strcpy(user[0].pass, "Andy");
    strcpy(user[0].masakan.name[0], "Nasi Goreng");
    strcpy(user[0].masakan.description[0], "nasi goreng yang nikmat dan gurih dibuat dengan rempah pilihan");

    strcpy(user[0].masakan.ingredient[0][0], "telur");
    user[0].masakan.qty[0][0] = 2;
    strcpy(user[0].masakan.satuan[0][0], "btr");

    strcpy(user[0].masakan.ingredient[0][1], "tomat ceri");
    user[0].masakan.qty[0][1] = 3;
    strcpy(user[0].masakan.satuan[0][1], "buah");

    strcpy(user[0].masakan.ingredient[0][2], "kacang polong");
    user[0].masakan.qty[0][2] = 3;
    strcpy(user[0].masakan.satuan[0][2], "sdm");

    strcpy(user[0].masakan.ingredient[0][3], "nasi");
    user[0].masakan.qty[0][3] = 1;
    strcpy(user[0].masakan.satuan[0][3], "piring");

    strcpy(user[0].masakan.ingredient[0][4], "daun bawang");
    user[0].masakan.qty[0][4] = 1;
    strcpy(user[0].masakan.satuan[0][4], "batang");

    strcpy(user[0].masakan.ingredient[0][5], "kerupuk");
    user[0].masakan.qty[0][5] = NULL;
    strcpy(user[0].masakan.satuan[0][5], "secukupnya");

    strcpy(user[0].masakan.ingredient[0][6], "margarin");
    user[0].masakan.qty[0][6] = 1;
    strcpy(user[0].masakan.satuan[0][6], "sdm");

    strcpy(user[0].masakan.ingredient[0][7], "bumbu nasi goreng instan");
    user[0].masakan.qty[0][7] = 1;
    strcpy(user[0].masakan.satuan[0][7], "bungkus");

    strcpy(user[0].masakan.instruction[0][0], "panaskan margarin, lalu masak telur orak-arik");
    strcpy(user[0].masakan.instruction[0][1], "tambahkan bumbu instan, aduk rata, masak hingga harum");
    strcpy(user[0].masakan.instruction[0][2], "masukan nasi, kacang polong, dan daun bawang");
    strcpy(user[0].masakan.instruction[0][3], "sajikan dengan kerupuk");
    user[0].masakan.total_ins[0] = 4;
    //profile org 2
    strcpy(user[1].name, "Budi");
    strcpy(user[1].pass, "Budi");

    strcpy(user[1].masakan.name[0], "Teh Tarik");
    strcpy(user[1].masakan.description[0], "teh tarik dengan racikan khas melepaskan rasa haus dan dahaga");

    strcpy(user[1].masakan.ingredient[0][0], "teh celup");
    user[1].masakan.qty[0][0] = 1;
    strcpy(user[1].masakan.satuan[0][0], "pc");

    strcpy(user[1].masakan.ingredient[0][1], "air panas");
    user[1].masakan.qty[0][1] = 200;
    strcpy(user[1].masakan.satuan[0][1], "ml");

    strcpy(user[1].masakan.ingredient[0][2], "susu kental manis");
    user[1].masakan.qty[0][2] = 30;
    strcpy(user[1].masakan.satuan[0][2], "ml");

    strcpy(user[1].masakan.ingredient[0][3], "es batu");
    user[1].masakan.qty[0][3] = NULL;
    strcpy(user[1].masakan.satuan[0][3], "secukupnya");

    strcpy(user[1].masakan.instruction[0][0], "tambahkan bumbu instan, aduk rata, masak hingga harum");
    strcpy(user[1].masakan.instruction[0][1], "tambahkan es, skm, lalu aduk sampai larut");
    strcpy(user[1].masakan.instruction[0][2], "sajikan");
    user[1].masakan.total_ins[0] = 3;
}

void progress_bar(float progress) {
    if (progress <= 5) {
        printf("[          ] %.2lf%%\n", progress);
    }
    else if (progress <= 15) {
        printf("[#         ] %.2lf%%\n", progress);
    }
    else if (progress <= 25) {
        printf("[##        ] %.2lf%%\n", progress);
    }
    else if (progress <= 35) {
        printf("[###       ] %.2lf%%\n", progress);
    }
    else if (progress <= 45) {
        printf("[####      ] %.2lf%%\n", progress);
    }
    else if (progress <= 55) {
        printf("[#####     ] %.2lf%%\n", progress);
    }
    else if (progress <= 65) {
        printf("[######    ] %.2lf%%\n", progress);
    }
    else if (progress <= 75) {
        printf("[#######   ] %.2lf%%\n", progress);
    }
    else if (progress <= 85) {
        printf("[########  ] %.2lf%%\n", progress);
    }
    else if (progress <= 95) {
        printf("[######### ] %.2lf%%\n", progress);
    }
    else if (progress <= 100) {
        printf("[##########] %.2lf%%\n", progress);
    }
}

int print_all_recipe(struct user* curr) {
    struct user* temp = curr;
    int i = 0, flag = 0, count = 0;
    system("cls || clear");
    printf("List All of Your Recipe\n");
    while (i <= 49) {
        if (temp->masakan.name[i][0] != '\0') {
            printf("%d. %s\n", i + 1, temp->masakan.name[i]);
            flag = 1;
            count++;
        }
        i++;
    }
    return count;
}

int select_recipe(struct user* curr) {
    int opt = 0;
    int max;
    do {
        max = print_all_recipe(curr);
        if (max == 0) {
            puts("No dish available!");
            puts("--------------------------------");
            puts("Please enter to continue");
            getchar();
            opt = 0;
            break;
        }
        puts("--------------------------------");
        puts("Please enter the number");
        scanf("%d", &opt); getchar();
    } while (opt < 1 || opt > max);

    return opt;
}

void ingredients_list(struct user* curr, int opt) {
    system("cls || clear");
    printf("# Ingredients\n");
    int i = 0;
    while (curr->masakan.ingredient[opt - 1][i][0] != '\0' && i < 49) {
        int lenQty = 1;  //maximal panjang qty
        int lenStr = 6;  //maximal panjang satuan
        if (curr->masakan.ingredient[opt - 1][0][0] == '\0') {
            break;
        }
        if (strcmp(curr->masakan.satuan[opt - 1][i], "secukupnya") == 0) {
            printf("%d. %*s%s (%s)\n", i + 1
                , lenQty + lenStr + 2, ""
                , curr->masakan.ingredient[opt - 1][i]
                , curr->masakan.satuan[opt - 1][i]);

        }
        else {
            printf("%d. %*d %*s %s\n", i + 1
                , lenQty
                , curr->masakan.qty[opt - 1][i]
                , lenStr, curr->masakan.satuan[opt - 1][i]
                , curr->masakan.ingredient[opt - 1][i]);
        }
        i++;
    }
    puts("--------------------------------");
    puts("Press enter to start cooking");
    getchar();
    return;
}

void cooking(struct user* curr, int opt) {
    int progress = 0;
    float end_progress = curr->masakan.total_ins[opt - 1];
    int i = 0;
    while (i < 19 && curr->masakan.instruction[opt - 1][i][0] != '\0') {
        system("cls || clear");
        printf("Step %d   ", i + 1);
        progress_bar((i + 1) / end_progress * 100);
        printf("%s\n", curr->masakan.instruction[opt - 1][i]);
        printf("\n\n\n--------------------------------\n");
        printf("Press \"<\" to step back, \">\" to next, \"s\" to stop\n");
        char nav;
        do {
            printf(">> ");
            scanf("%s", &nav); getchar();
        } while (nav != '<' && nav != '>' && nav != 's');

        switch (nav)nav : {
        case '<':
            i--;
            break;
        case '>':
            i++;
            break;
        case 's':
            i = 20;
            break;
        default:
            break;
        }

    }
}

void Kitchen(struct user* curr) {
    int opt = select_recipe(curr);
    if (opt == 0) return;
    ingredients_list(curr, opt);
    cooking(curr, opt);
}

int main() {
    struct user* curr_user;
    // input data
    start();
    curr_user = &user[0];
    int opt1 = 3;
    //fungsi kitchen
    if (opt1 == 3) {
        Kitchen(curr_user);
    }
}
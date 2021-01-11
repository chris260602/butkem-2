





struct recipe {
    char name[50][100];
    char description[50][255];
    char ingredient[50][20][50];
    char instruction[50][500];
};

struct user {
    char name[100];
    char pass[100];
    recipe masakan;
    user* next, * prev;
}*headuser, * tailuser;

struct dish {
    char name[100];
    dish* next, * prev;
}*headdish, * taildish;


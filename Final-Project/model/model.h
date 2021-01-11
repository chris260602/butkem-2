





struct recipe {
    char name[50][100];
    char description[50][255];
    char ingredient[50][20][50];
    char instruction[50][500];
};
struct bahan {
    char name[100][100];
    int qty[100];
};
struct user {
    char name[100];
    char pass[100];
    recipe masakan;
    bahan makanan;
    user* next, * prev;
}*headuser, * tailuser;




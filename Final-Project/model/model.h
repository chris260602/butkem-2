struct recipe {
    char name[50][100];
    char description[50][255];
    char ingredient[50][20][50];
    char instruction[50][500]; 
    int type[50];
    
    char satuan [50][ 20][ 50];
    int  qty [50][ 20];
    int  total_ins [50];
};
struct recipe {	struct recipe {
    char name[50][100];
    char description[50][255];
    char ingredient[50][20][50];
    char instruction[50][500]; 
    int type[50];

struct bahan {
    char name[100][100];
    int qty[100];
};

struct global_recipe {
    char name[100];
    char description[255];
    char ingredient[20][50];
    char instruction[500];
    int type;
    global_recipe* next, * prev;
}*head_global, * tail_global;
struct user {
    char name[100];
    char pass[100];
    int preference;
    recipe masakan;
    bahan makanan;
    user* next, * prev;
}*headuser, * tailuser;




#include<stdio.h>
#include<stdlib.h>


struct node {
    int value;
    node* next;
}*head, * tail;

node* createnode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
}

void pushhead(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void pushtail(int value) {
    node* temp = createnode(value);
    if (!tail) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void pushmid(int value) {
    if (!head) {
        node* temp = createnode(value);
        head = tail = temp;
    }
    else if (value >= head->value) {
        pushhead(value);
    }
    else if (value <= tail->value) {
        pushtail(value);
    }
    else {
        node* temp2 = createnode(value);
        node* temp = head;
        while (temp->next && temp->next->value > value) {
            temp = temp->next;
        }
        temp2->next = temp->next;
        temp->next = temp2;
    }
}

void print() {
    if (head == NULL) {
        printf("No head\n");
        return;
    }
    node* temp = head;
    while (temp) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    puts("");
}

void find() {
    int panjang = 1;
    node* temp = head;
    if (!head) {
        return;
    }
    while (temp->next) {
        panjang++;
        temp = temp->next;
    }
    panjang = (panjang) / 2;
    node* temp2 = head;
    while (panjang > 0) {
        temp2 = temp2->next;
        panjang--;
    }
    printf("Nilai dari Node Tengah adalah: %d\n", temp2->value);
}

int main() {
    pushhead(10);
    pushhead(20);
    pushhead(30);
    pushhead(40);
    pushhead(50);
    print();
    find();


    return 0;
}
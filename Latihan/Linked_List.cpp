#include<stdio.h>
#include<stdlib.h>

struct node {
    int nilai;
    node* next;
}*head = NULL, * tail = NULL;

node* createnode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->nilai = value;
    temp->next = NULL;
    return temp;
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
    else if (value >= head->nilai) {
        pushhead(value);
    }
    else if (value <= tail->nilai) {
        pushtail(value);
    }
    else {
        node* temp2 = createnode(value);
        node* temp = head;
        while (temp->next && temp->next->nilai > value) {
            temp = temp->next;
        }
        temp2->next = temp->next;
        temp->next = temp2;
    }
}

void pophead() {
    if (!head) {
        return;
    }
    else if (head == tail) {
        free(head);
        head = tail = NULL;
    }
    else {
        node* temp = head->next;
        free(head);
        head = temp;
    }
}

void poptail() {
    if (!tail) {
        return;
    }
    else if (head == tail) {
        free(head);
        head = tail = NULL;
    }
    else {
        node* temp = head;
        while (temp && temp->next != tail) {
            temp = temp->next;
        }
        free(tail);
        temp->next = NULL;
        tail = temp;
    }
}

void popmid(int value) {
    if (!head) {
        return;
    }
    else {
        if (head->nilai == value) {
            pophead();
        }
        else if (tail->nilai == value) {
            poptail();
        }
        else {
            node* temp = head;
            while (temp->next && temp->next->nilai != value) {

                temp = temp->next;
            }
            if (temp->next == NULL) {
                return;
            }
            temp->next = temp->next->next;
            temp->next->next = NULL;
        }
    }
}

void popall() {
    while (head) {
        pophead();
    }
}
void print() {
    if (head == NULL) {
        printf("No head\n");
        return;
    }
    node* temp = head;
    while (temp) {
        printf("%d ", temp->nilai);
        temp = temp->next;
    }
    puts("");
}

int main() {
    pushhead(10);
    pushhead(1000);
    pushtail(10);
    pushtail(10);
    pushhead(1000);
    pushtail(20);
    pushhead(1000);
    pushtail(20);
    print();
    pophead();
    poptail();
    popmid(10000);
    popall();
    print();

    return 0;
}


#include<stdio.h>
#include<stdlib.h>

struct node {
    int nilai;
    node* prev, * next;
}*head = NULL, * tail = NULL;

node* createnode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->nilai = value;
    temp->next = temp->prev = NULL;
    return temp;
}

void pushhead(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
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
        temp->prev = tail;
        tail = temp;
    }
}

void pushmid(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = tail = temp;
    }
    else {
        if (head->nilai < value) {
            pushhead(value);
        }
        else if (tail->nilai >= value) {
            pushtail(value);
        }
        else {
            node* curr = head;
            while (curr->next && curr->next->nilai > value) {
                curr = curr->next;
            }
            if (curr == NULL) {
                return;
            }
            curr->prev->next = temp;
            temp->prev = curr->prev;
            temp->next = curr;
        }
    }
}

void printawal() {
    if (!head) {
        return;
    }
    else {
        node* curr = head;
        while (curr) {
            printf("%d -> ", curr->nilai);
            curr = curr->next;
        }
        puts("");
    }
}

void printakhir() {
    if (!tail) {
        return;
    }
    else {
        node* curr = tail;
        while (curr) {
            printf("%d -> ", curr->nilai);
            curr = curr->prev;
        }
        puts("");
    }
}

int main() {
    pushhead(10);
    pushmid(10);
    printawal();

    return 0;
}
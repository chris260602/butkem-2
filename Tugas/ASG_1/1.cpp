#include<stdio.h>
#include<stdlib.h>

struct node {
    int nilai;
    node* next;
}*head, * tail;

node* createnode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->nilai = value;
    temp->next = NULL;
    return temp;
}

void push(int value, node** curr_node) {
    node* temp = createnode(value);
    temp->next = *curr_node;
    *curr_node = temp;
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
void swap(node* node1, node* node2) {
    node* temp1 = node1, * temp2 = node2;
    while (temp1 && temp2) {
        if (temp1->nilai > temp2->nilai) {
            // push(temp2->nilai, final);
            pushtail(temp2->nilai);
            temp2 = temp2->next;
        }
        else {
            // push(temp1->nilai, final);
            pushtail(temp1->nilai);
            temp1 = temp1->next;
        }
    }
    while (temp1) {
        // push(temp1->nilai, final);
        pushtail(temp1->nilai);
        temp1 = temp1->next;
    }
    while (temp2) {
        // push(temp2->nilai, final);
        pushtail(temp2->nilai);
        temp2 = temp2->next;
    }
}

void print(node* curr_node) {
    while (curr_node) {
        if (curr_node->next == NULL) {
            printf("%d\n", curr_node->nilai);
            curr_node = curr_node->next;
        }
        else {
            printf("%d -> ", curr_node->nilai);
            curr_node = curr_node->next;
        }
    }
}

int main() {
    node* a = NULL;
    node* b = NULL;
    push(30, &a);
    push(20, &a);
    push(10, &a);
    print(a);
    push(60, &b);
    push(50, &b);
    push(40, &b);
    print(b);
    swap(a, b);
    print(head);

    return 0;
}
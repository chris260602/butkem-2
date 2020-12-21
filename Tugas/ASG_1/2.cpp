#include<stdio.h>
#include<stdlib.h>
struct node {
    int value;
    bool visit;
    node* next;
}*head;

node* createnode(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void push(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void pushVIP(int value) {
    node* temp = createnode(value);
    if (!head) {
        head = temp;
    }
    else {
        node* curr_node = head;
        while (curr_node->next) {
            curr_node = curr_node->next;
        }
        curr_node->next = temp;
        temp->next = head;
    }
}

bool find() {
    if (!head) {
        return true;
    }
    else {
        node* temp = head;
        while (temp) {
            if (temp->visit == false) {
                temp->visit = true;
                temp = temp->next;
            }
            else if (temp->visit == true) {
                return false;
            }
        }
        return true;
    }
}

void print() {
    node* curr_node = head;
    while (curr_node) {
        if (curr_node->visit == true) {
            return;
        }
        if (curr_node->next == NULL) {
            printf(" %d ", curr_node->value);
            curr_node->visit = true;
            curr_node = curr_node->next;
        }
        else {
            printf(" %d ", curr_node->value);
            curr_node->visit = true;
            curr_node = curr_node->next;
        }
    }
    puts("");
}

int main() {
    push(10);
    pushVIP(20);
    push(30);
    print();
    if (find() == true) {
        puts("\nTidak ada Cycle");
    }
    else {
        puts("\nAda Cycle");
    }
    return 0;
}
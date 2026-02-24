#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    double value;
    struct Node* next;
} Node;

Node* createNode(double value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation fehlgeschlagen\n");
        return NULL;
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int main(){
    Node* head = NULL;
    Node* current = NULL;

    for(int i = 0; i < 50; i++){
        Node* newNode = createNode((double)i);
        if(head == NULL){
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    srand(time(NULL));
    int array[51];
    for(int i = 0; i < 50; i++){
        array[i] = rand();
    }

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

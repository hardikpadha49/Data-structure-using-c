#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* top = NULL;

Node* createNode(int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode;
}

void push(int ele) {
    Node* newNode = createNode(ele);
    if (newNode == NULL) {
        printf("Stack Overflow!!!!\n");
    } else {
        newNode->next = top;
        top = newNode;
        printf("Node Inserted: %d\n", ele);
    }
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty!!!\n");
    } else {
        Node* temp = top;
        printf("Deleted Element: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty!!!!\n");
    } else {
        printf("Top Element: %d\n", top->data);
    }
}

void show() {
    if (top == NULL) {
        printf("Stack is empty!!!!\n");
    } else {
        Node* temp = top;
        printf("Stack Elements:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Show\n5. Exit\n");
        int choice, ele;
        printf("Enter the choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!!!!!\n");
        }
    }

    return 0;
}

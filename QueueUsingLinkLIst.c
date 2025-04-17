#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* front = NULL;
Node* rear = NULL;

Node* createNode(int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode;
}

void Enqueue(int ele) {
    Node* newNode = createNode(ele);
    if(newNode==NULL)
    printf("Queue is full!!!\n");
    else if (rear == NULL) {
     front = rear = newNode;
    } else {
    rear->next = newNode;
     rear = newNode;
    }
    printf("Inserted: %d\n", ele);
}

void Dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = front;
    front = front->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    if (front == NULL) {
        rear = NULL;
    }
}

void Peek() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

void Display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, ele;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                Enqueue(ele);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

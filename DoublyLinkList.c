#include <stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* Head = NULL;

struct Node* CreateNode(int ele){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = ele;
    temp->prev = temp->next = NULL;
    return temp;
}
void InsretNodeInHead(int ele){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = ele;
    newnode->next = Head;
    newnode->prev = NULL;
    if(Head!=NULL){
    Head->prev = newnode;
    }
    Head = newnode;
}
void InsertNodeAtEnd(int ele){
    struct Node* newNode = CreateNode(ele);
        newNode->data=ele;
        newNode->next = NULL;
        struct Node* temp=Head;
        if(Head==NULL){
            Head=newNode;
        }
        else{
        while(temp->next!=NULL){
           temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        }
         printf("Inserted!!!\n");
}
void InsertNodeAtAny(int ele,int pos){
if(Head==NULL)
        printf("List is empty!!!\n");
       else if(pos==1){
        insertNodeInBeg(ele);
       }
       else{
        struct Node* newNode = createNode(ele);
       struct Node* temp = Head;
        int i = 1;
        while(i<pos&&temp!=NULL){
            temp = temp->next;
            i++;
        }
    if(temp!= NULL&&i>0){
        newNode->next=temp->next;
        temp->prev->next = newNode;
        newNode->next=temp;
        temp->prev=newNode;
    printf("Node Inserted !!!!\n");
       
    }
    else{
    printf("Invalid Possition!!!\n");
    }
   
    }
}
void DeleteAtHead(){
    if (Head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = Head;
    Head = Head->next; 
    Head->prev = NULL; 
    free(temp); 
    printf("Node deleted from beginning.\n");
}
void DeleteFromEnd(){
    if (Head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (Head->next == NULL) {
        free(Head);
        Head = NULL;
        printf("Last node deleted.\n");
        return;
    }
    struct Node* temp = Head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);

    printf("Last node deleted.\n");
}
void DeleteAtAny(int pos){
    if (Head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = Head;
    int i = 1;
    if (pos == 1) {
        Head = Head->next;
        if (Head != NULL) {
            Head->prev = NULL;
        }
        free(temp);
        printf("Node deleted from position \n");
        return;
    }
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node deleted from position %d.\n", pos);
}
void searching(int value){
    if(Head==NULL)
        printf("List is empty!!!\n");
        else{
           struct Node* temp = Head;
            while(temp!=NULL){
                if(temp->data==value){
                    printf("Found!!!!\n");
                    return;
                }
                temp=temp->next;
            }
            printf("Not Found!!!\n");
        }
}
void display(){
     if(Head==NULL)
        printf("List is Empty!!!\n");
        else{
            printf("Elements are: \n");
            struct Node* temp=Head;
            while(temp!=NULL){
                printf("%d ",temp->data);
                temp = temp->next;
            }
        }
}
int main(){
system("cls");
    while(1){
        printf("\n---------Doubly Linked List---------\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Searching in List\n8. Sort Elements\n9. Display\n10. Exit\n");
        int choice,value,pos;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            printf("Enter the value : ");
            scanf("%d",&value);
            insertNodeInBeg(value);
            break;
            case 2:
             printf("Enter the value at the end = ");
            scanf("%d",&value);
            insertNodeAtEnd(value);
            display();
            break;
            case 3:
            printf("Enter the value = ");
            scanf("%d",&value);
            printf("Enter the position = ");
            scanf("%d",&pos);
            insretNodeAtAnyPostion(value,pos);
            break;
            case 4:
            DeleteNodeAtHead();
            break;
            case 5:
            DeleteNodeAtEnd();
            break;
            case 6:
            printf("Enter the Position = ");
            scanf("%d",&pos);
            DeleteAtAny(pos);
            break;
            case 7:
            printf("Enter the value = ");
            scanf("%d",&value);
            searching(value);
            break;
            case 8:
            sorting();
            break;
            case 9:
            display();
            break;
            case 10:
            exit(0);
            break;
            default:
            printf("Invalid choice\n");
            break;
        }
        printf("\n");
    }
    return 0;
}
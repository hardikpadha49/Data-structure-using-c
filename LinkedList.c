#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;}Node;
    Node* Head=NULL;
    Node* createNode(int ele){
           Node* newNode = (Node*)malloc(sizeof(Node));/*this was a step no one*/
        newNode->data=ele;
        newNode->next = NULL;
        return newNode;
    }
    void insertNodeInBeg(int ele){
        Node* newNode = (Node*)malloc(sizeof(Node));/*this was a step no one*/
        newNode->data=ele;
        newNode->next = NULL;
        newNode->next=Head;
        Head = newNode;
        printf("Node Inserted !!!!\n");
    }
    void insertNodeAtEnd(int ele){
        Node* newNode = (Node*)malloc(sizeof(Node));/*this was a step no one*/
        newNode->data=ele;
        newNode->next = NULL;
        Node* temp=Head;
        if(Head==NULL){
            Head=newNode;
        }
        else{
        while(temp->next!=NULL){
           temp=temp->next;
        }
        temp->next=newNode;
        }
         printf("Inserted!!!\n");
    }
    void insretNodeAtAnyPostion(int ele,int pos){
        if(Head==NULL)
        printf("List is empty!!!\n");
       else if(pos==1){
        insertNodeInBeg(ele);
       }
       else{
        Node* newNode = createNode(ele);
        Node* temp = Head;
        int i = 1;
        while(i<pos-1&&temp->next!=NULL){
            temp = temp->next;
            i++;
        }
    if(temp->next != NULL&&i>1){
        newNode->next = temp->next;
    temp->next=newNode;
    printf("Node Inserted !!!!\n");
       
    }
    else{
    printf("Invalid Possition!!!\n");
    }
   
    }

    }
    void DeleteNodeAtHead(){
       if(Head==NULL)
       printf("list is empty!!!\n");
        Node* temp = Head;
        Head = Head->next;
        free(temp);
        printf("Element Deleted!!!!\n");
    }
    void DeleteAtAny(int pos){
        if(Head==NULL)
        printf("List is empty!!!\n");
        else if(pos==1)
        DeleteNodeAtHead();
        else{
            int i =1;
            Node* temp=Head;
            while(i<pos-1&&temp->next!=NULL){
                i++;
                temp = temp->next;
            }
            if(temp->next!=NULL&&pos>0){
                Node* t = temp->next;
                temp->next = temp->next->next;
                free(t);
                printf("Node Deleted!!!\n");
            }
            else
            printf("Invlaid position!!!\n");
        }
    }
    void DeleteNodeAtEnd(){
        if(Head==NULL)
        printf("List is empty\n");
        else{
            Node* temp = Head;
            if(Head->next==NULL){
                 temp=Head;
                 Head=NULL;
            }
            else{
                 Node* temp = Head;
             while (temp->next->next != NULL) {
        temp = temp->next;
             }   
    free(temp->next);
    temp->next = NULL;
            }
             free(temp->next);
              printf("Element Deleted!!!!\n");
}
    }
     void searching(int value){
        if(Head==NULL)
        printf("List is empty!!!\n");
        else{
            Node* temp = Head;
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
            Node* temp=Head;
            while(temp!=NULL){
                printf("%d ",temp->data);
                temp = temp->next;
            }
        }
    }
    void sorting() {
    if (Head == NULL || Head->next == NULL) {
        printf("List is empty or already sorted!\n");
        return;
    }

    Node *temp1, *temp2, *last=NULL;
    int temp;

    for (temp1 = Head; temp1->next != NULL; temp1 = temp1->next) {
        for (temp2 = Head; temp2->next != last ; temp2 = temp2->next) {
            if (temp1->data > temp2->data) {
                temp = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp;
            }
        }
        last = temp2;
    }
    printf("List sorted!\n");
}

int main(){
system("cls");
    while(1){
        printf("\n---------Singly Linked List---------\n");
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
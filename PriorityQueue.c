#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 100
int front = -1, rear = -1, queue[size];
typedef struct PrimorityQueue{
    int element;
    int priority;
}PQueue;
PQueue pq[size];
int isempty(){
    return (front == -1) ? 1 : 0;
}
int isfull()
{
    return ((rear + 1) % size == front) ? 1 : 0;
}
void enqueue(int data, int priority)
{
    rear = rear+1;
    pq[rear].element=data;
    pq[rear].priority=priority;
    if(front==-1)
    front=rear;
    printf("Element Inserted!!!\n");
}
int getHigherPriorityElement(){
    int max = 0,index=-1;
    for(int i=front;i<=rear;i++){
        if(pq[i].priority>max){
            max=pq[i].priority;
            index=i;
        }
    }
    return index;
}
int dequeue()
{
  int index = getHigherPriorityElement();
  int data = pq[index].element;
  if(index==front && index==rear)
  front = rear = -1;
  else if(index==front)
  front++;  
  else{
     for(int i = index;i<rear;i++){
    pq[i]=pq[i+1];
  }
  rear--;
  }
  return data;
}
void peek()
{ // front
int i = getHigherPriorityElement();
printf("Element:%d => Priority: %d",pq[i].element,pq[i].priority);
}
void display()
{
 printf("Element are :\n");
 for(int i=front;i<=rear;i++){
    printf("Element id %d => Prority :%d\n",pq[i].element,pq[i].priority);
 }
}
int main()
{
    system("clear");
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice, data,p;
        printf("Enter the choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isfull())
                printf("Queue Overflow!!!\n");
            else
            {
                printf("Enter the element :");
                scanf("%d", &data);
                printf("Enter the proirty :");
                scanf("%d", &p);
                enqueue(data,p);
            }
            break;
        case 2:
            if (isempty())
                printf("Queue Underflow!!!!\n");
            else
                printf("%d Dequeue from the queue\n", dequeue());
            break;
            break;
        case 3:
            if (isempty())
                printf("Queue Empty!!!!\n");
            else
                peek();
            break;
        case 4:
            if (isempty())
                printf("Queue Empty!!!!\n");
            else
                display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice !!!\n");
        }
        printf("\n");
    }
    return 0;
}
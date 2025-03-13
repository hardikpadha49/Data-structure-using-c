#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 100
int front = -1, rear = -1, queue[size];
int isempty()
{
    return (front == -1) ? 1 : 0;
}
int isfull()
{
    return ((rear + 1) % size == front) ? 1 : 0;
}
void enqueue(int data)
{
    rear = (rear + 1) % size;
    queue[rear] = data;
    if (front == -1)
        front = rear;
    printf("Element is inserted!!!!!\n");
}
int dequeue()
{
    int data = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
    return data;
}
int peek()
{ // front
    return queue[front];
}
void display()
{
  int i = front;
  while (i!=rear)
  {
printf("%d ",queue[i]);
i=(i+1)%size;
}
printf("%d",queue[rear]);
  
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
        int choice, data;
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
                enqueue(data);
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
                printf("Element avalaible at the front is %d\n", peek());
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
//stack program
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define Max 100
int stack[Max],top=-1;
int isEmpty(){
    return (top == -1)? 1:0;
}
int isFull(){
    return (top == Max-1) ? 1:0;
}
void push(){
    if(isFull()){
        printf("stack overflow!!!!\n");
    }
    else{
    int value;
    printf("enter the value = ");
    scanf("%d",&value);
    top++;
    stack[top]=value;
    printf("Element added !!!\n");
    }
}
int pop(){
    if(isEmpty()){
        printf("stack underflow!!!\n");
        return INT_MIN;
    }
    else{
        int val=stack[top];
        top--;
        return val;
    }
}
int peek(){
    if(isEmpty()){
        printf("stack is empty!!\n");
        return INT_MIN;
    }
    else{
        return stack[top];
    }
}
void show(){
    if(isEmpty()){
        printf("stack is empty !!!\n");
    }
    else{
        for(int i =top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
int main (){
    int n,res,ele;
    int choice;
    
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Show\n5.Exit");
         printf("\nEnter the choice = ");
     scanf("%d",&choice);
    switch(choice){
        case 1:
        push();
        break;
        case 2:
        res = pop();
        if(res != INT_MIN)
        printf("%d is pop from the stack\n",res);
        break;
        case 3:
       ele=peek();
        if(ele != INT_MIN)
        printf("Top element is %d",ele);
        break;
        case 4:
        show();
        break;
        case 5:
        exit(0);
        default:
        printf("Invalid choice !!!\n");
    }
    }
        
    printf("\n");
    return 0;
}
//multiple stack 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
int stack[MAX],top1=-1,top2=MAX;
int stack1isEmpty(){
    return (top1 == -1)? 1:0;
}
int stack2isEmpty(){
    return (top2 == MAX)? 1:0;
}
int stack1isFull(){
    return (top1 == top2-1) ? 1:0;
}
int stack2isFull(){
    return (top2 == top1+1) ? 1:0;
}
void pushstack1(){
    if(stack1isFull()){
        printf("Stack overflow!!!\n");
    }
    else{
        int value;
    printf("enter the value = ");
    scanf("%d",&value);
    stack[++top1]=value;
    printf("Element added !!!\n");
    }
}
void pushstack2(){
    if(stack2isFull()){
        printf("stack overflow!!!!\n");
    }
    else{
    int value;
    printf("enter the value = ");
    scanf("%d",&value);
     stack[--top2]=value;
    printf("Element added !!!\n");
    }
}
void popstack1(){
    if(stack1isEmpty()){
        printf("stack underflow!!!\n");
        return ;
    }
    else{
        top1--;
        printf("%d Element is pop!!!\n",stack[top1]);
    }
}
void popstack2(){
    if(stack2isEmpty()){
        printf("stack underflow!!!\n");
        return ;
    }
    else{
       
        printf("%d Element is pop!!!\n",stack[top2]);
         top2++;
    }
}
void peekstack1(){
    if(stack1isEmpty()){
        printf("stack is empty!!\n");
        return;
    }
    else{
        printf("%d is top element\n",stack[top1]);
    }
}
void peekstack2(){
    if(stack2isEmpty()){
        printf("stack is empty!!\n");
        return ;
    }
    else{
        printf("%d is top element\n",stack[top2]);
    }
}
void showstack1(){
    if(stack1isEmpty()){
        printf("stack is empty !!!\n");
    }
    else{
        for(int i =top1;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
void showstack2(){
    if(stack2isEmpty()){
        printf("stack is empty !!!\n");
    }
    else{
        for(int i =top2;i<MAX;i++){
            printf("%d\n",stack[i]);
        }
    }
}
int main (){
    int choice,n;
    while(1){
        printf("\n1.Push from stack1\n2.Pop from stack1\n3.Peek from stack1\n4.Show from stack1");
        printf("\n5.Push from stack2\n6.Pop from stack2\n7.Peek from stack2\n8.Show from stack2\n9.Exit");
         printf("\nEnter the choice = ");
     scanf("%d",&choice);
    switch(choice){
        case 1:
        pushstack1();
        break;
        case 2:
        popstack1();
        break;
        case 3:
       peekstack1();
        break;
        case 4:
        showstack1();
        break;
        case 5:
        pushstack2();
        break;
        case 6:
        popstack2();
        break;
        case 7:
       peekstack2();
        break;
        case 8:
        showstack2();
        break;
        case 9:
        exit(0);
        default:
        printf("Invalid choice !!!\n");
    }
    }
        
    printf("\n");
    return 0;
}
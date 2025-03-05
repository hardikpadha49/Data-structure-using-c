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
    scanf("%d",&value);
    top++;
    stack[top]=value;
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
push();
push();
push();
pop();
push();
push();
pop();
pop();
pop();
show();
    return 0;
}
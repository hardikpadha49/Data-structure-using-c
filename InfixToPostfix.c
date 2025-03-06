#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int precedence(char opr){
    switch(opr){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        default:
        return -1;
    }
}
char* convertinfixtopostfix(char* exp){
    int size =strlen(exp),top=-1,index=0;
    char* str=(char*)malloc(size+1);
    char stack[size];
    for(int i=0;i<size;i++){
        char ch=exp[i];
        if(isalnum(ch)){
            str[index++]=ch;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            if(top==-1)
            stack[++top]=ch;
            else{
                while(top!=-1 && precedence(ch)<=precedence(stack[top])){
                    str[index++]=stack[top--];
                }
                stack[++top]=ch;
            }
        }
        else if(ch=='('){
            stack[++top]=ch;
        }
        else if(ch==')'){
            while(stack[top]!='('){
                str[index++]=stack[top--];
            }
            top--;
        }
    }
    while (top!=-1)
    {
       str[index++]=stack[top--];
    }
    str[index]='\0';
    return str;
}
int main(){
    char exp[100];
    printf("Enter the infix expression = ");
    gets(exp);
    printf("Postfix form fo infix Expression %s is %s\n",exp,convertinfixtopostfix(exp));
    return 0;
}
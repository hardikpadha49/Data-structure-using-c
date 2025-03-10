#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
char* convertPostfixToInfix(char* exp){
    int size=strlen(exp),top=-1,temp;
    char stack[size][100];
    for(int i=0;i<size;i++){
        char ch=exp[i];
        if(isalnum(ch)){
            char temp[]={ch,'\0'};
            strcpy(stack[++top],temp);
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            char *s1=stack[top--];
            char *s2=stack[top--];
            char s3[100];
            snprintf(s3,100,"(%s%c%s)",s2,ch,s1);
            strcpy(stack[++top], s3);
        }
    }
    char *s=(char*)malloc(strlen(stack[top])+1);
    strcpy(s,stack[top]);
    return s;
}
char* convertPrefixToInfix(char* exp){
   int size=strlen(exp),top=-1;
    char stack[size][100];
    for(int i =size;i>=0;i--){
        char ch=exp[i];
        if(isalnum(ch)){
            char temp[]={ch,'\0'};
            strcpy(stack[++top],temp);
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            char *s1=stack[top--];
            char *s2=stack[top--];
            char s3[100];
            snprintf(s3,100,"(%s%c%s)",s1,ch,s2);
              strcpy(stack[++top], s3);
        }
    }
    char *s=(char*)malloc(strlen(stack[top])+1);
    strcpy(s,stack[top]);
    return s;
}
int main (){
    system("clear");
    char exp[100];
    printf("Enter the expression = ");
    gets(exp);
    char* infixPostfix = convertPostfixToInfix(exp);
    printf("Infix form of Postfix expression  is %s\n",infixPostfix);
    printf("Enter the expression = ");
    gets(exp);
    char* infixPrefix = convertPrefixToInfix(exp);
    printf("Infix form of Prefix expression  is %s\n",infixPrefix);
    return 0;
}

//infix form,post fix,prefix form
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int top1 = -1,top2=-1;
int operand[100];
char operator[100];
void doprocess(){
    int x= operand[top1--];
    int y= operand[top1--];
    int z;
    char opr = operator[top2--];
    switch (opr)
    {
        case '+':
        z=y+x;
        break;
        case '-':
        z=y-x;
        break;
        case '*':
        z=y*x;
        break;
        case '/':
        z=y/x;
        break;
        case '^':
        z=pow(y, x);
        break;
    }
    operand[++top1]=z;
}
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
int evalinflixexpression(char *exp){
int size = strlen(exp);
for(int i =0;i<size;i++){
    char ch = exp[i];
    if(isdigit(ch)){
       int num =0;
       while (isdigit(exp[i]))
       {
        num = num*10+exp[i]-48;
        i++;
       }
       i--;
       operand[++top1]=num;
    }
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            while(top2!=-1 &&precedence(ch)<=precedence(operator[top2])){
            doprocess();
            }
        
        operator[++top2]=ch;
    }
    else if(ch=='('){
        operator[++top2]=ch;
    }
    else if(ch==')'){
        while(operator[top2]!='('){
            doprocess();
        }
        top2--;
    }
}
while(top2!=-1){
    doprocess();
}
return operand[top1--];
}
int evalpostflixexpression(char *exp){
int size = strlen(exp);
for(int i =0;i<size;i++){
    char ch = exp[i];
    if(isdigit(ch)){
       int num =0;
       while (isdigit(exp[i]))
       {
        num = num*10+exp[i]-48;
        i++;
       }
       i--;
       operand[++top1]=num;
    }
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            int x= operand[top1--];
            int y= operand[top1--];
            int z;
            switch(ch){
                 case '+':
                 z=y+x;
                break;
                case '-':
                z=y-x;
                 break;
                case '*':
                z=y*x;
                break;
                case '/':
                z=y/x;
                break;
                case '^':
                z=pow(y, x);
                break;
            }
            operand[++top1]=z;
    }
}
return operand[top1--];
}
int evalpreflixexpression(char *exp){
int size = strlen(exp);
for(int i =size;i>=0;i--){
    char ch = exp[i];
    if(isdigit(ch)){
       int num =0;
       while (isdigit(exp[i]))
       {
        num = num*10+exp[i]-48;
        i++;
       }
       i--;
       operand[++top1]=num;
    }
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            int x= operand[top1--];
            int y= operand[top1--];
            int z;
            switch(ch){
                 case '+':
                 z=y+x;
                break;
                case '-':
                z=y-x;
                 break;
                case '*':
                z=y*x;
                break;
                case '/':
                z=y/x;
                break;
                case '^':
                z=pow(y, x);
                break;
            }
            operand[++top1]=z;
    }
}
return operand[top1--];
}
int main() {
    system("clear");
char str[100];
printf("Enter infix expression = ");
gets(str);
printf("Result = %d\n",evalinflixexpression(str));
printf("\nEnter postfix expression = ");
gets(str);
printf("Result = %d\n",evalpostflixexpression(str));
printf("\nEnter prefix expression = ");
gets(str);
printf("Result = %d\n",evalpreflixexpression(str));

return 0;
}
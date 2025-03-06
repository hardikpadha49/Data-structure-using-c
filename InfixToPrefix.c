#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int precedence(char opr) {
    switch (opr) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}
char* reverseStr(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}\
char* convertInfixToPrefix(char* exp) {
    int size = strlen(exp), top = -1, index = 0;
    char* str = (char*)malloc(size + 1);
    char stack[size];
    reverseStr(exp);
    for (int i = 0; i < size; i++) {
        char ch = exp[i];

        if (isalnum(ch)) {  
            str[index++] = ch;
        } 
        else if (ch == ')') {  
            stack[++top] = ch;
        } 
        else if (ch == '(') {  
            while (top != -1 && stack[top] != ')') {
                str[index++] = stack[top--];
            }
            top--;  
        } 
        else {  
            while (top != -1 && precedence(ch) < precedence(stack[top])) {
                str[index++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {  
        str[index++] = stack[top--];
    }
    str[index] = '\0';
    reverseStr(str);
    return str;
}
int main() {
    char exp[100];
    printf("Enter the infix expression: ");
    gets(exp);

    printf("Prefix form of infix expression is %s\n", convertInfixToPrefix(exp));
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ip(char ch) {
    if(ch == '+' || ch == '-')
        return 2;
    if(ch == '/' || ch == '*')
        return 3;
    if(ch == '(')
        return 9;
    return 0; // Default case
}

int sp(char ch) {
    if(ch == '+' || ch == '-')
        return 2;
    if(ch == '/' || ch == '*')
        return 3;
    if(ch == '(')
        return 0;
    if(ch == '#')
        return -1;
    return 0; // Default case
}

int main(){
    char exp[30];
    char stk[10];
    int top=0;
    stk[top] = '#';
    printf("Enter the expression: ");
    fgets(exp, sizeof(exp), stdin);
    
    for (int i = 0; exp[i] != '\0';i++){
        if(exp[i] == '*'||exp[i]=="/"|| exp[i] == "+"|| exp[i] == "-"){
            if(ip(exp[i])>sp(stk[top])){
                stk[++top] = exp[i];
            }
            else{
                while(ip(exp[i])<=sp(stk[top])){
                    printf("%c", stk[top--]);
                }
                stk[++top] = exp[i];
            }
        }
        else if(exp[i] == '(') {
            stk[++top] = exp[i];
        }
        else if(exp[i] == ')') {
            while(stk[top] != '(') {
                printf("%c", stk[top--]);
            }
            top--; // Discard "()" from stack
        }
        else{
            printf("%c", exp[i]);
        }
    }
    
    while(stk[top] != '#') {
        printf("%c", stk[top--]);
    }
    return 0;
}

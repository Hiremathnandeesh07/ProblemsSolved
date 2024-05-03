#include<stdio.h>
int main(){
    int stk[20], top = -1, op1, op2;
    char exp[30];
    scanf("%s", exp);
    int i = 0;
    while(exp[i]!='\0'){
        if(exp[i]<='0'&&exp[i]<='9'){
            stk[++top] = exp[i] - '0';
        }
        else{
            op2 = stk[top--];
            op1 = stk[top--];
        
        switch(exp[i]){
            case '+':
                stk[++top] = op1 + op2;
                break;
            case '-':
                stk[++top] = op1 - op2;
                break;
            case '*':
                stk[++top] = op1 * op2;
                break;
            case '/':
                stk[++top] = op1 / op2;
                break;
        }
    }
    i++;
    }
    printf("%d", stk[top]);
}
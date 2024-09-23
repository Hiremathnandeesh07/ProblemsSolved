#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to get the input precedence of operators
int ip(char ch) {
    if (ch == '+' || ch == '-')
        return 2;
    if (ch == '/' || ch == '*')
        return 3;
    if (ch == '(')
        return 9;
    return 0; // Default case for other characters
}

// Function to get the stack precedence of operators
int sp(char ch) {
    if (ch == '+' || ch == '-')
        return 2;
    if (ch == '/' || ch == '*')
        return 3;
    if (ch == '(')
        return 0;
    if (ch == '#')
        return -1;
    return 0; // Default case for other characters
}

int main() {
    char exp[30];
    char stk[10];
    int top = 0;
    stk[top] = '#'; // Initialize stack with '#' as a sentinel
    printf("Enter the expression: ");
    fgets(exp, sizeof(exp), stdin);
    
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '*' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/') {
            // If current character is an operator
            if (ip(exp[i]) > sp(stk[top])) {
                stk[++top] = exp[i]; // Push operator to stack if precedence is higher
            } else {
                // Pop from stack and print until precedence is higher
                while (ip(exp[i]) <= sp(stk[top])) {
                    printf("%c", stk[top--]);
                }
                stk[++top] = exp[i]; // Push the current operator to stack
            }
        } else if (exp[i] == '(') {
            // If current character is '(', push to stack
            stk[++top] = exp[i];
        } else if (exp[i] == ')') {
            // If current character is ')', pop and print until '(' is encountered
            while (stk[top] != '(') {
                printf("%c", stk[top--]);
            }
            top--; // Discard the '(' from stack
        } else if (exp[i] != ' ' && exp[i] != '\n') {
            // If current character is an operand, print it (ignoring spaces and newlines)
            printf("%c", exp[i]);
        }
    }
    
    // Pop and print all remaining operators in stack
    while (stk[top] != '#') {
        printf("%c", stk[top--]);
    }
    return 0;
}

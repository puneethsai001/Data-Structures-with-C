#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <math.h>
#include "Stack.h"


int isOperator(char c){
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
        break;
    
    default:
        return 0;
        break;
    }
}

int main(){
    char expr[25];
    Stack mystack;

    initializeStack(&mystack);

    printf("Enter expression: ");
    gets(expr);

    for (int i = 0; expr[i] != '\0'; i++){
        if (isdigit(expr[i])){
            push(&mystack, expr[i] - '0');
        }

        else if (expr[i] == ' ')
            continue;

        else if (isOperator(expr[i])){
            int a = pop(&mystack);
            int b = pop(&mystack);
            int c;
            switch (expr[i])
            {
            case '+':
                c = b + a;
                break;

            case '-':
                c = b - a;
                break;

            case '*':
                c = b * a;
                break;
            
            case '/':
                c = b / a;
                break;
            
            case '^':
                c = pow(b,a);
                break;
            
            default:
                break;
            }
            push(&mystack, c);
        }
    }

    int value = mystack.arr[mystack.top];
    printf("%d \n", value);
    return 0;
}
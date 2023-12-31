//Program to evaluate a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <math.h>

#define MAX 20

typedef struct
{
    int arr[MAX];
    int top;
} Stack;

void initializeStack(Stack *s){
    s->top = -1;
}

int push(Stack *s,int n) //adds elment to the stack
{
    if (s->top == MAX-1)
    {   
        printf("Error: Stack Overflow, %d cannot be added. \n", n);
        return n;
    }

    s->top++;
    s->arr[s->top] = n;
    return n;
}

int pop(Stack *s) //removes top most element in a stack
{
    if (s->top == -1)
    {
        printf("Error: Stack Underflow, element can't be removed.");
        return 0;
    }
    int a = s->arr[s->top];
    s->top--;
    return a;
}

int size(Stack *s) //returns MAX of the stack
{
    return s->top+1;
}

int topValue(Stack *s) //returns topmost value of the stack
{
    return s->arr[s->top];
}

void display(Stack *s) //displays the stack
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d", s->arr[i]);
        printf(" ");
    }
}


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
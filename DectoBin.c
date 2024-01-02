#include <stdio.h>

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

int main(){
    Stack bin;
    initializeStack(&bin);

    int dec, rem, topval;
    printf("Enter decimal number: ");
    scanf("%d", &dec);

    while (dec != 1){
        rem = dec%2;
        push(&bin, rem);
        dec /= 2;

        if (dec == 1)
            push(&bin, 1);
    }

    topval = bin.top;
    printf("Binary Value: ");
    for (int i = 0; i <= topval; i++)
        printf("%d", pop(&bin));

    return 0;
}
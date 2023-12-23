//Section B Internal Question 1
#include <stdio.h>

const int MAX_SIZE = 20;

typedef struct Stack{
    int A[20];
    int top;
}Stack;

void initializeStack(Stack *s){
    s->top = -1;
}

void push(Stack *s, int value){
    if (s->top == MAX_SIZE - 1){
        printf("Stack Overflow \n");
        return;
    }

    s->top = s->top + 1;
    s->A[s->top] = value;
}

int pop(Stack *s){
    if (s->top == -1){
        printf("Stack Underflow \n");
        return 0;
    }

    return s->A[s->top--];
}

void display(Stack *s){
    if (s->top == -1){
        printf("Stack Empty \n");
        return;
    }

    printf("Stack: ");
    for (int i = 0; i < s->top+1; i++){
        printf("%d ", s->A[i]);
    }
    printf("\n");
}

int main(){

    Stack mystack;

    initializeStack(&mystack);

    int choice, num, flag = 1;

    while (flag){
        printf("1. Enter Number\n");
        printf("2. Undo Previous Entry\n");
        printf("3. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            
            printf("Enter Element: ");
            scanf("%d", &num);
            
            push(&mystack, num);
            display(&mystack);

            break;
        
        case 2:

            printf("Undo Success: ");

            pop(&mystack);
            display(&mystack);
            break;
        
        case 3:
            flag = 0;
            break;

        default:
            printf("Invalid Input!!");
        }

    }
    return 0;
}
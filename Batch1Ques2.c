//NOTE: The answer may not be 100% correct since the question is unclear

#include <stdio.h>
#define MAX_SIZE (20)

typedef struct Stack{
    int A[MAX_SIZE];
    int top;
}Stack;

void initializeStack(Stack *s){
    s->top = -1;
}

void push(Stack *s, int value){
    if (s->top == MAX_SIZE - 1){
        printf("Stack Overflow");
        return;
    }

    s->top = s->top + 1;
    s->A[s->top] = value;
}

int pop(Stack *s){
    if (s->top == -1){
        printf("Stack Underflow");
        return 0;
    }

    return s->A[s->top--];
}

int isEmpty(Stack *s){
    if (s->top == -1){
        return 1;
    }

    return 0;
}

void display(Stack *s){
    if (s->top == -1){
        printf("Stack Empty\n");
        return;
    }

    printf("Text Editor: ");
    for (int i = 0; i < s->top+1; i++){
        printf("%d ", s->A[i]);
    }
    printf("\n");
}

int main(){

    Stack myStack, redoStack;

    initializeStack(&myStack);
    initializeStack(&redoStack);

    int choice, flag = 1;
    int ele;

    while (flag){
        printf("\n1. Push an item\n");
        printf("2. Undo previous operation\n");
        printf("3. Redo previous operation\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Item: ");
            scanf("%d", &ele);

            push(&myStack, ele);
            display(&myStack);
            break;

        case 2:
            ele = pop(&myStack);

            if (ele != 0){
                push(&redoStack, ele);
                printf("Undo Success\n");
            }

            else{
                printf("\nUndo Unsuccessfull");
            }

            display(&myStack);
            break;

        case 3:
            ele = pop(&redoStack);

            if (ele != 0){
                push(&myStack, ele);
                printf("Redo Success\n");
            }

            else{
                printf("\nRedo Unsuccessfull\n");
            }

            display(&myStack);
            break;
        
        case 4:
            flag = 0;
            break;
        
        default:
            break;
        }
    }
    return 0;
}
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
        printf("STACK OVERFLOW: ");
        return;
    }

    s->top = s->top + 1;
    s->A[s->top] = value;
}

int pop(Stack *s){
    if (s->top == -1){
        printf("STACK UNDERFLOW: ");
        return 0;
    }

    return s->A[s->top--];
}

int topValue(Stack *s){
    return s->top;
}

void display(Stack *s){
    if (s->top == -1){
        printf("STACK EMPTY\n");
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

    int choice, flag = 1;
    int ele, temp;

    while (flag){
        
        printf("===================== Stack Main Menu =====================\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &ele);

            temp = topValue(&mystack);

            push(&mystack, ele);

            if (temp == topValue(&mystack)){
                printf("CANT PUSH THE VALUE\n");
            }

            else{
                printf("PUSH SUCCESS\n");
            }

            break;
        
        case 2:
            temp = topValue(&mystack);

            pop(&mystack);

            if (temp == topValue(&mystack)){
                printf("CANT POP THE VALUE\n");
            }

            else{
                printf("POP SUCCESS\n");
            }

            break;
        
        case 3:
            display(&mystack);
            break;
        
        case 4:
            flag = 0;
            break;

        default:
            printf("Invalid Input\n");
        }
    }
    

    return 0;
}
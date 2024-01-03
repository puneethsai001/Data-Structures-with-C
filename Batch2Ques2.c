#include <stdio.h>
#define MAX_SIZE (20)

typedef struct Queue{
    int A[MAX_SIZE];
    int front;
    int rear;
}Queue;

void initializeQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, int value){
    if (q->rear == MAX_SIZE - 1){
        printf("QUEUE OVERFLOW: ");
        return;
    }

    q->rear = q->rear + 1;
    q->A[q->rear] = value;
}

int dequeue(Queue *q){

    if (q->rear < q->front){
        printf("NO PRINT JOBS: ");
        return 0;
    }

    int a = q->A[q->front];
    q->front = q->front + 1;
    return a;
}

void display(Queue *q){
    if (q->front > q->rear){
        printf("PRINTER QUEUE EMPTY\n");
        return;
    }

    printf("Printer Status: ");
    for (int i = q->front; i <= q->rear; i++){
        printf("%d ",q->A[i]);
    }
    printf("\n");
}

int rearValue(Queue *q){
    return q->rear;
}

int frontValue(Queue *q){
    return q->front;
}


int main(){

    Queue myqueue;
    initializeQueue(&myqueue);

    int choice, flag = 1;
    int ele, temp, invalid = 1;
    int computers[10];

    for (int i = 1; i <= 10; i++){
        computers[i-1] = i;
    }

    while (flag){
        
        printf("===================== Print Operation Menu =====================\n");
        printf("1. Add a Print Job\n");
        printf("2. Print a Job\n");
        printf("3. Display Job Queue Status\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:

            printf("Enter Computer No: ");
            scanf("%d", &ele);

            temp = rearValue(&myqueue);

            enqueue(&myqueue, ele);

            if (temp == rearValue(&myqueue)){
                printf("CANT ADD MORE JOBS\n");
            }

            else{
                printf("ADDED SUCCESSFULLY\n");
            }

            break;
        
        case 2:
            temp = frontValue(&myqueue);

            dequeue(&myqueue);

            if (temp == frontValue(&myqueue)){
                printf("CANT PRINT\n");
            }

            else{
                printf("PRINTED SUCCESSFULLY\n");
            }

            break;
        
        case 3:
            display(&myqueue);
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
#include <stdio.h>
#define MAX_SIZE (8)

typedef struct CircularQueue
{
    int A[MAX_SIZE];
    int front;
    int rear;
}CircularQueue;

void initializeCirQueue(CircularQueue *q){
    q->front = -1;
    q->rear = -1;
}

void enqueue(CircularQueue *q, int value){

    if (q->front == -1 && q->rear == -1){
        q->front = 0;
        q->rear = 0;
        q->A[q->rear] = value;
    }

    else if (q->front == (q->rear + 1) % MAX_SIZE){
        printf("PRINTER CAPACITY FULL: ");
    }

    else{
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->A[q->rear] = value;
    }
}

int dequeue(CircularQueue *q){

    int value = 0;

    if (q->front == -1 && q->rear == -1){
        printf("NO CURRENT JOBS: ");
    }

    else if (q->front == q->rear){
        value = q->A[q->front];
        q->front = -1;
        q->rear = -1;
    }

    else{
        value = q->A[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
    }

    return value;
}

void display(CircularQueue *q){
    int frontPos = q->front;
    int rearPos = q->rear;

    if (q->front == -1){
        printf("NO CURRENT JOBS\n");
        return;
    }

    printf("Printer Job Queue: ");
    if (frontPos <= rearPos){
        while (frontPos <= rearPos){
            printf("%d <- ", q->A[frontPos]);
            frontPos++;
        }
    }

    else{
        while (frontPos <= MAX_SIZE - 1){
            printf("%d <- ", q->A[frontPos]);
            frontPos++;
        }

        frontPos = 0;

        while (frontPos <= rearPos){
            printf("%d <- ", q->A[frontPos]);
            frontPos++;
        }
    }
    printf("%d ", q->A[q->front]);
    printf("\n");
}

int rearValue(CircularQueue *q){
    return q->rear;
}

int frontValue(CircularQueue *q){
    return q->front;
}


int main(){

    CircularQueue myqueue;
    initializeCirQueue(&myqueue);

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
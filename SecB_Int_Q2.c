//Section B Internal Question 2
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *insertStart(Node *start, int value){
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = value;

    if (start == NULL){
        newNode->next = NULL;
        return newNode;
    }

    else{
        newNode->next = start;
        start = newNode;
        return start;
    }
}

int displayList(Node *start){
    int count = 0;
    if (start == NULL){
        printf("List is empty\n");
        count++;
    }

    else{
        printf("Linked List: ");
        Node *temp = start;
        while (temp->next != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
            count++;
        }

        printf("%d -> NULL\n", temp->data);
        count++;
    }

    return count;
}

int main(){
    Node *head = NULL;

    head = insertStart(head, 1);
    head = insertStart(head, 2);
    head = insertStart(head, 1);
    head = insertStart(head, 3);
    head = insertStart(head, 1);

    int count = displayList(head);
    printf("The number of nodes are %d", count);
    
    return 0;
}
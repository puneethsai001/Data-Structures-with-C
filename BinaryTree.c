#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* Create(){

    int x;
    printf("Enter Data (-1 for no node): ");
    scanf("%d", &x);
    printf("\n");

    if (x == -1){
        return NULL;
    }

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = x;
    
    printf("Left Child of %d \n",x);
    newNode->left = Create();

    printf("Right Child of %d \n",x);
    newNode->right = Create();

    return newNode;
}

int main(){

    Node *root = NULL;
    root = Create();

    return 0;
}
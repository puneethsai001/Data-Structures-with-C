#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;


Node* insertEnd(Node *start, int value){

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (start == NULL){
        return newNode;
    }

    else{
        Node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return start;
    }
}

Node* deleteEnd(Node *start){
    if (start == NULL){
        printf("List Underflow\n");
        return start;
    }

    else if (start->next == NULL){
        Node *ptr = start;
        start = NULL;
        free(ptr);
        return start;
    }

    else{
        Node *p, *temp = start; 
        while (temp->next != NULL)
        {
            p = temp;
            temp = temp->next;
        }
        p->next = NULL;
        Node *ptr = temp;
        free(ptr);
        return start;
    }
}

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

Node *deleteStart(Node *start){

    if (start == NULL){
        printf("List Underflow: ");
        return start;
    }

    else{
        Node *ptr = start;
        start = start->next;
        free(ptr);
        return start;
    }

}

Node *insertSP(Node *start, int value, int pos){
    Node *temp = start;
    int k = 1;

    while (k < pos){
        temp = temp->next;

        if (temp == NULL){
            printf("Nodes are lesser than the position\n");
            return start;
        }
        k++;
    }

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    return start;
}

Node *deleteSP(Node *start, int pos){
    if (start == NULL){
        printf("List Underflow\n");
        return start;
    }

    Node *ptr = start;
    Node *temp;

    int k = 1;

    while (k < pos){
        temp = ptr;
        ptr = ptr->next;

        if (ptr == NULL){
            printf("Nodes are lesser than the position\n");
            return start;
        }
        k++;
    }

    temp->next = ptr->next;
    free(ptr);
    return start;
}

void displayList(Node *start){
    if (start == NULL){
        printf("List is empty\n");
    }

    else{
        printf("Linked List: ");
        Node *temp = start;
        while (temp->next != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("%d -> NULL\n", temp->data);
    }
}

int main(){

    Node *newhead, *head = NULL; 
    int choice, secchoice, flag = 1;
    int pos, ele;

    while (flag){
    printf("===================== Main Menu =====================\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("Enter Choice: ");
    scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("===================== Insert Menu =====================\n");
            printf("1. Insert at start\n");
            printf("2. Insert at end \n");
            printf("3. Insert at a specific position \n");

            printf("Enter Choice: ");
            scanf("%d",&secchoice);

            switch (secchoice)
            {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);

                head = insertStart(head, ele);

                continue;
                break;
            
            case 2:
                printf("Enter element: ");
                scanf("%d", &ele);

                head = insertEnd(head, ele);

                continue;
                break;

            case 3:
                printf("Enter element: ");
                scanf("%d", &ele);

                printf("Enter position: ");
                scanf("%d", &pos);

                head = insertSP(head, ele, pos);

                continue;
                break;

            default:
                printf("Invalid Input!!\n");
            }
            
            break;
        
        case 2:
            printf("===================== Delete Menu =====================\n");
            printf("1. Delete from start\n");
            printf("2. Delete from end \n");
            printf("3. Delete from a specific position \n");

            printf("Enter Choice: ");
            scanf("%d",&secchoice);

            switch (secchoice)
            {
            case 1:

                newhead = head;
                head = deleteStart(head);

                if (newhead == head){
                    printf("Deletion cannot be performed\n");
                }

                else{
                    printf("Deleted from start\n");
                }

                continue;
                break;
            
            case 2:

                newhead = head;
                head = deleteEnd(head);

                if (newhead == head){
                    printf("Deletion cannot be performed\n");
                }

                else{
                    printf("Deleted from end\n");
                }
                continue;
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);

                newhead = head;
                head = deleteSP(head, pos);

                if (newhead == head){
                    printf("Deletion cannot be performed\n");
                }

                else{
                    printf("Deleted Successfully from position: %d\n",pos);
                }
                continue;
                break;

            default:
                printf("Invalid Input!!\n");
            }
            break;
        
        case 3:
            displayList(head);
            break;

        case 4:
            flag = 0;
            break;

        default:
            printf("Invalid Input!!\n");
        }
    }
    

    return 0;
}
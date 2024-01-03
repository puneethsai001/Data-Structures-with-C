#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int expenseid;
    double amount;
    char category[20];
    char date[8];
    struct Node *next;
}Node;

Node *insertData(Node *start, int e, double a, char c[20], char d[20]){

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->expenseid = e;
    newNode->amount = a;
    strcpy(newNode->category, c);
    strcpy(newNode->date, d);
    newNode->next = NULL;

    if (start == NULL){
        start = newNode;
        return start;
    }

    else{
        Node *temp = start;

        while (temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
        return start;
    }
}

Node *deleteData(Node *start, int id){
    if (start == NULL){
        printf("No Records Found\n");
        return start;
    }

    else{
        Node *ptr = start;
        Node *temp;

        while (ptr->expenseid != id){
            temp = ptr;
            ptr = ptr->next;

            if (ptr == NULL){
                printf("Expense ID not found\n");
                return start;
            }
        }

        temp->next = ptr->next;
        free(ptr);
        return start;
    }


}

void showFinance(Node *start){
    if (start == NULL){
        printf("No Records Found\n");
    }

    else{
        Node *temp = start;
        while (temp->next != NULL){
            printf("Expense ID: %d\n", temp->expenseid);
            printf("Amount: %f\n", temp->amount);
            printf("Category: %s\n", temp->category);
            printf("Date: %s\n", temp->date);
            printf("=======================================\n");

            temp = temp->next;
        }

        printf("Expense ID: %d\n", temp->expenseid);
        printf("Amount: %f\n", temp->amount);
        printf("Category: %s\n", temp->category);
        printf("Date: %s\n", temp->date);
        printf("=======================================\n");
    }

}

int main(){

    int id;

    Node *financeList = NULL;

    //inserting data
    financeList = insertData(financeList, 1, 1000, "Furniture", "06-04-23");
    financeList = insertData(financeList, 2, 5000, "Maintenance", "11-02-23");
    financeList = insertData(financeList, 3, 4000, "Groceries", "19-06-23");
    financeList = insertData(financeList, 4, 1200, "Fuel", "01-01-24");
    financeList = insertData(financeList, 5, 20000, "Credit Card", "13-11-24");
    financeList = insertData(financeList, 6, 10000, "Loan", "28-10-24");
    financeList = insertData(financeList, 7, 800, "Others", "23-12-24");

    printf("Enter Expense ID to delete: ");
    scanf("%d", &id);

    //funtion to search and delete
    deleteData(financeList, id);

    //The list after deleting is
    printf("The records after deleting are: \n");
    showFinance(financeList);

    return 0;
}
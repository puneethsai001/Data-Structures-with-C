#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *lchild;
    struct node *rchild; 
}NODE;

NODE* Create_Binary_Tree(){

    int ele;
    printf("Enter the element to inserted (-1 for no data):");
    scanf("%d",&ele);

    if (ele == -1)
        return NULL;

    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp->data = ele;

    printf("Enter lchild child of %d:\n",ele);
    temp->lchild = Create_Binary_Tree();

    printf("Enter rchild child of %d:\n",ele);
    temp->rchild = Create_Binary_Tree();

    return temp;
}

void inorder(NODE *ptr)
{
    if(ptr != NULL){
        inorder(ptr->lchild);
        printf("%5d",ptr->data);
        inorder(ptr->rchild);
    }
}

void postorder(NODE *ptr){

    if (ptr != NULL){
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%5d",ptr->data);
    }
}

void preorder(NODE *ptr){

    if (ptr != NULL){
        printf("%5d",ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

int main()
{
    int n,choice, flag = 1;
    NODE *root = NULL;

    while(flag){
        printf("\n===================== Binary Tree Main Menu =====================\n");
        printf("1. Insert\n");
        printf("2. All traversals\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: 
                root = Create_Binary_Tree();
                break;

            case 2:

                printf("\nInorder traversal:   ");
                inorder(root);

                printf("\nPreorder traversal:  ");
                preorder(root);

                printf("\nPostorder traversal: ");
                postorder(root);

                printf("\n");

                break;

            case 3:
                flag = 0;
                break;

            default:
                printf("Invalid Choice \n");
        }
    }
    return 0;
}
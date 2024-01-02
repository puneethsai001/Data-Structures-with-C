#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

int nodes = 0, leaf = 0;

int max(int a, int b){
    return (a > b) ? a: b;
}

int height(Node *root){

    if (root == NULL){
        return -1;
    }

    int h = 1+max(height(root->left),height(root->right));
    return h;
}

void countNode(Node *root){
    if (root==NULL)
        return;

    countNode(root->left);
    nodes++;

    countNode(root->right);
}

void countLeaf(Node *root){
    if (root == NULL)
        return;

    countLeaf(root->left);

    if (root->left == NULL && root->right == NULL)
        leaf++;

    countLeaf(root->right);
}

Node* insert(Node *root, int val){
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = val;
    newNode->right = NULL;
    newNode->left = NULL;

    if (root == NULL){
        root = newNode;
        return root;
    }

    if (root->data > val){
        root->left = insert(root->left, val);
    }

    else{
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(Node *root){
    if (root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);

}

int search(Node *root, int key){
    if (root == NULL){
        return 0;
    }

    if (root->data > key){
        return search(root->left, key);
    }

    else if (root->data == key){
        return 1;
    }

    else{
        return search(root->right, key);
    }
}

Node* delete(Node *root, int val){
    if (root == NULL){
        return NULL;
    }

    if (root->data > val){
        root->left = delete(root->left, val);
        return root;
    }

    else if (root->data < val){
        root->right = delete(root->right, val);
        return root;
    }

    else{
        //Case 1
        if (root->left == NULL && root->right == NULL){
            return NULL;
        }

        //Case 2
        if (root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        //Case 3
        Node* ISParent = root;
        Node* IS = root->right;

        while (IS->left != NULL) {
            ISParent = IS;
            IS = IS->left;
        }
 
        if (ISParent != root){
            ISParent->left = IS->right;
        }

        else {
            ISParent->right = IS->right;
        }
 
        root->data = IS->data;
        free(IS);
    }

    return root;
}

int main(){

    int values[] = {8,5,3,1,4,6,10,11,14};
    Node *root = NULL;

    int choice, flag = 1;
    int ele, found;

    for (int i = 0; i < 9; i++){
        root = insert(root, values[i]);
    }

    while (flag){

        printf("\n===================== BST Main Menu =====================\n");
        printf("1. Insert\n");
        printf("2. Traversal\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display Height, No of Nodes and Leaves\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &ele);
            root = insert(root, ele);
            break;
        
        case 2:
            printf("\nInorder: ");
            inorder(root);

            printf("\n");

            break;
        
        case 3:
            printf("Enter Element: ");
            scanf("%d", &ele);

            found = search(root, ele);

            if (found){
                printf("Element Found \n");
            }

            else{
                printf("Element Not Found \n");
            }
            
            break;

        case 4:
            printf("Enter Element: ");
            scanf("%d", &ele);

            delete(root, ele);
            break;
        
        case 5:
            printf("\nHeight: %d", height(root));
            countLeaf(root);
            countNode(root);

            printf("\nNo of Nodes: %d", nodes);
            printf("\nNo of Leaves: %d", leaf);

            printf("\n");

            break;

        case 6:
            flag = 0;  
            break;

        default:
            printf("Invalid Input\n");
        }
    }

    return 0;
}
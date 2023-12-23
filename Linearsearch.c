#include <stdio.h>

int Lsearch(int arr[], int n, int ele){
    for (int i = 0; i < n; i++){
        if (arr[i] == ele){
            return i+1;
        }
    }

    return 0;
}

int main(){
    
    int n, ele;

    printf("Enter no of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search for: ");
    scanf("%d", &ele);

    if (Lsearch(arr, n, ele) != 0)
        printf("Element found at position %d", Lsearch(arr, n, ele));
    else
        printf("Element not found \n");
    return 0;
}
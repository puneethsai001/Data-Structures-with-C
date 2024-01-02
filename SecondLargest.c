#include <stdio.h>

int seclargest(int arr[], int n){

    int first_largest = 0, second_largest;
    
    for (int j = 0; j < n; j++){
        if (arr[j] > first_largest){
            second_largest = first_largest;
            first_largest = arr[j];
        }
        else if (arr[j] > second_largest && arr[j] < first_largest) {
            second_largest = arr[j];
        }
    }
    return second_largest;
}
int main(){
    int n;
    printf("Enter no of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    printf("The second largest number is %d", seclargest(arr, n));
    return 0;
}
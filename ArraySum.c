#include <stdio.h>

double Add(double arr[], int n){
    double sum = 0;
    for (int j = 0; j < n; j++)
        sum = sum + arr[j];
    return sum;
}

int main(){
    int n;

    printf("Enter no of elements: ");
    scanf("%d", &n);

    double arr[n];

    for (int i = 0; i < n; i++){
        printf("Enter a double element: ");
        scanf("%lf", &arr[i]);
    }

    printf("The sum is %lf",Add(arr, n));
    return 0;
}
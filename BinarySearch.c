#include <stdio.h>

int main(){
    
    //declaring all variables
    int target, size = 8, flag = 0;
    int mid, first = 0, last = size ;
    int found = 0;

    printf("Enter an Element: ");
    scanf("%d", &target);

    //sorted array
    int a[8] = {1,2,8,11,19,21,25,34};


    //binary search algoritm
    while (first <= last)
    {
        mid = (last + first)/2;

        if (target > a[mid])
        {first = mid + 1;}

        else if (target < a[mid])
        {last = mid - 1;}

        else if (target == a[mid])
        {
            printf("Found at Position: %d \n", mid+1);
            found = 1;
            break;
        }
    }

    if (found != 1)
    {printf("Element not found \n");}

    return 0;
}
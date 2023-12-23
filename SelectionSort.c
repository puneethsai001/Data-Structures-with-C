#include <stdio.h>

int main(){
    
    //declaring all varibales and initializing the array
    int min,size;

    //user input of the array
    printf("Enter the no of elements: ");
    scanf("%d", &size);

    int a[size];

    for (int l = 0; l < size; l++)
    {
        printf("Enter Element: ");
        scanf("%d", &a[l]);        
    }

    //sorting the array
    for (int i = 0; i < size; i++)
    {
        min = a[i];
        for (int k = i+1; k < size; k++)
        {
            if (min > a[k])
            {
                min = a[k];
                int temp = a[i];
                a[i] = a[k];
                a[k] = temp;
            }
        }
    }

    //printing the sorted array
    printf("[");
    for (int j = 0; j < size; j++)
    {
        printf("%d",a[j]);
        if (j!= size - 1)
        {
            printf("%s",", ");
        }   
    }
    printf("] \n");

    return 0;
}
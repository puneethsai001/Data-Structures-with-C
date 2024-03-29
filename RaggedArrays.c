#include<stdio.h>
#include<stdlib.h>

int main(){
    int rowNum, colNum, i, j;
    int **table;

    printf("Enter the number of rows: ");
    scanf("%d", &rowNum);

    table = (int **) calloc(rowNum+1, sizeof(int *));

    for (i = 0; i < rowNum; i++){
        printf("Enter size of %d row: ", i+1);
        scanf("%d", &colNum);

        table[i] = (int *) calloc(colNum+1, sizeof(int));

        printf("Enter %d row elements: \n", i+1);
        for (j = 1; j <= colNum; j++)
            scanf("%d", &table[i][j]);

        table[i][0] = colNum;
        printf("Size of row number [%d] = %d \n", i+1, table[i][0]);
    }

    table[i] = NULL;
    for (i = 0; i < rowNum; i++) {
        printf("Displaying %d row elements:\n", i+1);
        for (j = 0; j <= *table[i]; j++)
            printf("%5d", table[i][j]);
        printf("\n");
    }

    for (i = 0; i < rowNum; i++) 
        free(table[i]);

    free(table);
    return 0;
}
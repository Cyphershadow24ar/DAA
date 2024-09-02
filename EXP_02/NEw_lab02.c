#include <stdio.h>
int main()
{
    int i, j, n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int arr[n][n];
    
    printf("Enter elements in 2D array:-\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++){
            if (i == j){
                printf("Enter element [%d][%d] :", i, j);
                scanf("%d", &arr[i][j]);
            }
            else{
                arr[i][j] = 0;
            }
        }
    }

    for (i = n; i >= 0; i--){
        for (j = 0; j < n; j++){
            if (i < j){
                arr[i][j] = arr[i][j - 1] + arr[i + 1][j];
            }
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
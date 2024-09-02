#include<stdio.h>

int main()
{
    int n = 4;
    int arr[10][10];
    int i, j;

    printf("Enter the values of diagonal elements:");

    // First row: Input for diagonal elements, set non-diagonal to 0
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j){ // For diagonal elements
                scanf("%d", &arr[i][j]);
            } else { // For non-diagonal elements
                arr[i][j] = 0;
            }
        }
    }

    // Fill the second row
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j){
                int sum = arr[i][j] + arr[i+1][j+1]; // Addition 
                arr[i][j+1] = sum;
            }
        }
    }

    // Fill the third row
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j-1){
                int sum1 = arr[i][j] + arr[i+1][j+1]; // Addition
                arr[i][j+1] = sum1;
            }
        }
    }

    // Fill the fourth row
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j-2){
                int sum2 = arr[i][j] + arr[i+1][j+1]; // Addition
                arr[i][j+1] = sum2;
            }
        }
    }

    // Print the matrix in reverse order
    printf("\nDisplay the matrix in reverse order:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d\t", arr[n-1-i][n-1-j]);  // Printing in reverse order
        }
        printf("\n");
    }

    return 0;
}

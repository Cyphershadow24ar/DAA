#include<stdio.h>

int main()
{
    int n, m; // Dimensions of the matrix
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    int arr[n][m]; // Variable-sized 2D array
    int *p = &arr[0][0]; // Pointer to the first element of the array
    int i, j;

    printf("Enter the values of diagonal elements:\n");

    // Initialize matrix with diagonal elements and set non-diagonal elements to 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i == j && i < m) {  // For diagonal elements within matrix bounds
                scanf("%d", p + i * m + j);
            } else {   // For non-diagonal elements
                *(p + i * m + j) = 0;
            }
        }
    }

    // Fill the matrix by calculating sums for each diagonal above the main diagonal
    for (int k = 1; k < m; k++) {  // k represents the diagonal level above the main diagonal
        for (i = 0; i < n - k; i++) {
            j = i + k;
            if (j < m) {
                *(p + i * m + j) = *(p + i * m + (j - 1)) + *(p + (i + 1) * m + j);
            }
        }
    }

    // Display the matrix
    printf("Display the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", *(p + i * m + j));
        }
        printf("\n");
    }

    return 0;
}

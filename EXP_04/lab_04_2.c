#include <stdio.h>

int main()
{
    int arr[3][8] = {
        {1, 2, 3, 4, 5, 6, 7, 8},   // First row
        {3, 9, 5, 1, 11, 2, 5, 15},  // Second row
        {5, 15, 8, 4, 15, 3, 8, 20}  // Third row
    };

    // Bubble sort based on the third row
    int n = 3; // Number of rows
    int k = 8; // Number of columns
    int i, j, m, temp;

    for (i = 0; i < k - 1; i++)
    {
        for (j = 0; j < k - i - 1; j++)
        {
            if (arr[2][j] > arr[2][j + 1])
            {
                // Swap the entire column if the third row value is greater
                for (m = 0; m < n; m++)
                {
                    temp = arr[m][j];
                    arr[m][j] = arr[m][j + 1];
                    arr[m][j + 1] = temp;
                }
            }
        }
    }

    // Print the sorted array
    printf("Sorted 2D array:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Print the activity chart
    printf("\nActivity chart:\n");
    int value = arr[2][0];
    printf("A%d ", arr[0][0]);
    for (i = 0; i < k; i++)
    {
        if (arr[1][i] >= value)
        {
            value = arr[2][i];
            printf("A%d ", arr[0][i]);
        }
    }
    printf("\n");

    return 0;
}

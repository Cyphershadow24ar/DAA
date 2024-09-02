#include <stdio.h>

int main() {
    // Unsorted 2x8 array
    int arr[2][8] = {
        {3, 9, 5, 1, 11, 2, 5, 15},  // First row
        {5, 15, 8, 4, 15, 3, 8, 20} // Second row
    };


// Bubble sort based on the second row (index value 1)

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8 - i - 1; j++) {
            if (arr[1][j] > arr[1][j + 1]) { // Compare the values in the second row
                for (int k = 0; k < 2; k++) { // Swap the entire column if the second row value is greater
                    int temp = arr[k][j];
                    arr[k][j] = arr[k][j + 1];
                    arr[k][j + 1] = temp;
                }
            }
        }
    }

    // Print the sorted array
    printf("Sorted 2D array:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nActivity chart:\n");
    int value = arr[2][0];
    printf("A%d ", arr[0][0]);
    for (int i = 0; i < 8; i++)
    {
        if (arr[1][i] >= value)
        {
            value = arr[2][i];
            printf("A%d ", arr[0][i]);
        }
    }
    for (int j = 0; j < 8; j++) {
        if (arr[0][j] > arr[1][j]) {
            int temp = arr[1][j]; // Store the second row value
            arr[1][j] = arr[0][j]; // Move the first row value to the second row
            printf("Storing %d in the second row\n", temp);
    }
    }

    return 0;
}

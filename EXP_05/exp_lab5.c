#include <stdio.h>
#include<stdlib.h>
// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n) {
    int i, j;
    int K[n + 1][W + 1];

    // Build the table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i - 1] <= j)
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            else{
                K[i][j] = K[i - 1][j];
            }
        }
    }

    // The maximum value that can be put in a knapsack of capacity W
    

printf("\nDP Table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            printf("%d\t", K[i][j]);
        }
        printf("\n");
    }

    // Maximum value that can be carried
    printf("\nMaximum value in Knapsack = %d\n", K[n][W]);

    // Find out which items to select
    printf("Items selected:\n");
    int res = K[n][W];
    j= W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][j])
            continue; // Item not included
        else {
            // Item included
            printf("Item %d (Value: %d, Weight: %d)\n", i, val[i - 1], wt[i - 1]);
            res = res - val[i - 1];
            j = j - wt[i - 1];
        }
    }
}


int main() {
    int W,n,i;
    printf("ENTER THE KNAPSACK CAPACITY:");
    scanf("%d/n",&W);
    printf("ENTER THE NUMBER OF ELEMENTS REQUIRED:");
    scanf("%d",&n);
    int val[n], wt[n];
    printf("ENTER THE VALUES OF ELEMENTS:");
    for(i=0;i<n;i++){
    scanf("%d",&val[i]);
    }
    printf("ENTER THE WEIGHT OF THE ITEMS:");
    for(i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }

knapsack(W, wt, val, n);

    return 0;
}
#include <stdio.h>
#include <limits.h>

// Function to print optimal parenthesis
void print_optimal_parenthesis(int i, int j, int n, int kv[n][n]) {
    if (i == j) {
        printf("M%d", i);
        return;
    }
    printf("(");
    print_optimal_parenthesis(i, kv[i][j], n, kv);
    print_optimal_parenthesis(kv[i][j] + 1, j, n, kv);
    printf(")");
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int d[n + 1];
    printf("Enter the dimensions of the matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &d[i]);
    }

    int cost[n][n];
    int kv[n][n]; //  kv represents the k values

    // Initialize cost and kv matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = 0;
            kv[i][j] = 0;
        }
    }

    // Fill the diagonal of the cost matrix with 0
    for (int i = 1; i < n; i++) {
        cost[i][i] = 0;
    }

    // Matrix chain multiplication DP approach
    for (int L = 2; L < n; L++) { // L is chain length
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX; // Initialize to max value for minimization
            for (int k = i; k <= j - 1; k++) {
                int temp = cost[i][k] + cost[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (temp < cost[i][j]) {
                    cost[i][j] = temp;
                    kv[i][j] = k;
                }
            }
        }
    }

    printf("\nCost Table (cost):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i > j) {
                printf("    - ");
            } else {
                printf("%6d ", cost[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nK Value Table (kv):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i >= j) {
                printf("    - ");
            } else {
                printf("%6d ", kv[i][j]);
            }
        }
        printf("\n");
    }

    // Printing the optimal parenthesis
    printf("\nOptimal parenthesis: ");
    print_optimal_parenthesis(1, n - 1, n, kv);
    printf("\nMinimum number of multiplications: %d\n", cost[1][n - 1]);

    return 0;
}

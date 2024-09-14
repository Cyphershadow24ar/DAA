#include <stdio.h>
#include <limits.h>

// Function created 
void matrix_function(int dim[], int n);
void parenthesis(int i, int j, int n, int s[n][n]);

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dim[n + 1];
    printf("Enter the dimensions of the matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &dim[i]);
    }

    matrix_function(dim, n + 1);

    return 0;
}

void matrix_function(int dim[], int n) {
    int m[n][n];  // m = Cost matrix
    int s[n][n];  // s = Matrix for k

    // this loop is used to initialize the matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    // this loop is used Filling up the diagonal of cost matrix with zeros.
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // Apply matrix chain multiplication formula.
    for (int L = 2; L < n; L++) {  // here L is the chain length.
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX; // int_max is used for initialize of max value for minimization.
            for (int k = i; k <= j - 1; k++) {
                int temp = m[i][k] + m[k + 1][j] + dim[i - 1] * dim[k] * dim[j];
                if (temp < m[i][j]) {
                    m[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print Cost Table
    printf("\nCost Table (m):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i > j) {
                printf("    - ");
            } else {
                printf("%6d ", m[i][j]);
            }
        }
        printf("\n");
    }

    // Print K Value Table
    printf("\nK Value Table (s):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i >= j) {
                printf("    - ");
            } else {
                printf("%6d ", s[i][j]);
            }
        }
        printf("\n");
    }

    // Print optimal parenthesis
    printf("\nOptimal Parenthesis: ");
    parenthesis(1, n - 1, n, s);
    printf("\n");
}

void parenthesis(int i, int j, int n, int s[n][n]) {
    if (i == j) {
        printf("M%d", i);
        return;
    }
    printf("(");
    parenthesis(i, s[i][j], n, s);
    parenthesis(s[i][j] + 1, j, n, s);
    printf(")");
}

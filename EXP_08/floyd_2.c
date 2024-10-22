#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INF 9999 // Define infinity as a largest value

int main() {
    int i, j, k;
    int v = 4;
    int graph[4][4] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    printf("The initial Matrix: \n");
    for (i = 0; i < v; i++) {  // loop for printing initial matrix
        for (j = 0; j < v; j++) {
            if (graph[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");


    for (i = 0; i < v; i++) { // layers updating
        for (j = 0; j < v; j++) { // COLUMNS updating
            for (k = 0; k < v; k++) { // rows updating
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
        for (int a= 0; a < v; a++) {
        for (int b = 0; b< v; b++) {
            if (graph[a][b] == INF) {
                printf("INF ");
            } else {
                printf("%d ", graph[a][b]);
            }
        }
        printf("\n");
    }
        printf("\n");
    }



    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 6

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 3, 2, 5, 0, 0},
        {3, 0, 0, 1, 4, 0},
        {2, 0, 0, 2, 0, 1},
        {5, 1, 2, 0, 3, 0},
        {0, 4, 0, 3, 0, 2},
        {0, 0, 1, 0, 2, 0}
    };

    char vertices[MAX_VERTICES];
    int v;

    // Print the graph
    printf("The graph is:\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Get the number of vertices from the user
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &v);

    // Get the vertices from the user
    printf("Enter the vertices:\n");
    for (int i = 0; i < v; i++) {
        printf("Enter the %dth vertex: ", i + 1);
        scanf(" %c", &vertices[i]);
    }

    // Initialize the distance array
    int distances[MAX_VERTICES];
    for (int i = 0; i < v; i++) {
        distances[i] = INT_MAX;
    }

    // Initialize the visited array
    int visited[MAX_VERTICES];
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }

    // Dijkstra's algorithm
    for (int i = 0; i < v; i++) {
        int min = INT_MAX;
        int c;
        for (int j = 0; j < v; j++) {
            if (!visited[j] && distances[j] < min) {
                min = distances[j];
                c = j;
            }
        }
        visited[c] = 1;
        printf("\nVisited vertex: %c", vertices[c]);
        for (int j = 0; j < v; j++) {
            if (!visited[j] && graph[c][j] != 0 && distances[c] != INT_MAX &&
                distances[c] + graph[c][j] < distances[j]) {
                distances[j] = distances[c] + graph[c][j];
            }
        }
    }

    return 0;
}
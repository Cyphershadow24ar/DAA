#include<stdio.h>
#include<stdlib.h>

int main()
{
    int v, row = 0; // Initialize row to 0 or some value
    int INT_MAX = 9999;
    int graph[6][6] = {{0, 3, 2, 5, 0, 0},
                {3, 0, 0, 1, 4, 0},
                {2, 0, 0, 2, 0, 1},
                {5, 1, 2, 0, 3, 0},
                {0, 4, 0, 3, 0, 2},
                {0, 0, 1, 0, 2, 0}};
    char vertices[10];
    
    // Declare the visited array and dijComp for distances
    int visited[6] = {0}; // Initialize all as not visited
    int dijComp[6];       // Initialize 1D array for shortest path estimates

    // Print the Graph array
    printf("The graph is:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    // Store the vertices in a 1D character array
    printf("Enter the vertices for Character array:\n");
    for (int i = 0; i < v; i++) {
        printf("Enter the %dth element: ", i+1);
        scanf(" %c", &vertices[i]);  // Notice the space before %c to handle newline
    }

    // Initialize Dijkstra's comparison array (distance) with INT_MAX (infinity)
    for (int i = 0; i < v; i++) {
        dijComp[i] = INT_MAX;
    }

    dijComp[row] = 0; // Distance to the source node (row) is 0

    // Loop to process all vertices
    for (int i = 0; i < v; i++) {
        int min = INT_MAX, c = -1; // Variable to store the vertex with the minimum distance

        // Find the vertex with the minimum distance
        for (int j = 0; j < v; j++) {
            if (!visited[j] && dijComp[j] < min) {
                min = dijComp[j];
                c = j;
            }
        }

        visited[c] = 1; // Mark the vertex as visited
        printf("\nVisited node: %c", vertices[c]);

        // Update the distances of adjacent vertices
        for (int j = 0; j < v; j++) {
            if (!visited[j] && graph[c][j] != 0 && dijComp[c] != INT_MAX &&
                dijComp[c] + graph[c][j] < dijComp[j]) {
                dijComp[j] = dijComp[c] + graph[c][j];
            }
        }
    }

    // Print the final dijComp (Dijkstra distance matrix)
    printf("\nFinal distances from source:\n");
    for (int i = 0; i < v; i++) {
        printf("Distance to %c: %d\n", vertices[i], dijComp[i]);
    }

    return 0;
}

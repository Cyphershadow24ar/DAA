#include<stdio.h>
#include<stdlib.h>  // For malloc and free

void dijkstra(int** arrcost, int source, int dest, int VER, int INFINITY) {
    int dist[VER];
    int visited[VER];
    int prev[VER];  // To store the path

    for (int i = 0; i < VER; i++) {
        visited[i] = 0;
        prev[i] = -1; // -1 means no previous node
    }

    // Initialize distances to infinity, and source to 0
    for (int i = 0; i < VER; i++) dist[i] = INFINITY;
    dist[source] = 0;

    // Dijkstra's algorithm
    for (int count = 0; count < VER - 1; count++) {
        int min_dist = INFINITY, u = -1;

        // Find the vertex with the minimum distance
        for (int i = 0; i < VER; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // No reachable unvisited node

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < VER; v++) {
            if (!visited[v] && arrcost[u][v] && dist[u] != INFINITY && dist[u] + arrcost[u][v] < dist[v]) {
                dist[v] = dist[u] + arrcost[u][v];
                prev[v] = u; // Track the path
            }
        }
    }

    // Output the shortest distance from source to destination
    if (dist[dest] == INFINITY) {
        printf("No path exists from source to destination.\n");
    } else {
        printf("Shortest distance from vertex %d to vertex %d is: %d\n", source, dest, dist[dest]);

        // Print the path from source to destination
        printf("Path: ");
        int current = dest;
        while (current != -1) {
            printf("%d ", current);
            current = prev[current];
        }
        printf("\n");
    }
}

int main() {
    int VER = 6;
    int INFINITY = 1000000;

    // Predefined cost matrix
    int costMatrix[6][6] = {
        {0, 3, 2, 5, 0, 0},
        {3, 0, 0, 1, 4, 0},
        {2, 0, 0, 2, 0, 1},
        {5, 1, 2, 0, 3, 0},
        {0, 4, 0, 3, 0, 2},
        {0, 0, 1, 0, 2, 0}
    };

    // Dynamically allocate 2D array for costs
    int** arrcost = (int**)malloc(VER * sizeof(int*));
    for (int i = 0; i < VER; i++) {
        arrcost[i] = (int*)malloc(VER * sizeof(int));
        for (int j = 0; j < VER; j++) {
            arrcost[i][j] = costMatrix[i][j];
        }
    }

    // Input the source vertex
    int source = 0;  // You can change this if needed

    // Input the destination vertex
    int dest = 5;  // You can change this if needed

    // Call the modified Dijkstra function
    dijkstra(arrcost, source, dest, VER, INFINITY);

    // Free dynamically allocated memory
    for (int i = 0; i < VER; i++) {
        free(arrcost[i]);
    }
    free(arrcost);

    return 0;
}

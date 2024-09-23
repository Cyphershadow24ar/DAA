#include <stdio.h>
#define INF 9999

int main() {
    // Graph represented as an adjacency matrix
    int graph[6][6] = {
        {0, 3, 2, 5, 0, 0},
        {3, 0, 0, 1, 4, 0},
        {2, 0, 0, 2, 0, 1},
        {5, 1, 2, 0, 3, 0},
        {0, 4, 0, 3, 0, 2},
        {0, 0, 1, 0, 2, 0}
    };

    char source_vertex;
    int i, j, src_idx, selected_vertex = 0, next_vertex;
    char vertices[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int dist_table[6][6], explored[6] = {0}; // Initialize explored to all 0s

    // Print the original graph
    printf("The original Graph (adjacency matrix):\n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Initialize all distances to INF initially
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            dist_table[i][j] = INF;
        }
    }

    // Get source vertex from user
    printf("Enter the source vertex: ");
    scanf("%c", &source_vertex);

    // Find the index of the source vertex
    for (i = 0; i < 6; i++) {
        if (vertices[i] == source_vertex) {
            src_idx = i;
        }
    }
    
    printf("Source vertex is %c, index is %d\n", source_vertex, src_idx);

    // Initialize distances from source to itself as 0
    dist_table[src_idx][src_idx] = 0;

    // Populate initial distances from the source to other vertices
    for (i = 0; i < 6; i++) {
        if (graph[src_idx][i] != 0) {
            dist_table[1][i] = graph[src_idx][i];
        }
    }

    // Mark the source vertex as explored
    explored[src_idx] = 1;
    int step = 1;

    // Dijkstra's algorithm loop
    for (i = 1; i < 6; i++) {
        step++;
        int minimum_dist = INF;

        // Find the nearest unexplored vertex
        for (int k = 0; k < 6; k++) {
            if (dist_table[i][k] < minimum_dist && explored[k] != 1) {
                next_vertex = k;
                minimum_dist = dist_table[i][k];
            }
        }

        explored[next_vertex] = 1; // Mark the next vertex as explored

        // Update distances to other vertices based on the current minimum vertex
        for (j = 0; j < 6; j++) {
            if (explored[j] == 1) {
                dist_table[step][j] = dist_table[step - 1][j];
            } else if (graph[next_vertex][j] == 0) {
                dist_table[step][j] = dist_table[step - 1][j];
            } else if (dist_table[step - 1][j] >= dist_table[step - 1][next_vertex] + graph[next_vertex][j]) {
                dist_table[step][j] = dist_table[step - 1][next_vertex] + graph[next_vertex][j];
            } else {
                dist_table[step][j] = dist_table[step - 1][j];
            }
        }
    }

    // Set source column to INF after the first row
    for (i = 1; i < 6; i++) {
        dist_table[i][src_idx] = INF;
    }

    // Print the final Cost table
    printf("\nFinal Cost table:\n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d ", dist_table[i][j]);
        }
        printf("\n");
    }

    // Print visited vertices
    printf("\nVisited vertices: ");
    for (i = 0; i < 6; i++) {
        if (explored[i] == 1) {
            printf("%c ", vertices[i]); 
        }
    }
    printf("\n");

    return 0;
}

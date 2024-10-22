#include <stdio.h>

#define INF 99999 // A value representing infinity (no connection)

void printSolution(int dist[][4], int V);

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[][4], int V) {
    int dist[V][V]; // dist[][] will hold the shortest distances between every pair

    // Initialize the solution matrix same as input graph matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Add all vertices one by one to the set of intermediate vertices.
    for (int k = 0; k < V; k++) {
        // Pick all vertices as the source
        for (int i = 0; i < V; i++) {
            // Pick all vertices as the destination
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, update dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist, V);
}

// Function to print the solution matrix
void printSolution(int dist[][4], int V) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    // Number of vertices in the graph
    int V = 4;

    /* The graph is represented as a matrix.
    A value of INF means there is no direct path between vertices.
    For example, graph[i][j] is the weight of the edge from vertex i to vertex j.
    If i == j, then graph[i][j] is 0 because there is no cost to go from a vertex to itself.
    */
    int graph[4][4] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF,0}
    };

    // Run the Floyd-Warshall algorithm
    floydWarshall(graph, V);

    return 0;
}
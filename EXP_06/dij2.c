#include<stdio.h>
#include<limits.h>
#define VER 6
#define INF 9999 // Using a large value to represent infinity

int main()
{
    int arrgraph[VER][VER]; // Array for actual computation (Array 3)
    char vertices[VER]; // Array to store vertices (Array 2)

    // Input vertices
    for (int i = 0; i < VER; i++)
    {
        printf("Enter your %d node: ", i);
        scanf(" %c", &vertices[i]);
    } // Stored all vertices in a 1D array

    // Initialize arrcost (Array 1) and input costs
    int arrcost[VER][VER] = {0}; // Initialize the array to 0
    for (int x = 0; x < VER; x++)
    {
        for (int y = 0; y < VER; y++)
        {
            printf("Enter the cost of edge from %c to %c: ", vertices[x], vertices[y]);
            scanf("%d", &arrcost[x][y]);
        }
    }

    // Initialize arrgraph (Array 3) to infinity (INF)
    for (int x = 0; x < VER; x++)
    {
        for (int y = 0; y < VER; y++)
        {
            arrgraph[x][y] = INF; // Set everything to infinity initially
        }
    }

    // Input the source vertex
    char source;
    printf("Enter the source to find path from: ");
    scanf(" %c", &source);

    // Find index of the source vertex
    int index = -1;
    for (int i = 0; i < VER; i++) {
        if (vertices[i] == source) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Source vertex not found!\n");
        return 1; // Exit if source is not found
    }

    // Set the source row in arrgraph to 0
    for (int j = 0; j < VER; j++) {
        arrgraph[index][j] = 0;
    }

    // Copy edges from arrcost to arrgraph, except where the cost is 0
    for (int p = 0; p < VER; p++) {
        for (int q = 0; q < VER; q++) {
            if (arrcost[p][q] != 0) {
                arrgraph[p][q] = arrcost[p][q];
            }
        }
    }

    // Print the cost matrix (arrcost)
    printf("\nCost Matrix (arrcost):\n");
    for (int p = 0; p < VER; p++) {
        for (int q = 0; q < VER; q++) {
            printf("%d ", arrcost[p][q]);
        }
        printf("\n");
    }

    // Print the graph matrix (arrgraph)
    printf("\nGraph Matrix (arrgraph):\n");
    for (int p = 0; p < VER; p++) {
        for (int q = 0; q < VER; q++) {
            if (arrgraph[p][q] == INF) {
                printf("INF "); // Print 'INF' for unconnected vertices
            } else {
                printf("%d ", arrgraph[p][q]);
            }
        }
        printf("\n");
    }

    return 0;
}

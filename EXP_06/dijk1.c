#include<stdio.h>
#include<stdlib.h>


int main()
{
    int v,row;
    int INT_MAX = 9999;
    int graph[6][6]={{0,3,2,5,0,0},{3,0,0,1,4,0},{2,0,0,2,0,1},{5,1,2,0,3,0},{0,4,0,3,0,2},{0,0,1,0,2,0}};
    char vertices[10];
    int dijComp[v][v];

    // This LOOP is used to here to Print the Graph array
    printf("The graph is:\n");
    for (int i = 0; i < 6; i++)
    {
    for (int j = 0; j < 6; j++)
    {
        printf("%d ", graph[i][j]);
    }
    printf("\n");
    }

    printf("Enter the no. of vertices: ");
    scanf("%d", &v);

    // This LOOP is used here for storing a 1D array (vertices).
    printf("Enter the vertices for Character array:\n");
    for(int i=0; i<v; i++){
        printf("Enter the %dth element: ", i+1);
        scanf(" %c", &vertices[i]);  // Notice the space before %c to handle newline
    }

    // This LOOP is used for storing Dijkstra algo values in 2D array.
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            dijComp[i][j] = INT_MAX;
        }
    }

    dijComp[row] = 0;
    for (i = 0; i < v; i++) {
        int min = INT_MAX;
        for (j = 0; j < V; j++) {
            if (!visited[j] && Dijcomp[j] < min) {
                min = Dijcomp[j];
                c = j;
            }
        }
        visited[c] = 1;
        printf("\nVisited node: %c", Vertices[c]);
        for (j = 0; j < V; j++) {
            if (!visited[j] && graph[c][j] != 0 && Dijcomp[c] != INT_MAX &&
                Dijcomp[c] + graph[c][j] < Dijcomp[j]) {
                Dijcomp[j] = Dijcomp[c] + graph[c][j];
            }
        }
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define v 6

int main(){
    int relax, i, j, k;
    int adj[v][v] = {{0,4,2,0,0,0}, {0,0,3,2,0,0}, {0,1,0,4,5,0},{0,0,0,0,0,2},{0,0,0,-5,0,0},{0,0,0,0,5,0}};
    char vertex[v] = {'A','B','C','D','E','F'};
    char source = 'A';
    int dist[v];

    // Initialize distances to a large value (infinity) except for the source vertex
    for(i = 0; i < v; i++){
        dist[i] = 10000; // Representing infinity
    }
    dist[source - 'A'] = 0;

    // Print the iteration header
    printf("Iteration  ");
    for(i = 0; i < v; i++){
        printf("%c  ", vertex[i]);
    }
    printf("\n");

    // Apply the relaxation process
    for(i = 0; i < v - 1; i++){
        printf("%d          ", i + 1);
        for(j = 0; j < v; j++){
            for(k = 0; k < v; k++){
                // Relax the edge if possible
                if(adj[j][k] != 0 && dist[j] + adj[j][k] < dist[k]){
                    dist[k] = dist[j] + adj[j][k];
                }
            }    
        }
        
        // Print distances after the current iteration
        for(int l = 0; l < v; l++){
            if(dist[l] == 10000){
                printf("INF  ");
            }
            else{
                printf("%d  ", dist[l]);
            }
        }
        printf("\n");
    }

    // Print the final distance results
    printf("\nFinal distance:\n");
    for(i = 0; i < v; i++){
        printf("%c            ", vertex[i]);
        if(dist[i] == 10000){
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }

    return 0;
}

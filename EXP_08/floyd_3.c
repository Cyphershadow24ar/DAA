#include<stdio.h>
#include<stdlib.h>
# define v 4
# define INF 9999
int main()
{
    int i,j,k,n;
    int arr[v][v]={ // input graph
        {0,3,INF,7},
        {8,0,2,INF},
        {5,INF,0,1},
        {2,INF,INF,0}
    };
    int graph[v][v][v]; //graph initialized 
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            graph[0][i][j] = arr[i][j];
        }
    }
    //floyd warshasll algo
        for(int k=1;k<=v;k++) 
        {
            for(int i=0;i<=v;i++)
            {
                for(int j=0;j<=v;j++){
                if(graph[k-1][i][j]>graph[k-1][i][k-1]+graph[k-1][k-1][j])
                graph[k][i][j]=graph[k-1][i][k-1]+graph[k-1][k-1][j];
                else
                graph[k][i][j]=graph[k-1][i][j];
            }
        }
        // print graph 
        printf("display matrix:-\n");
    for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (graph[v][i][j] == INF) {
                    printf("INF ");
                } else {
                    printf("%d ", graph[v][i][j]);
                }
            }
            printf("\n");
        }
        } 
    return 0;
}
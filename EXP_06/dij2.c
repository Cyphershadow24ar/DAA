#include<stdio.h>
#include<stdlib.h>
#define V 6

int main(){
    
	char source = 'A';
	
	char vertex[V] = {'A', 'B', 'C', 'D', 'E', 'F'};

	int graph[V][V] = {
    {0,3,2,5,0,0},
    {3,0,0,1,4,0},
    {2,0,0,2,0,1},
    {5,1,2,0,3,0},
    {0,4,0,3,0,2},
    {0,0,1,0,0,2}
	};

	int dijcomp[V][V];
	
	char visited[V];

	int min = __INT_MAX__;
	
	int i, j, row, a = 0, c, k;

	for(i = 0; i < V; i++){
    for(int j = 0; j < V; j++){
        dijcomp[i][j] = min;
    }
	}

    for(i = 0; i < V; i++){
        if(source == vertex[i]){
            row = i;
            break;
        }
    }
    
    dijcomp[row][0] = 0;
	
	for(k = 1; k < V; k++){
		for(j = 0; j < V; j++){
    if(dijcomp[row][j] < min){
    min = dijcomp[row][j];
    c = j;
			}
		}
		
		visited[a] = vertex[c];
		a++;
	
		for(i = 0; i < V; i++){
			if(graph[c][i] > 0){
				dijcomp[k][i] = dijcomp[c][c] + graph[c][i];
			}
		}
	}
	
	for(i = 0; i < V; i++){
		printf("%c ",visited[i]);
	}
	printf("\n");
	
	for(i = 0; i < V; i++){
    for(int j = 0; j < V; j++){
        printf("%d ",dijcomp[i][j]);
    }
    printf("\n");
	}
	
}
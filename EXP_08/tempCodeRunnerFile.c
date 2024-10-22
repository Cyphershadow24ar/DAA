for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            if (graph[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }

#include<stdio.h>

int main(){
    int n;
    printf("Enter the total number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter the start times for each activity:\n");
    for(int i = 0; i < n; i++) {
        printf("Start time for activity %d: ", i + 1);
        scanf("%d", &start[i]);  // Corrected to use start[i]
    }

    printf("Enter the finish times for each activity:\n");
    for(int i = 0; i < n; i++) {
        printf("Finish time for activity %d: ", i + 1);
        scanf("%d", &finish[i]);  // Corrected to use finish[i]
    }

    // Sort activities by their finish times
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                // Swap start times
                int temp = start[i];
                start[i] = start[j];
                start[j] = temp;

                // Swap finish times
                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;
            }
        }
    }

    // Print selected activities
    printf("Selected activities: ");
    printf("(%d, %d) ", start[0], finish[0]);

    int last = finish[0];
    for (int i = 1; i < n; i++) {
        if (start[i] >= last) {
            printf("(%d, %d) ", start[i], finish[i]);
            last = finish[i];
        }
    }
    printf("\n");

    return 0;
}

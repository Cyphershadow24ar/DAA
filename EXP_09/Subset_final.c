#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int sum;                // Sum of the current subset
    struct Node* include;   // Include current element
    struct Node* exclude;   // Exclude current element
};

// node creation
struct Node* createNode(int sum) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sum = sum;
    newNode->include = NULL;
    newNode->exclude = NULL;
    return newNode;
}

// subset logic
void find(struct Node* node, int* numbers, int n, int index, int targetSum, int* path, int pathIndex) {
    if (index == n) {
        if (node->sum == targetSum) {
            printf("Subset found: ");
            for (int i = 0; i < pathIndex; i++) {
                printf("%d\t", path[i]);}
            printf("\n");}
        return;}

    // Include tree
    path[pathIndex] = numbers[index];
    node->include = createNode(node->sum + numbers[index]);
    find(node->include, numbers, n, index + 1, targetSum, path, pathIndex + 1);

    // Exclude tree
    node->exclude = createNode(node->sum);
    find(node->exclude, numbers, n, index + 1, targetSum, path, pathIndex);
}

// Function to free the dynamically allocated tree
void freeTree(struct Node* node) {
    if (node) {
        freeTree(node->include);
        freeTree(node->exclude);
        free(node);}}

int main() {
    int n, targetSum;
    int numbers[MAX];
    printf("Enter the number of elements in the subset: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);}
    printf("Enter the subset limit: ");
    scanf("%d", &targetSum);

    struct Node* root = createNode(0);
    int path[MAX]; // Array to store the current path
    find(root, numbers, n, 0, targetSum, path, 0); // Start with 0
    freeTree(root);
    return 0;}

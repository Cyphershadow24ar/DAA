#include <stdio.h>
#include <stdlib.h>

// Structure for subset sum tree nodes
struct TreeNode {
    int sum;  // Sum of the subset
    int index;  // Index in the array
    struct TreeNode *include;  // left Child including the current element
    struct TreeNode *exclude;  // right Child excluding the current element
};

// Function to create a new TreeNode for subset sum tree
struct TreeNode* createTreeNode(int sum, int index) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->sum = sum;
    newNode->index = index;
    newNode->include = NULL;
    newNode->exclude = NULL;
    return newNode;
}

// leaf node
//  za

int main() {

    int arr[] = {10, 30, 40, 50};  // original array 
    int n = sizeof(arr) / sizeof(arr[0]); // size of array 
    int targetSum = 80;
    int subset[n];  // new array or subset array 

    return 0;
}

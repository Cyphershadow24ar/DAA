#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *NewNode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right=NULL;
    return temp;
}

struct node *create(struct node *root, int data){
    if (root == NULL)
        return NewNode(data);
    if (data < root->data)
        root->left = create(root->left, data);
    else if (data > root->data)
        root->right = create(root->right, data);
    return root;
}

int main(){

    struct node *root = NULL;
    root = create(root, 100);
    root = create(root, 80);
    root = create(root, 60);
    root = create(root, 90);
    root = create(root, 110);
    return 0;
    
}
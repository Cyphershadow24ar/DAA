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

struct node *create(struct node *node, int data){
    if (node == NULL)
        return NewNode(data);
    if (data < node->data)
        node->left = create(node->left, data);
    else if (data > node->data)
        node->right = create(node->right, data);
    return node;
}


void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    struct node *root = NULL;
    root = create(root, 100);
    root = create(root, 80);
    root = create(root, 120);
    root = create(root, 60);
    root = create(root, 90);
    root = create(root, 110);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
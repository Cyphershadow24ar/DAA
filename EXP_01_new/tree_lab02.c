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

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *delete(struct node *root, int data)
{
    if(root == NULL)
        return root;

    if(data < root->data){
        root->left = delete(root->left, data);
    }
    else if(data > root->data){
        root->right = delete(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        else{
            struct node *temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

int main(){
    struct node *root = NULL;
    root = create(root, 100);
    root = create(root, 80);
    root = create(root, 60);
    root = create(root, 90);
    root = create(root, 110);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    root = delete(root, 80);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
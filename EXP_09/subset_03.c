#include <stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree* include,*exclude;
}root;

struct tree*insert(int data){
    struct tree*temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=data;
    temp->include=temp->exclude=NULL;
    return temp;
}


struct tree*create(struct tree* root,int data,int limit){
    int pre=0;
    if(root==NULL){
    root=insert(data);
    return root;
    }
    pre=root->data;
     //subset sum logic
    if(pre+data<=limit){
    root->include=create(root->include,data+pre,limit);}
    root->exclude=create(root->exclude,pre,limit);

}
void in(struct tree*root){
        if(root==NULL)return;
        in(root->include);
        printf("%d->",root->data);
        in(root->exclude);
    }

int main(){
    int size;
    printf("ENTER the no. of subset:\n");
    scanf("%d",&size);
    int limit;
    printf("ENTER the limit of sum:\n");
    scanf("%d",&limit);


    int subset[size];
    for(int i =0;i<size;i++){
        printf("ENTer subset %d:",i+1);
        scanf("%d",&subset[i]);
    } 

    struct tree*root=insert(0);

    for(int i =0;i<size;i++){
        create(root,subset[i],limit);
    }

    in(root);
}
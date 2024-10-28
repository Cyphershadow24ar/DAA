#include<stdio.h>
#include<stdlib.h>
struct node{
    int sum;
    int index;
    struct node *include;
    struct node *exclude;
};
struct node* createNode(int sum ,int index){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->sum=sum;
    temp->index=index;
    temp->include=NULL;
    temp->exclude=NULL;
    return temp;
} 
void tree(struct node* node,int arr[],int n,int target,int subset[],int subsize){
    subset[subsize]=arr[node->index];
    node->include=createNode(node->sum+arr[node->index],node->index+1);
    tree(node,arr,n,target,subset,subsize+1);
    node->exclude=createNode(node->sum,node->index+1);
    tree(node,arr,n,target,subset,subsize);
    if(node=NULL){
        return;
    }
    if(node->index==n){
        if(node->sum==target){
            printf("{");
            for(int i =0;i<n;i++){
                printf("%d ",subset[i]);
            }
            printf("}\n");
        }
        return;
    }
}
int main(){
    struct node * root= createNode(0,0);
    int arr[4]={10,30,40,50};
    int target= 80;
    int n=sizeof(arr)/sizeof(arr[0]);
    int subset[n];
    int subsize=0;
    tree(root,arr,n,target,subset,subsize);


printf("\n");
    return 0;

    
}
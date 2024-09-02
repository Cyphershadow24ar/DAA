#include<stdio.h>

int main()
{
    int n=4;
    int arr[10][10];
    int i,j;
    printf("Enter the values of element:");
    
    //First ROW
    for(i=0;i<n;i++){
        for(j=0; j<n; j++){
            if(i==j){  //for diagonal element
                scanf("%d",&arr[i][j]);
            }
            else{   //for non diagonal element
                arr[i][j]=0;
            }
        }
    }

    //Second row
    for(i=0;i<n;i++){
        for(j=0; j<n; j++){
            if(i==j){
                int Sum = arr[i][j] + arr[i+1][j+1]; //addition 
                arr[i][j+1]= Sum;
            }
        }
    }

    //THird ROw
    for(i=0;i<n;i++){
        for(j=0; j<n; j++){
            if(i==j-1){
                int Sum1 = arr[i][j] + arr[i+1][j+1]; //addition
                arr[i][j+1]= Sum1;
            }
        }
    }

    //fourth row
    for(i=0;i<n;i++){
        for(j=0; j<n; j++){
            if(i==j-2){
                int Sum02 = arr[i][j] + arr[i+1][j+1]; //addition
                arr[i][j+1]= Sum02;
            }
        }
    }

    printf("Display the matrix: \n");
    for(i=0;i<n;i++){
        for(j=0; j<n; j++){
            printf("%d\t ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}


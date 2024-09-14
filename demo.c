#include<stdio.h>
int costCalculating(int c[4][4],int dim[5],int i, int j,int k)
{
    int cost;
    cost = c[i][k] + c[k+1][j] + (dim[i] * dim[k+1] * dim[j+1]);
}
void print_parenthesis(int i, int j, int cost, int k[cost][cost]) {
    if (i == j) {
        printf("M%d", i);
        return;
    }
    printf("(");
    print_parenthesis(i, k[i][j], cost, k);
    print_parenthesis(k[i][j] + 1, j, cost, k);
    printf(")");
}

int main()
{
    int d[5] = {2,3,3,4,2};
    int cost[4][4] = {0};
    int k1[4][4] = {0};

    for(int i = 3; i>=0; i--)
    {
        for(int j = 0; j<4; j++)
        {
            if(i<j)
            {
                int k = i;
                while(k<j)
                {
                    int temp = costCalculating(&cost[0],&d[0],i,j,k);
                    if(cost[i][j]==0)
                    {
                        cost[i][j] = temp;
                        k1[i][j] = k+1;
                        k++;
                    }
                    else
                    {
                        if(cost[i][j]>temp)
                        {
                            cost[i][j] = temp;
                            k1[i][j] = k+1;
                        }
                        k++;
                    } 
                }
                
            }
        }
    }
    printf("Cost of Matrix \n");
        for(int i = 0; i<4; i++)
        {
            for(int j = 0; j<4; j++)
            {
                printf("%d\t",cost[i][j]);
            }
            printf("\n");
        }
        printf("k matrix \n");
        for(int i = 0; i<4; i++)
        {
            for(int j = 0; j<4; j++)
            {
                printf("%d\t",k1[i][j]);
            }
            printf("\n");
        }

    printf("\nOptimal Parenthesis: ");
    print_parenthesis(0, 3, 4, k1);
    printf("\n");

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main()
{
	int i,j,n,dis,temp,row,k,min,col,p;
	char s,d;
	
	printf("Enter the no. of vertices : ");
	scanf("%d",&n);
	
	char vertex[6]={'a','b','c','d','e','f'};
	int graph[6][6]={{0,3,2,5,0,0,},{3,0,0,1,4,0},{2,0,0,2,0,1},{5,1,2,0,3,0,},{0,4,0,3,0,2},{0,0,1,0,2,0,}};
	int dij[n][n];
	int visited[n];
	char path[n];
	
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			dij[i][j]=INT_MAX;
		}
	}
	
	printf("Enter the source : ");
	scanf(" %c",&s);
	
	for(i=0;i<n;i++)
	{
		if(s==vertex[i])
			col=i;
	}
	dij[0][col]=0;
	
	//DIJ CALCULATION
	for(i=0;i<n-1;i++)
	{
		
		min=INT_MAX;
		for(k=0;k<n;k++)
		{
			if(dij[i][k]<min)
			{
				min=dij[i][k];
				row=k;	
			}
		}
		visited[row]=1;
		for(j=0;j<n;j++)
		{
			if(visited[j]==0)
			{
				if(graph[row][j]!=0)
				{
					
					temp=graph[row][j]+min;
					if (temp<dij[i][j])
						dij[i+1][j]=temp;
					else
						dij[i+1][j]=dij[i][j];
					
				}
				else
					dij[i+1][j]=dij[i][j];
				
			}
			
		}
		
    }
	printf("\nGRAPH MATRIX:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	printf("\nDIJ MATRIX:\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(dij[i][j]==INT_MAX)
				printf("INF\t");
			else
				printf("%d\t",dij[i][j]);			
		}
		printf("\n");
	}
	printf("Enter destination :");
	scanf(" %c",&d);
	for(i=0;i<n;i++)
	{
		if(d==vertex[i])
			k=i;
		
	}
	path[0]=d;
	p=1;
	
	for(i=n-1;i>0;i--)
	{
		if(dij[i][k]!=dij[i-1][k] && dij[i][k]!=INT_MAX)
		{
			min=INT_MAX;
			for(j=0;j<n;j++)
			{
				if(dij[i-1][j]<min)
				{				
					min=dij[i-1][j];
					k=j;			
				}
			}
			path[p]=vertex[k];
			p++;
		}
	}
	for(i=p-1;i>=0;i--)
	{
		if(i==0)
			printf("%c",path[i]);
		else
			printf("%c->",path[i]);
	}
	return 0;	
}
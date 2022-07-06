#include<stdio.h>
int i,j,k,a,b,v,u,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
void main()
{
    printf("\nEnter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix::\n");
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    printf("\nThe edges of spanning treeare:\n\n");
    while(ne<n)
    {
        for (i=1,min=999;i<=n;i++)
            for (j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i; b=v=j;
                }
            }
            while(parent[u])
                u=parent[u];
            while(parent[v])
                v=parent[v];
            if(u!=v)
            {
                printf("\n%d\tEdge(%d,%d)=%d",ne++,a,b,min);
                mincost+=min;
                parent[v]=u;
            }
            cost[a][b]=cost[b][a]=999;
    }
    printf("\n\tMINCOST=%d\n",mincost);
}
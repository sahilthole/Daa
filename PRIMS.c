#include<stdio.h>
int i, j, a, b, v, u,n, ne=1;
int min,mincost=0, cost[9][9], visited[9];
void main()
{
    printf( "The no of vertices=\t");
    scanf("%d",&n);
    printf("Enter the adjacency matrix=\t");
    for( i=1;i<=n;i++)
        for( j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
    printf("The edges of spanning tree are \t");
    visited[1]=1;
    while(ne<n)
    {
        for(i=1,min=999;i<=n; i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]==0)
                        continue;
                    else
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[v]==0)
        {
            printf("\n%d\t Edge \t(%d, %d)=%d\n",ne++, a, b, min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\n\tMINCOST=%d\n",mincost);
}
#include <stdio.h>
#include <time.h>
double tc;
time_t start, end;
int min(int, int);

void floyds(int p[10][10], int n)
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(i==j)
                    p[i][j] = 0;
                else 
                    p[i][j] = min(p[i][j], p[i][k]+p[k][j]);

}
int min(int a, int b)
{
    if(a<b) return a;
    else return b;
}

void main()
{
    int p[10][10], n, e, u, v,w, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edge: ");
    scanf("%d", &e);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            p[i][j] = 999;
    for(int i=1; i<=e; i++)
    {
        printf("\nEnter the end vertices of edge %d weight\n", i);
        scanf("%d%d%d",&u,&v,&w);
        p[u][v]=w;
    }
   printf("\n Matrix of input data:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
printf("%d\t",p[i][j]);
printf("\n");
}
start=clock();
floyds(p,n);
end=clock();
printf("\n Transitive closure:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
printf("%d\t",p[i][j]);
printf("\n");
}

    printf("\nShortest path:\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i!=j)
                printf("\n<%d,%d> = %d", i, j, p[i][j]);
        }
    }
    tc = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime taken: %f", tc);
}
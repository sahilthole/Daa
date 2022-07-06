#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
const int max=20;
clock_t start, end, total;
int place(int x[],int k)
{
    int i;
    for(i=0;i<k;i++)
        if (x[i]==x[k] || abs(x[i]-x[k])==abs(i-k))
            return 0;
    return 1;
}
void display(int x[], int n)
{
    char chessb[max][max];
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            chessb[i][j]='x';
    for(i=0;i<n;i++)
        chessb[i][x[i]]='q';
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%c", chessb[i][j]);
        printf ("\n");
    }
    printf ("\n");
}
void nqueens(int n) {
    int x[max];
    int k;
    x[0]=-1;
    k=0;
    while(k>=0) 
    {
        x[k]=x[k]+1;
        while(x[k]<n && !place(x,k))
            x[k]=x[k]+1;
        if(x[k]<n)
            if (k==n-1)
                display(x,n);
        else 
        {
            k++; x[k]=-1;
        }
        else 
            k--;
    }
}
void main() {
int n;
printf("enter the no of queens\n");
scanf("%d", &n);
printf("the soln to %d queens problem is\n", n);
start=clock();
nqueens(n);
end=clock();
total = (end-start)/CLOCKS_PER_SEC;
printf("\ntime taken=%f\n",total);
}

/* ALGORITHM 
PLACE(k,i)
{
    for j <- 1 to k <-1
    do if(x[j] =1 ) or (abs x[j]-1) = (Abs(j-k))
    then return False;
    return Ture
}
N-Queens(k,n)
{
    for i <- 1 to n
    do if place(k,i) then
    {
        x[k] <- i;
        if(k==n) then
        writes(x[1...n]);
        else
        N-queens (k+1, n);
    }
}
*/
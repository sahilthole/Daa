#include<stdio.h> 
#include<time.h>
#define MAX 50
void mergeSort(int arr[],int low,int mid,int high); 
void partition(int arr[],int low,int high);
double tc;
time_t start,end;
void main()
{
	int a[MAX],i,n;
	printf("Enter the total number of elements: "); 
	scanf("%d",&n);
	printf("Enter the elements to be sorted:\n\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element:",i+1);
		scanf("%d",&a[i]);
		printf("\n");
	}
            start=clock();
	partition(a,0,n-1);
            end=clock();
	printf("After merge sorting elements are: "); 
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
            tc=difftime(end,start)/CLOCKS_PER_SEC;
	printf("time efficiency is %lf",tc);
}
void partition(int arr[],int low,int high)
{
	int mid; 
	if(low<high)
	{
		mid=(low+high)/2; 
		partition(arr,low,mid); 
		partition(arr,mid+1,high); 
		mergeSort(arr,low,mid,high);
	}
}
void mergeSort(int arr[],int low,int mid,int high)
{ 
	int i,m,k,l,temp[MAX];
	l=low; i=low; m=mid+1;
        while((l<=mid)&&(m<=high))
        { 
		if(arr[l]<=arr[m])
                {
			temp[i]=arr[l]; 
			l++;
		}
		else
		{
			temp[i]=arr[m]; 
			m++;
		}
			i++;
	}

        while(l<=mid)
        {
           temp[i]=arr[l];
           i++;
           l++;
        }
        while(m<=high)
        {
           temp[i]=arr[m];
           i++;
           m++;
        }

	for(k=low;k<=high;k++)
	{ 
		arr[k]=temp[k];
	}
}
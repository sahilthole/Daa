#include <math.h>
#include <stdio.h>
#include<time.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[20],n,i;
    clock_t  start, end, total;
    printf("enter array size<20\n");
    scanf("%d",&n);
    printf("enter array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    start = clock();
    insertionSort(arr, n);
    end = clock();
    total = (end-start)/CLOCKS_PER_SEC;
    printf("array after sorting is\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("time taken=%f",total);
    return 0;
}
#include<stdio.h>
#include"header.h"
int main()
{
    int arr[]={50,40,30,20,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
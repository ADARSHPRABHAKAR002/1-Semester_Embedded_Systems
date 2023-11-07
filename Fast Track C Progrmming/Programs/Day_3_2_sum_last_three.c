#include<stdio.h>
int main()
{
    int a=0,b=0,c=1;
    int n,sum=0;
    scanf("%d",&n);
    printf("0 0 1 ");
    for(int i=0;i<n;i++)
    {
        sum=a+b+c;
        a=b;
        b=c;
        c=sum;
        printf("%d ",sum);
        
    }
    
}
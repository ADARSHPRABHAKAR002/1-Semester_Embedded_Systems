#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        for(int j=i;j>0;j--)
        {
            printf("1");
        }
        printf("\t");
    }
}
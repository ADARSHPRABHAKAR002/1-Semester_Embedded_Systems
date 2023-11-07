#include<stdio.h>
int main()
{
    int num,sum=0,rem;
    scanf("%d",&num);

    while(num!=0)
    {
        rem=num%10;
        sum=sum+rem;
        num/=10;
        //printf("%d",num);

    } 
    printf("%d",sum);
}
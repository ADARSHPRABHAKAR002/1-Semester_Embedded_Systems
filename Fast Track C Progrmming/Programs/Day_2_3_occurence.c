#include<stdio.h>
int main()
{
    int num,sum=0,rem,occ;
    scanf("%d",&num);
    scanf("%d",&occ);

    while(num!=0)
    {
        rem=num%10;
        if(rem==occ)sum++;
        num/=10;
    } 
    printf("%d",sum);
}
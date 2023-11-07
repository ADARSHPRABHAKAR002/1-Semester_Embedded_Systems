#include<stdio.h>
int main()
{
    int num,cub=0,rem,temp;
    scanf("%d",&num);
    temp=num;

    while(num!=0)
    {
        rem=num%10;
        cub=cub+(rem*rem*rem);
        num/=10;
    }
    if(temp==cub)printf("armstrong number");
    else printf("not an armstrong number");
    printf("%d",cub);
}
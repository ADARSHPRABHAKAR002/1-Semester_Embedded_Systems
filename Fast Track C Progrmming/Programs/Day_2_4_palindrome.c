#include<stdio.h>

int main()
{
    int num,sum=0,rem,temp;
    scanf("%d",&num);
    temp=num;

    while(num!=0)
    {
        rem=num%10;
        sum=sum*10+rem;
        num/=10;
        //printf("%d",num);

    } 
    if(temp==sum)printf("palindrome");
    else printf("not a plindrome");
    printf("%d",sum);
}
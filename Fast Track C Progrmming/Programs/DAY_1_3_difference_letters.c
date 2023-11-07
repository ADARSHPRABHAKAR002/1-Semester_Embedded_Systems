#include<stdio.h>
#include <stdlib.h>
int main()
{
    char a,b;
    printf("enter two numbers: ");
    scanf("%c %c",&a,&b);
    printf("%d",abs(a-b)-1);
}
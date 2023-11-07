#include<stdio.h>
#include<math.h>
int main()
{
    float p;
    long double a = M_PI;
    scanf("%f",&p);
    float b=(float)a;
    printf("%0.2f",(b*p*p));
}
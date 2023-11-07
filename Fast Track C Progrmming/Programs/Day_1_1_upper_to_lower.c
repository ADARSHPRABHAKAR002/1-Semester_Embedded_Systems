#include<stdio.h>
int main()
{
    char name[50];
    printf("enter the your name: ");
    scanf("%[^\n]%c",name);
    //  ascii for numbers
    //  48 -0
    //  57 -9
    //  ascii for capital latter
    //  65 -A
    //  90 -Z
    //  ascii for small letter
    //  97 -a
    //  122 -z
    // difference between captial to small is 32
    for(int i=0;name[i]!='\0';i++)
    {
        if('A'<=name[i] && name[i]<='Z')
        {
            
            name[i]=name[i]+32;
        }
        
    }
    printf("%s",name);
}
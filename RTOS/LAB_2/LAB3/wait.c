#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int id;
id=fork();
if(id<0)
exit(-1);
if(id==0)
{
sleep(8);
printf("I am the child");
}
if(id>0)
{
printf("I am the parent");
int status;
wait(&status);
}
return 0;
}

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
int r=0;
r=fork();  //creating systems process
if(r>0)
{
printf("perent ID:%d",getpid());
}
else if(r==0)
{
printf("child ID:%d",getpid());
printf("perent ID:%d",getppid());
}
return 0;
}


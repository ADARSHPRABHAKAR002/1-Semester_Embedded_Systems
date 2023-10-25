#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{


int id;
int counter=0;
int status;

id=fork();

if(id<0)
{
printf("Fork error\n");
exit(EXIT_FAILURE);
}
if(id==0)
{
printf("I am the child, processor ID:%d\n",getpid());
printf("I am the child fetching parent ID, processor ID:%d\n",getppid());

for(int i=0;i<999;i++)
{
counter++;
}
exit(255);
}
if(id>0)
{

printf("I am the perent, processor ID:%d\n",getpid());
printf("I am the parent fetching child ID, processor ID:%d\n",getppid());
waitpid(id,&status,0);
printf("Child process is completed with ID:%d and exit value:%d\n",getppid(),WEXITSTATUS(status));
}
return 0;
}

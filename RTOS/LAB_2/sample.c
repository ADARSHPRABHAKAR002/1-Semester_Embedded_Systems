/*Write a program which creates a thread. The main thread should 
publish its pid. Let the thread publish its thread id. Next the 
thread computes the sum of first twenty five numbers and outputs the 
result to the screen. {Use pthread_join() in the main, so that it 
waits for the thread to finish its execution.} 
Modify the above code such that the upper limit of the summation is 
read from the user and is passed as a parameter to the thread.*/



#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct ThreadData {
    int upperLimit;
};
void *f1(void *);
void *f2(void *);
void *computeSum(void *param) {
    struct ThreadData *data = (struct ThreadData *)param;
    int sum = 0;
    for (int i = 1; i <= data->upperLimit; ++i) {
        sum += i;
    }
    printf("Thread ID: %ld\n", pthread_self());
    printf("Sum of first %d numbers: %d\n", data->upperLimit, sum);
    pthread_exit(NULL);
}

int main() {
    pthread_t t1,t2;
    struct ThreadData data;
    long int var = 0;
    // Get PID of the main thread (parent process)
    printf("Process ID (PID): %d\n", getpid());

    // Ask the user to enter the upper limit for summation
    printf("Enter the upper limit for summation: ");
    scanf("%d", &data.upperLimit);

    // Create a thread and pass the upper limit as a parameter
    //if (pthread_create(&thread, NULL, computeSum, (void *)&data) != 0) {
    //   perror("pthread_create");
    //    return -1;
    //}

    // Wait for the thread to finish its execution using pthread_join
    pthread_create(&t1, NULL, f1, NULL);
    pthread_create(&t2, NULL, f2, NULL);
    //
    printf("hello dude\n");
    pthread_join(t1,NULL);
    while(1)
    {
       if(var >=130000000)
	{
          var = 0;
          printf("main thread \n");
	}
      else
         var++;
    }
    return 0;
}

void *f1(void *variable)
{
    long int var = 0;
    while(1)
    {
       if(var >=130000000)
	{
          var = 0;
          printf("t1 thread \n");
          return NULL;
	}
      else
         var++;
    }
   return NULL;

}

void *f2(void *variable)
{
   long int var = 0;
    while(1)
    {
       if(var >=130000000)
	{
          var = 0;
          printf("t2 thread \n");
	}
      else
         var++;
    }
   return NULL;
}



/*Write a program which creates two threads. Let the main thread 
display a message, "Hello, main thread here!". Also the main thread 
reads 2 integers n1 and n2 (which can range between 1 to 9) from the 
user. Main should pass n1 to thread1, and n2 to thread2. Thread1 then
displays "Hello, thread1 here!" n1 times. Thread2 displays 
"Hello,thread2 here!" n2 times. */



#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *param) {
    int n = *((int *)param);
    for (int i = 0; i < n; ++i) {
        if (pthread_self() == pthreads[0]) {
            printf("Hello, thread1 here!\n");
        } else {
            printf("Hello, thread2 here!\n");
        }
    }
    pthread_exit(NULL);
}

pthread_t pthreads[2];

int main() {
    int n1, n2;

    // Display a message from the main thread
    printf("Hello, main thread here!\n");

    // Read integers n1 and n2 from the user
    printf("Enter n1 (1 to 9): ");
    scanf("%d", &n1);

    printf("Enter n2 (1 to 9): ");
    scanf("%d", &n2);

    // Create threads and pass n1 to Thread1 and n2 to Thread2
    pthread_create(&pthreads[0], NULL, threadFunction, (void *)&n1);
    pthread_create(&pthreads[1], NULL, threadFunction, (void *)&n2);

    // Wait for threads to finish using pthread_join
    pthread_join(pthreads[0], NULL);
    pthread_join(pthreads[1], NULL);

    return 0;
}


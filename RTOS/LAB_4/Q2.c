/*Write a program which creates 3 threads. 
case (i) Let the main thread input the value of n from the user. 
{Hint:- You can store n in a global variable so that it is available 
to all threads of the process} Each thread reads a message from the 
user and displays the message n times. 
case (ii) Modify your program such that the value of n is given by 
the user and is passed as a parameter to the threads. 
*/


#include <stdio.h>
#include <pthread.h>

struct ThreadData {
    int n;
    char message[100];
};

void *printMessage(void *param) {
    struct ThreadData *data = (struct ThreadData *)param;
    for (int i = 0; i < data->n; ++i) {
        printf("%s\n", data->message);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    struct ThreadData data[3];

    // Ask the user to enter the value of n
    printf("Enter the value of n: ");
    scanf("%d", &(data[0].n)); // Assuming n is the same for all threads

    // Ask the user to input messages for each thread
    for (int i = 0; i < 3; ++i) {
        printf("Enter message for thread %d: ", i + 1);
        scanf(" %[^\n]s", data[i].message);
        data[i].n = data[0].n;
    }

    // Create threads and pass messages and n as parameters
    for (int i = 0; i < 3; ++i) {
        pthread_create(&threads[i], NULL, printMessage, (void *)&data[i]);
    }

    // Wait for threads to finish using pthread_join
    for (int i = 0; i < 3; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}


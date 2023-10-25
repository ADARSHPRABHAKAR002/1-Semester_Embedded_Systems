/*Write a program which defines a global integer array. Let the main 
read the length of the array and populate it. Next it creates 2 
threads. Let the main pass the array length to the 2 threads. One 
thread computes the sum of array elements and outputs the result. The
second thread publishes all odd numbers present in the array. {Use 
pthread_join() in the main, so that it waits for the threads to 
finish their execution.} 
Suppose the array is defined in main, and the main has to pass both 
the array as well as the array length to the threads, how will your 
program change?*/

#include <stdio.h>
#include <pthread.h>

struct ThreadData {
    int *array;
    int length;
};

void *computeSum(void *param) {
    struct ThreadData *data = (struct ThreadData *)param;
    int sum = 0;
    for (int i = 0; i < data->length; ++i) {
        sum += data->array[i];
    }
    printf("Sum of array elements: %d\n", sum);
    pthread_exit(NULL);
}

void *findOddNumbers(void *param) {
    struct ThreadData *data = (struct ThreadData *)param;
    printf("Odd numbers in the array: ");
    for (int i = 0; i < data->length; ++i) {
        if (data->array[i] % 2 != 0) {
            printf("%d ", data->array[i]);
        }
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    int length;

    // Read the length of the array from the user
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    // Allocate memory for the array
    int *array = (int *)malloc(length * sizeof(int));

    // Populate the array
    printf("Enter %d elements for the array:\n", length);
    for (int i = 0; i < length; ++i) {
        scanf("%d", &array[i]);
    }

    // Create a structure to hold array and its length
    struct ThreadData data;
    data.array = array;
    data.length = length;

    // Create threads and pass array and its length to them
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, computeSum, (void *)&data);
    pthread_create(&thread2, NULL, findOddNumbers, (void *)&data);

    // Wait for threads to finish using pthread_join
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Free the allocated memory for the array
    free(array);

    return 0;
}


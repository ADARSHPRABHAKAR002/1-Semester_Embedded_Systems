/*Define a global integer matrix of size 3 * 4. Let the main thread 
populate the matrix with integers from the user. Create 4 threads. 
Each thread computes the column sum of a particular column. The main
waits for the threads to complete their execution. Finally the main 
computes the total sum of integers from the partial results given out
by the threads, and outputs the sum to the screen. 
How will your program change if there are 3 threads, each computing 
the sum of a particulr row, and finally the main thread computes the
total sum?
*/


#include <stdio.h>
#include <pthread.h>

int matrix[3][4]; // Global 3x4 matrix

void *computeColumnSum(void *param) {
    int col = *((int *)param);
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += matrix[i][col];
    }
    pthread_exit((void *)sum);
}

int main() {
    pthread_t threads[4];
    int columnSums[4];

    // Populate the matrix with integers from the user
    printf("Enter 3x4 matrix elements:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Create threads to compute column sums
    for (int i = 0; i < 4; ++i) {
        pthread_create(&threads[i], NULL, computeColumnSum, (void *)&i);
    }

    // Wait for threads to finish using pthread_join and compute total sum
    int totalSum = 0;
    for (int i = 0; i < 4; ++i) {
        pthread_join(threads[i], (void **)&columnSums[i]);
        totalSum += columnSums[i];
        printf("Sum of column %d: %d\n", i + 1, columnSums[i]);
    }

    // Output total sum
    printf("Total sum of matrix elements: %d\n", totalSum);

    return 0;
}

